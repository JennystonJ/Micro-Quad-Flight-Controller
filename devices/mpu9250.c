#include "mpu9250.h"
#include "../peripherals/i2c.h"
#include <math.h>
#include "../devices/statusLED.h"

//private member variables
static short gyroOffsetX = 0;
static short gyroOffsetY = 0;
static short gyroOffsetZ = 0;

//public routines
void InitMPU()
{    
    WriteMPUCommand(MPU9250_PWR_MGMT_1, 0b00000010);
    WriteMPUCommand(MPU9250_PWR_MGMT_2, 0x00);  
    WriteMPUCommand(MPU9250_SIGNAL_PATH_RESET, 0b00000111);
    WriteMPUCommand(MPU9250_SMPLRT_DIV, 0x01);
    WriteMPUCommand(MPU9250_CONFIG, 0x03);
    WriteMPUCommand(MPU9250_GYRO_CONFIG, 0b00001000);
    WriteMPUCommand(MPU9250_ACCEL_CONFIG, 0b00001000);
    WriteMPUCommand(MPU9250_ACCEL_CONFIG_2, 0x03);
    
    CalibrateGyros();
    
    unsigned char data = ReadMPUCommand(MPU9250_WHO_AM_I);
    
    if(data != 0x73)
    {
        SetStatusLEDWarning();
        for(;;)
        {
            
        }
    }
}

void WriteMPUCommand(unsigned char registerAdd, unsigned char data)
{
    IdleI2C();
    StartI2C();
    WriteI2CByte(MPU9250_ADDRESS);
    IdleI2C();
    //TODO: propagate error to system
    GetI2CACKStatus();
    
    WriteI2CByte(registerAdd);
    IdleI2C();
    //TODO: propagate error to system
    GetI2CACKStatus();
    
    WriteI2CByte(data);
    IdleI2C();
    //TODO: propagate error to system
    GetI2CACKStatus();
    
    StopI2C();
}

unsigned char ReadMPUCommand(unsigned char registerAdd)
{
    IdleI2C();
    StartI2C();
    WriteI2CByte(MPU9250_ADDRESS);
    IdleI2C();
    //TODO: propagate error to system
    GetI2CACKStatus();
    
    WriteI2CByte(registerAdd);
    IdleI2C();
    //TODO: propagate error to system
    GetI2CACKStatus();
    
    RestartI2C();
    WriteI2CByte(MPU9250_ADDRESS | 0x01);
    IdleI2C();
    
    unsigned char data = ReadI2CByte();
    NotACKI2C();
     
    StopI2C();
    
    return data;
}

void CalibrateGyros()
{
    
    gyroOffsetX = 0;
    gyroOffsetY = 0;
    gyroOffsetZ = 0;
    
    int sum = 0;
    
    //calibrate x-axis
    for(int i = 0; i < NUM_CALIBRATION_SAMPLES; i++)
    {
        sum += GetRawGyroX();
    }
    gyroOffsetX = sum / NUM_CALIBRATION_SAMPLES;
    
    sum = 0;
    
    //calibrate y-axis
    for(int i = 0; i < NUM_CALIBRATION_SAMPLES; i++)
    {
        sum += GetRawGyroY();
    }
    gyroOffsetY = sum / NUM_CALIBRATION_SAMPLES;
    
    sum = 0;
    
    //calibrate z-axis
    for(int i = 0; i < NUM_CALIBRATION_SAMPLES; i++)
    {
        sum += GetRawGyroZ();
    }
    gyroOffsetZ = sum / NUM_CALIBRATION_SAMPLES;
}

short GetRawAccelX() {
    unsigned char upperByte = ReadMPUCommand(MPU9250_ACCEL_XOUT_H);
    unsigned char lowerByte = ReadMPUCommand(MPU9250_ACCEL_XOUT_L);

    return ((short)upperByte << 8) | (short)lowerByte;
}

short GetRawAccelY() {
    unsigned char upperByte = ReadMPUCommand(MPU9250_ACCEL_YOUT_H);
    unsigned char lowerByte = ReadMPUCommand(MPU9250_ACCEL_YOUT_L);

    return ((short)upperByte << 8) | (short)lowerByte;
}

short GetRawAccelZ() {
    unsigned char upperByte = ReadMPUCommand(MPU9250_ACCEL_ZOUT_H);
    unsigned char lowerByte = ReadMPUCommand(MPU9250_ACCEL_ZOUT_L);

    
    return ((short)upperByte << 8) | (short)lowerByte;   
}

short GetRawGyroX() {
    unsigned char upperByte = ReadMPUCommand(MPU9250_GYRO_XOUT_H);
    unsigned char lowerByte = ReadMPUCommand(MPU9250_GYRO_XOUT_L);

    return (((short)upperByte << 8) | (short)lowerByte) - gyroOffsetX;
}

short GetRawGyroY() {
    unsigned char upperByte = ReadMPUCommand(MPU9250_GYRO_YOUT_H);
    unsigned char lowerByte = ReadMPUCommand(MPU9250_GYRO_YOUT_L);

    return (((short)upperByte << 8) | (short)lowerByte) - gyroOffsetY;
}

short GetRawGyroZ() {
    unsigned char upperByte = ReadMPUCommand(MPU9250_GYRO_ZOUT_H);
    unsigned char lowerByte = ReadMPUCommand(MPU9250_GYRO_ZOUT_L);

    return (((short)upperByte << 8) | (short)lowerByte) - gyroOffsetZ;
}

float GetGyroX() {
    int value = GetRawGyroX();
    return ((float) value) / GYRO_SENSITIVITY;
}

float GetGyroY() {
    int value = GetRawGyroY();
    return ((float) value) / GYRO_SENSITIVITY;
}

float GetGyroZ() {
    int value = GetRawGyroZ();
    return ((float) value) / GYRO_SENSITIVITY;
}

float GetAccelX() {
    int value = GetRawAccelX();
    return (float) value / ACCEL_SENSITIVITY;
}

float GetAccelY() {
    int value = GetRawAccelY();
    return (float) value / ACCEL_SENSITIVITY;
}

float GetAccelZ() {
    int value = GetRawAccelZ();
    return (float) value / ACCEL_SENSITIVITY;
}

float GetAccelAngleX()
{
    return 57.295*atan((float)GetRawAccelY()/sqrt(pow((float)GetRawAccelZ(),2)+pow((float)GetRawAccelX(),2)));
}

float GetAccelAngleY()
{
    return 57.295*atan((float)(-1.0 * GetRawAccelX())/sqrt(pow((float)GetRawAccelZ(),2)+pow((float)GetRawAccelY(),2))); 
}