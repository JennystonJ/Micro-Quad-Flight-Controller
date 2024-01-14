/* 
 * File:   conversion.h
 * Author: Jennyston
 *
 * Created on April 9, 2016, 10:18 PM
 */

#ifndef CONVERSION_H
#define	CONVERSION_H

#ifdef	__cplusplus
extern "C" {
#endif

#define BANK_ANGLE_MAX 35.0f
#define BANK_ANGLE_MIN -35.0f
#define BANK_ANGLE_RANGE (BANK_ANGLE_MAX - BANK_ANGLE_MIN)

//old rates
//#define ROTATION_DPS_MAX 252.0f
//#define ROTATION_DPS_MIN -252.0f
#define ROTATION_DPS_MAX 360.0f
#define ROTATION_DPS_MIN -360.0f
#define ROTATION_DPS_RANGE (ROTATION_DPS_MAX - ROTATION_DPS_MIN)
    
    float ReceiverValueToDegrees(unsigned short value);
    float ReceiverValueToDPS(unsigned short value);


#ifdef	__cplusplus
}
#endif

#endif	/* CONVERSION_H */

