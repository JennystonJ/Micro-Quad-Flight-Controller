#include "commandUI.h"
#include "../peripherals/uart.h"
#include "../devices/serialReceiver.h"
#include "../peripherals/vbatt.h"
#include "../flightMode.h"
#include <stdbool.h>
#include "../pidVar.h"
#include "../pid.h"

//constant definitions
#define VERIFY_CONNECTION 0x55
#define CONNECTION_READY (VERIFY_CONNECTION)

#define REQUEST_ACCEL_X 0
#define REQUEST_ACCEL_Y 1
#define REUEST_ACCEL_Z 2
#define REQUEST_GYRO_X 3
#define REQUEST_GYRO_Y 4
#define REQUEST_GYRO_Z 5
#define REQUEST_AA_X 6
#define REQUEST_AA_Y 7

#define REQUEST_RX_1 8
#define REQUEST_RX_2 9
#define REQUEST_RX_3 10
#define REQUEST_RX_4 11
#define REQUEST_RX_5 12

#define REQUEST_KP 13
#define REQUEST_KI 14
#define REQUEST_KD 15
#define REQUEST_SET_KP 16
#define REQUEST_SET_KI 17
#define REQUEST_SET_KD 18

#define REQUEST_CONV_GYRO_X 19
#define REQUEST_CONV_GYRO_Y 20
#define REQUEST_CONV_GYRO_Z 21

#define RUN_COMPLMENTARY_FILTER 22

#define REQUEST_FLIGHT_MODE 23
#define REQUEST_SET_FLIGHT_MODE 24

#define REQUEST_RX 25

#define REQUEST_VBATT 26

#define REQUEST_FADES 27

#define COMMAND_LAST 27

#define DISCONNECT 0xFF

void VerifyConnection();

void RequestAccelX();
void RequestAccelY();
void RequestAccelZ();
void RequestGyroX();
void RequestGyroY();
void RequestGyroZ();
void RequestAccelAngleX();
void RequestAccelAngleY();
void RequestRX1();
void RequestRX2();
void RequestRX3();
void RequestRX4();
void RequestRX5();
void RequestKP();
void RequestKI();
void RequestKD();
void RequestSetKP();
void RequestSetKI();
void RequestSetKD();
void RequestConvGyroX();
void RequestConvGyroY();
void RequestConvGyroZ();
void RunComplementaryFilter();
void RequestFlightMode();
void RequestSetFlightMode();
void RequestRX();
void RequestVBatt();
void RequestFades();

void (*request[])(void) = {&RequestAccelX, &RequestAccelY, &RequestAccelZ,
                            &RequestGyroX, &RequestGyroY, &RequestGyroZ,
                            &RequestAccelAngleX, &RequestAccelAngleY,
                            &RequestRX1, &RequestRX2, &RequestRX3,
                            &RequestRX4, &RequestRX5, &RequestKP, &RequestKI, &RequestKD,
                            &RequestSetKP, &RequestSetKI, &RequestSetKD,
                            &RequestConvGyroX, &RequestConvGyroY,
                            &RequestConvGyroZ, &RunComplementaryFilter,
                            &RequestFlightMode, &RequestSetFlightMode,
                            &RequestRX, &RequestVBatt, &RequestFades};


static int status;

void InitCommandUI()
{
    InitUART(PC_BUS_BRG_VAL, PC_BUS, &pcBus);
}

static unsigned int command;
int StartCommandUI()
{    
    status = COMMAND_UI_NO_CHANGE;
    do
    {
        command = (unsigned int)(ReadUARTChar(&pcBus));
        if(command <= COMMAND_LAST)
        {
            request[command]();
        }
        else if (command == VERIFY_CONNECTION)
        {
            VerifyConnection();
        }
        else if(command == DISCONNECT)
        {
            return status;
        }
        else
        {
            //invalid command
        }
    }
    while(true);
}

void VerifyConnection()
{
    //echo connection ready
    WriteUARTData(CONNECTION_READY, &pcBus);
}

void RequestAccelX()
{
//    short data = GetRawAccelX();
//    WriteUARTData(data >> 8);
//    WriteUARTData(data & 0xFF);
}

void RequestAccelY()
{
//    short data = GetRawAccelY();
//    WriteUARTData(data >> 8);
//    WriteUARTData(data & 0xFF);
}

void RequestAccelZ()
{
//    short data = GetRawAccelZ();
//    WriteUARTData(data >> 8);
//    WriteUARTData(data & 0xFF);
}

void RequestGyroX()
{
//    short data = GetRawGyroX();
//    WriteUARTData(data >> 8);
//    WriteUARTData(data & 0xFF);
}

void RequestGyroY()
{
//    short data = GetRawGyroY();
//    WriteUARTData(data >> 8);
//    WriteUARTData(data & 0xFF);
}

void RequestGyroZ()
{
//    short data = GetRawGyroZ();
//    WriteUARTData(data >> 8);
//    WriteUARTData(data & 0xFF);
}

void RequestAccelAngleX()
{
//    short data = GetAccelAngleX();
//    WriteUARTData(data >> 8);
//    WriteUARTData(data & 0xFF);
    
//    WriteUARTFloat32(GetAccelAngleX());
}

void RequestAccelAngleY()
{
//    short data = GetAccelAngleY();
//    WriteUARTData(data >> 8);
//    WriteUARTData(data & 0xFF);   
    
//    WriteUARTFloat32(GetAccelAngleY());
}

void RequestRX1()
{
//    unsigned short data = GetRXChannelValue(RX_CHANNEL_1);
//    WriteUARTData(data >> 8);
//    WriteUARTData(data & 0xFF);
}

void RequestRX2()
{
//    unsigned short data = GetRXChannelValue(RX_CHANNEL_2);
//    WriteUARTData(data >> 8);
//    WriteUARTData(data & 0xFF);
}

void RequestRX3()
{
//    unsigned short data = GetRXChannelValue(RX_CHANNEL_3);
//    WriteUARTData(data >> 8);
//    WriteUARTData(data & 0xFF);
}

void RequestRX4()
{
//    unsigned short data = GetRXChannelValue(RX_CHANNEL_4);
//    WriteUARTData(data >> 8);
//    WriteUARTData(data & 0xFF);
}

void RequestRX5()
{
//    unsigned short data = GetRXChannelValue(RX_CHANNEL_5);
//    WriteUARTData(data >> 8);
//    WriteUARTData(data & 0xFF);
}

void RequestKP()
{
    unsigned int axis = (unsigned int)(ReadUARTChar(&pcBus) & 0xFF);
    WriteUARTFloat32(GetKP(axis), &pcBus);
}

void RequestKI()
{
    unsigned int axis = (unsigned int)(ReadUARTChar(&pcBus) & 0xFF);
    WriteUARTFloat32(GetKI(axis), &pcBus);
}

void RequestKD()
{
    unsigned int axis = (unsigned int)(ReadUARTChar(&pcBus) & 0xFF);
    WriteUARTFloat32(GetKD(axis), &pcBus);
}

void RequestSetKP()
{
    unsigned int axis = (unsigned int)(ReadUARTChar(&pcBus) & 0xFF);
    SetKP(ReadUARTFloat32(&pcBus), axis);
    status = COMMAND_UI_CHANGE;
}

void RequestSetKI()
{
    unsigned int axis = (unsigned int)(ReadUARTChar(&pcBus) & 0xFF);
    SetKI(ReadUARTFloat32(&pcBus), axis);
    status = COMMAND_UI_CHANGE;
}

void RequestSetKD()
{
    unsigned int axis = (unsigned int)(ReadUARTChar(&pcBus) & 0xFF);
    SetKD(ReadUARTFloat32(&pcBus), axis);
    status = COMMAND_UI_CHANGE;
}

void RequestConvGyroX()
{
//    WriteUARTFloat32(GetGyroX());
}

void RequestConvGyroY()
{
//    WriteUARTFloat32(GetGyroY());
}

void RequestConvGyroZ()
{
//    WriteUARTFloat32(GetGyroZ());
}

void RunComplementaryFilter()
{
    //float dt = ReadUARTFloat32();
    
//    float gyroX = 0;
//    float accelAngleX = 0;
//    float currentAngle = 0;
//    for(;;)
//    {
//        //ReadUARTChar();
//        //debug use
////        LATAbits.LATA0 = !LATAbits.LATA0;
//        gyroX = GetGyroX();
//        accelAngleX = GetAccelAngleX();
//        currentAngle = ComputeComplementaryAngle(currentAngle, gyroX,
//                accelAngleX, dt);
//        //WriteUARTFloat32(gyroX);
//        //WriteUARTFloat32(accelAngleX);
//        WriteUARTFloat32(currentAngle);
//    }
}

void RequestFlightMode()
{
    WriteUARTData((unsigned char)GetFlightMode(), &pcBus);
}

void RequestSetFlightMode()
{
    SetFlightMode((FlightMode)ReadUARTChar(&pcBus));
    status = COMMAND_UI_CHANGE;
}

void RequestRX()
{
    unsigned char channel = ReadUARTChar(&pcBus) & 0xFF;
    WriteUART16(GetSRXChannelAt(channel), &pcBus);
}

void RequestVBatt()
{
    WriteUARTFloat32(GetVBatt(), &pcBus);
}

void RequestFades()
{
    WriteUARTData(GetNumSRXFades(), &pcBus);
}