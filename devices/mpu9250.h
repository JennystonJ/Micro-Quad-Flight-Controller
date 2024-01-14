/* 
 * File:   mpu9250.h
 * Author: Jennyston
 *
 * Created on April 1, 2016, 8:15 PM
 */

#ifndef MPU9250_H
#define	MPU9250_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "mpu9250RegisterMap.h"
    
#define MPU9250_ADDRESS 0b11010010 // Address with end write bit
    
#define GYRO_SENSITIVITY (65.5f) //500 dps
#define ACCEL_SENSITIVITY 8192 //+/- 4g
#define NUM_CALIBRATION_SAMPLES 1000
    
    void InitMPU();
    void CalibrateGyros();
    void WriteMPUCommand(unsigned char registerAdd, unsigned char data);
    unsigned char ReadMPUCommand(unsigned char data);
    short GetRawAccelX();
    short GetRawAccelY();
    short GetRawAccelZ();
    short GetRawGyroX();
    short GetRawGyroY();
    short GetRawGyroZ();
    float GetAccelX();
    float GetAccelY();
    float GetAccelZ();
    float GetGyroX();
    float GetGyroY();
    float GetGyroZ();
    float GetAccelAngleX();
    float GetAccelAngleY();
        



#ifdef	__cplusplus
}
#endif

#endif	/* MPU9250_H */

