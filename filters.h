/* 
 * File:   filters.h
 * Author: Jennyston
 *
 * Created on April 9, 2016, 9:37 PM
 */

#ifndef FILTERS_H
#define	FILTERS_H

#ifdef	__cplusplus
extern "C" {
#endif

#define GYRO_PERCENT 0.99
#define ACCEL_PERCENT (1-GYRO_PERCENT)
    
    float ComputeComplementaryAngle(float currentAngle, float gyroRate,
            float accelAngle, float dt);

#ifdef	__cplusplus
}
#endif

#endif	/* FILTERS_H */

