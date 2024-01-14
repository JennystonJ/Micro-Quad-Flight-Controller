#include <xc.h>
#include "config.h"
#include "peripherals/adc.h"
#include "devices/statusLED.h"
#include "peripherals/motor.h"
#include "peripherals/i2c.h"
#include "utilities/delay.h"
#include "devices/mpu9250.h"
#include "devices/serialReceiver.h"
#include "pid.h"
#include "pidVar.h"
#include "flightMode.h"
#include "filters.h"
#include "utilities/commandUI.h"
#include "utilities/conversion.h"
#include "peripherals/timers/timer1.h"
#include "peripherals/vbatt.h"
#include "devices/24fc512.h"
#include "eeprom.h"
#include "watchDogTimer.h"

void Idle();
void InitIO();
void InitInterrupts();
void InitTimer();
bool IsPIDSaved();
void LoadSavedPID();
void InitSavedPID();

#define PITCH 0
#define ROLL 1
#define YAW 2
#define NUM_AXES 3

#define THROTTLE_MIN 10000
#define RX_THROTTLE_SCALE 0.75

#define MOTOR_OUTPUT_SCALE 0.8

#define FAIL_SAFE_NUM_FADES 20

#define VBATT_WARNING_THRESHOLD 3.8f

#define SWITCH_1 PORTBbits.RB12

//member variables
static int motorOutput[NUM_MOTORS];

//for use with angle mode
static float currentAngleX = 0;
static float currentAngleY = 0;

//for use with rate mode
static float currentRateX = 0;
static float currentRateY = 0;

static float currentRateZ = 0;

//debug use
static bool outputLoopData = true;
static float bufferedAngleX = 0;
static bool dataRead = true;

void __attribute__( (interrupt(IPL5SOFT), vector(_TIMER_1_VECTOR))) 
    Timer1Handler()
{
    //clear timer1 interrupt flag
    IFS0bits.T1IF = 0;
    
//    SetBlueStatusLED(false);
//    PORTBbits.RB15 = 1;
    
//    if(GetSRXChannelAt(RX_GEAR) < 20000) {
//        __pic32_software_reset();
//    }
    
    if(GetSRXChannelAt(RX_THROTTLE) < THROTTLE_MIN)
    {
        //shut off motors
        for(int i = 0; i < NUM_MOTORS; i++)
        {
            SetMotorPower(0, i);
        }
        
        
        //reset integrals
        for(int i = 0; i < NUM_PID; i++)
        {
            ResetPIDVarIntegral(i);
        }
        
        if(GetSRXChannelAt(RX_GEAR) < 32768)
        {
            SetStatusLEDDisarmed();
            StopSRXWatchDog();
            int uiStatus = StartCommandUI();
            if(uiStatus == COMMAND_UI_CHANGE)
            {
                InitSavedPID();
            }
            ResumeSRXWatchDog();
            SetStatusLEDArmed();
        }
    }
    else
    {
        
        currentRateX = GetGyroX();
        currentRateY = GetGyroY();
        currentRateZ = GetGyroZ();
        
        int throttleRx = (int)(GetSRXChannelAt(RX_THROTTLE) *
            RX_THROTTLE_SCALE);
        int elevatorRx = GetSRXChannelAt(RX_ELEVATOR);
        int aileronRx = GetSRXChannelAt(RX_AILERON);
        int rudderRx = GetSRXChannelAt(RX_RUDDER);
        
        int pitchOut, rollOut, yawOut;
        float cyclicSetPoints[NUM_AXES-1];
        if(GetFlightMode() == ANGLE_MODE)        
        {
            currentAngleX = ComputeComplementaryAngle(currentAngleX,
                    currentRateX, GetAccelAngleX(), DT);
            currentAngleY = ComputeComplementaryAngle(currentAngleY,
                    currentRateY, GetAccelAngleY(), DT);
            
            if(outputLoopData)
            {
                if(dataRead)
                {
                    bufferedAngleX = currentAngleX;
                    dataRead = false;
                }
            }
            
            
            cyclicSetPoints[PITCH] = ComputePID(
                    ReceiverValueToDegrees(elevatorRx), currentAngleX,
                    GetPIDVarPtr(PITCH_ANGLE));
            cyclicSetPoints[ROLL] = ComputePID(
                    ReceiverValueToDegrees(aileronRx), currentAngleY,
                    GetPIDVarPtr(ROLL_ANGLE));

//            pitchOut = ComputePID(ReceiverValueToDegrees(elevatorRx),
//                    currentAngleX, GetPIDVarPtr(PITCH));
//            rollOut = ComputePID(ReceiverValueToDegrees(aileronRx),
//                    currentAngleY, GetPIDVarPtr(ROLL));
            
            pitchOut = ComputePID(cyclicSetPoints[PITCH],
                    currentRateX, GetPIDVarPtr(PITCH));
            rollOut = ComputePID(cyclicSetPoints[ROLL],
                    currentRateY, GetPIDVarPtr(ROLL));
            
            yawOut = ComputePID(ReceiverValueToDPS(rudderRx),
                    currentRateZ, GetPIDVarPtr(YAW));
        }
        else if(GetFlightMode() == RATE_MODE)
        {
            cyclicSetPoints[PITCH] = ReceiverValueToDPS(elevatorRx);
            cyclicSetPoints[ROLL] = ReceiverValueToDPS(aileronRx);
            
            pitchOut = ComputePID(cyclicSetPoints[PITCH], currentRateX,
                GetPIDVarPtr(PITCH));
            rollOut = ComputePID(cyclicSetPoints[ROLL], currentRateY,
                GetPIDVarPtr(ROLL));
        
            yawOut = ComputePID(ReceiverValueToDPS(rudderRx), currentRateZ,
                GetPIDVarPtr(YAW));
        }
        
        motorOutput[MOTOR_1] = throttleRx + pitchOut - rollOut - yawOut;
        motorOutput[MOTOR_2] = throttleRx + pitchOut + rollOut + yawOut;
        motorOutput[MOTOR_3] = throttleRx - pitchOut + rollOut - yawOut;
        motorOutput[MOTOR_4] = throttleRx - pitchOut - rollOut + yawOut;

        for(int i = 0; i < NUM_MOTORS; i++)
        {
            //scale down motor power
            motorOutput[i] = (int)(((double)motorOutput[i]) *
                MOTOR_OUTPUT_SCALE);
                
            //saturation filter
            if(motorOutput[i] > 65535)
            {
                motorOutput[i] = 65535;
            }
            else if(motorOutput[i] < 10 && throttleRx >= THROTTLE_MIN)
            {
                motorOutput[i] = 10;
            }
            else if(throttleRx < THROTTLE_MIN)
            {
                motorOutput[i] = 0;
            }

            SetMotorPower((unsigned short)motorOutput[i], i);
        }
        
//        }
//        else
//        {
//            for(int i = NUM_MOTORS - 1; i >= 0; i--)
//            {
//                //saturation filter
//                if(motorOutput[i] > 65535)
//                {
//                    motorOutput[i] = 65535;
//                }
//                else if(motorOutput[i] < 0)
//                {
//                    motorOutput[i] = 0;
//                }
//                //delay motor startup to prevent RX reset
////                Delay10Ms(10);
//                SetMotorPower((unsigned short)motorOutput[i], i);
//                //SetMotorPower((unsigned short)motorOutput[3], 3);
//            }
//        }
//        PORTBbits.RB15 = 0;
        if(GetVBatt() < VBATT_WARNING_THRESHOLD) {
            SetBlueStatusLED(true);
        }
        else {
            SetBlueStatusLED(false);
        }
    }
}

static int watchdogTriggeredCount = 0;
//RX watchdog timer interrupt vector
void __attribute__( (interrupt(IPL7SOFT), vector(_TIMER_4_VECTOR)))
    Timer4Handler()
{
    watchdogTriggeredCount++;
    
    if(watchdogTriggeredCount > 0)
    {
        SetBlueStatusLED(true);
    }
    
    if(watchdogTriggeredCount >= FAIL_SAFE_NUM_FADES)
    {
        //shut off motors
        for(int i = 0; i < NUM_MOTORS; i++)
        {
            SetMotorPower(0, i);
        }

        //indicate controller is disarmed
        SetStatusLEDWarning();

        //halt program execution
        for(;;)
        {
            
        }
    }
    else
    {
        ResetWatchDogTimer();
    }
}

int main()
{
    InitIO();
    InitADC();
    InitI2C();
    InitInterrupts();
    InitPIDVar();
    
    
    SetStatusLEDDisarmed();
    
    for(int i = 0; i < NUM_MOTORS; i++)
    {
        InitMotor(i);
    }
    
    if(IsPIDSaved())
    {
        LoadSavedPID();
    }
    else
    {
        InitSavedPID();
    }
    
    InitCommandUI();
    //start command interface if switch is in correct position at startup
    if(SWITCH_1 == 1)
    {
        int uiStatus = StartCommandUI();
        //change has been made
        if(uiStatus == COMMAND_UI_CHANGE)
        {
            InitSavedPID();
        }
    }
    
    //pause to allow receiver to start up
    Delay10Ms(5);
    
    //map SRX to RPB11
    unsigned int u2rx = 0b0011;
    InitSRX(u2rx, true, 0);
    InitMPU();
    
    //pause to allow controller to read data from receiver
    Delay10Ms(100);
    
    //prevent controller from being armed if throttle is over minimum position
    GetSRXChannelAt(RX_THROTTLE);
    while(GetSRXChannelAt(RX_THROTTLE) > THROTTLE_MIN)
    {
        //indicate throttle is over minimum position
        SetStatusLEDWarning();
    }
    SetStatusLEDDisarmed();
    
    //5 second delay
    Delay10Ms(500);
    
    CalibrateGyros();
    
    //indicate controller is armed
    SetStatusLEDArmed();
    
//    for(;;)
//    {
//        SetMotorPower(GetSRXChannelAt(RX_THROTTLE), MOTOR_1);
//        SetMotorPower(GetSRXChannelAt(RX_THROTTLE), MOTOR_2);
//        SetMotorPower(GetSRXChannelAt(RX_THROTTLE), MOTOR_3);
//        SetMotorPower(GetSRXChannelAt(RX_THROTTLE), MOTOR_4);
//    }
    
    SetFlightMode(ANGLE_MODE);
    InitTimer();
    
    //idle loop
    for(;;)
    {
        //SetBlueStatusLED(true);
        Idle();
//        if(outputLoopData)
//        {
//            if(!dataRead)
//            {
//                WriteUARTFloat32(bufferedAngleX, &pcBus);
//                dataRead = true;
//            }
//        }
    }
    
    //program should not reach here
    return 0;
}

void InitIO()
{
    //configure analog/digital pins
    ANSELA = 0x00;
    ANSELB = 0x00;
    ANSELC = 0x02;
    
    //ensure all output pins are switched off
    LATA = 0x00;
    LATB = 0x00;
    LATC = 0x00;
    
    //PWM pin setup
    static const int OC1 = 0b0101,
                    OC2 = 0b0101,
                    OC3 = 0b0101,
                    OC4 = 0b0101;
    RPB4Rbits.RPB4R = OC1;
    RPA9Rbits.RPA9R = OC2;
    RPC9Rbits.RPC9R = OC3;
    RPA2Rbits.RPA2R = OC4;
    
    //vBatt pin
    TRISCbits.TRISC2 = 1;
    
    //switch
    TRISBbits.TRISB12 = 1;
    
    //status LEDs
    //red LED
    TRISAbits.TRISA10 = 0;
    //green LED
    TRISAbits.TRISA7 = 0;
    //blue LED
    TRISBbits.TRISB14 = 0;
    //yellow LED
    TRISAbits.TRISA1= 0;
    
    //UART pin setup
    //map U1RX to RPB13
    U1RXRbits.U1RXR = 0b0011;
    TRISBbits.TRISB13 = 1;
    //map U1TX to RPB15
    RPB15Rbits.RPB15R = 0b0001;
    TRISBbits.TRISB15 = 0;
    //now handled by serialReceiver.c
//    //map U2RX to RPB11
//    U2RXRbits.U2RXR = 0b0011;
//    TRISBbits.TRISB11 = 1;
}

void Idle()
{
    //write invalid key to force lock
    SYSKEY = 0x0;
    //write key1
    SYSKEY = 0xAA996655;
    //write key2
    SYSKEY = 0x556699AA;
    //set the power-saving mode to idle
    OSCCONCLR = 0x10;
    //write invalid key to force lock
    SYSKEY = 0x0;
    //enter idle mode
    asm volatile ("wait");
}

void InitInterrupts()
{
    //enable multi-vectored interrupts
    INTCONbits.MVEC = 1;
    //enable global interrupts
    asm volatile ("EI");
}

void InitTimer()
{
    InitTimer1();
    
    SetTimer1InterruptPriority(5);
    SetTimer1Interrupt(true);

//    //400 Hz loop frequency
//    SetTimer1Period(18);
//    //1:64 pre-scaler
//    SetTimer1Prescaler(0b10);
   
    //100 Hz loop frequency
//    SetTimer1Period(1875*4);
    //1:64 pre-scaler
//    SetTimer1Prescaler(0b10);
    
    //400 Hz loop frequency
    SetTimer1Period(1875);
    //1:64 pre-scaler
    SetTimer1Prescaler(0b10);
    //1:8
    //1600 Hz loop frequency
//    SetTimer1Period(1875 * 2);
//    SetTimer1Prescaler(0b01);
    
    StartTimer1();
}

bool IsPIDSaved()
{
    if(ReadEEPROMByte(EEPROM_INIT_ADDR) == 0x01)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void LoadSavedPID()
{
    PIDVar pidVal;
    
    //iterate through all PID axes
    for(unsigned char axis = 0; axis < NUM_PID; axis++)
    {
        unsigned char addrOffset = EEPROM_PID_PITCH + sizeof(PIDVar) * axis;
        unsigned char *pidVarPtr = (unsigned char *)(&pidVal);
        ReadEEPROMData(addrOffset, (unsigned char *)pidVarPtr, sizeof(PIDVar));
//        for(unsigned char i = 0; i < sizeof(PIDVar); i++)
//        {
//            volatile unsigned char test = sizeof(PIDVar);
//            pidVarPtr++;
//            *pidVarPtr = ReadEEPROMByte(addrOffset + i);
//        }
        SetPIDVar(pidVal, axis);
    }
}

void InitSavedPID()
{
    //iterate through all PID axes
    for(unsigned char axis = 0; axis < NUM_PID; axis++)
    {
        PIDVar *pidVarPtr = GetPIDVarPtr(axis);
        unsigned char addrOffset = EEPROM_PID_PITCH + sizeof(PIDVar) * axis;
        WriteEEPROMData(addrOffset, (unsigned char *)pidVarPtr, sizeof(PIDVar));
    }
    
    //indicate EEPROM is initialized
    WriteEEPROMByte(EEPROM_INIT_ADDR, 1);
}
