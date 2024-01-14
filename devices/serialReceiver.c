#include <xc.h>
#include "serialReceiver.h"
#include "../peripherals/uart.h"
#include "../peripherals/dma.h"
#include "../watchDogTimer.h"
#include "../utilities/delay.h"

#define RX_BYTES_PER_PACKET 16
#define RX_NUM_SERVO_FIELDS 7
#define RX_SYNC_TIME_IN_MS 5

#define RX_NUM_FADES_INDEX 0
#define RX_MODE_INDEX 1
#define RX_SERVO_FIELD_START_INDEX 2

void SychSRX();
void ReadSRXPacket();
void ProcessSRXPacket();
unsigned char GetChannelIDFromServoData(unsigned short servoData);
unsigned short GetServoPosFromServoData(unsigned short servoData);
void InitUARTPinRx(unsigned int urx);
void InitiateBind(char bindType);

static Uart srxUart;

static unsigned char srxPacket[RX_BYTES_PER_PACKET];
static unsigned short servoPositions[RX_NUM_CHANNELS];
static char currentRxMode;
static char numFades;

static bool watchDogEnabled;

static const unsigned char RxModes[NUM_DSM_MODES] = {DSM2_1024_22MS,
    DSM2_2048_11MS, DSMS_2048_22MS, DSMX_2048_11MS};

void InitSRX(unsigned int urx, bool watchDog, char bindType)
{
    watchDogEnabled = watchDog;
    
    if(bindType > 0) {
        InitiateBind(bindType);
    }
    
    InitUARTPinRx(urx);
    InitUART(SERIAL_RX_UART_BRG, SERIAL_RX_BUS, &srxUart);
    SychSRX();
    InitDMA(srxUart.UxRXREG, &srxPacket[0], RX_BYTES_PER_PACKET);
    
    if(watchDog)
    {
        InitWatchDogTimer();
    }
}
    
void InitiateBind(char bindType)
{
    //set pin as pulse output
    SERIAL_RX_TRIS_PIN = 0;
    //ensure pin is high (falling edges must match bind type)
    SERIAL_RX_LAT_PIN = 1;
    for(int pulseIndex = 0; pulseIndex < bindType; pulseIndex++)
    {
        Delay10Ms(1);
        SERIAL_RX_LAT_PIN = 0;
        Delay10Ms(1);
        SERIAL_RX_LAT_PIN = 1;
    }
}

void InitUARTPinRx(unsigned int urx) {
    if(SERIAL_RX_BUS == UART_1) {
        U1RXRbits.U1RXR = urx;
        SERIAL_RX_TRIS_PIN = 1;
    }
    else if(SERIAL_RX_BUS == UART_2) {
        U2RXRbits.U2RXR = urx;
        SERIAL_RX_TRIS_PIN = 1;
    }
}
    
unsigned short GetSRXChannelAt(char index)
{
    if(index != RX_THROTTLE)
    {
        return servoPositions[index] * 32.01514f;
    }
    else
    {
        return (servoPositions[RX_THROTTLE] - 205) * 40.0091575f;
    }
}

char GetCurrentSRXMode()
{
    return currentRxMode;
}

unsigned char GetNumSRXFades()
{
//    return srxPacket[RX_NUM_FADES_INDEX];
    return numFades;
}

void ResumeSRXWatchDog()
{
    ResumeWatchDogTimer();
}

void StopSRXWatchDog()
{
    StopWatchDogTimer();
}

//private

void ReadSRXPacket()
{ 
    for(int i = 0; i < RX_BYTES_PER_PACKET; i++)
    {
        srxPacket[i] = ReadUARTChar(&srxUart);
    }
}

void ProcessSRXPacket()
{
    numFades = srxPacket[RX_NUM_FADES_INDEX];
    currentRxMode = srxPacket[RX_MODE_INDEX];
    
    unsigned short servoData;
    for(int i = 0; i < RX_NUM_SERVO_FIELDS; i++)
    {
        servoData = srxPacket[(i * 2) + RX_SERVO_FIELD_START_INDEX] << 8 |
                srxPacket[(i * 2) + RX_SERVO_FIELD_START_INDEX + 1];
        servoPositions[GetChannelIDFromServoData(servoData)] =
                GetServoPosFromServoData(servoData);
    }
}

void SychSRX()
{
    unsigned char prevVal = ReadUARTChar(&srxUart);
    unsigned char val = ReadUARTChar(&srxUart);
    while(true)
    {
        bool rxModeMatchesVal = false;
        for(int i = 0; i < NUM_DSM_MODES; i ++)
        {
            if(val == RxModes[i])
            {
                rxModeMatchesVal = true;
                break;
            }
        }
        
        if(rxModeMatchesVal && prevVal == 0)
        {
            break;
        }
        
        prevVal = val;
        val = ReadUARTChar(&srxUart);
    }
    
    numFades = prevVal;
    currentRxMode = val;
    
    for(int i = 0; i < RX_NUM_SERVO_FIELDS; i++)
    {
        ReadUART16(&srxUart);
    }
}

unsigned char GetChannelIDFromServoData(unsigned short servoData)
{
    return (servoData & 0x7800) >> 11;
}

unsigned short GetServoPosFromServoData(unsigned short servoData)
{
    return servoData & 0x07FF;
}

void __attribute__( (interrupt(IPL5SOFT), vector(_DMA0_VECTOR))) 
    DMA0Handler()
{ 
    ProcessSRXPacket();
    
    if(watchDogEnabled)
    {
        ResetWatchDogTimer();
    }
    
    //clear DMA interrupt flags
    DCH0INTCLR = 0xFF;
    IFS1bits.DMA0IF = 0;
}