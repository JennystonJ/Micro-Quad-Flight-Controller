/* 
 * File:   pid.h
 * Author: Jennyston
 *
 * Created on February 19, 2016, 9:47 PM
 */

#ifndef PID_H
#define	PID_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "pidVar.h"
    
#define EPSILON 0.1
//#define DT (1.0/100)
#define DT (1.0/400.0)
//#define DT (1.0/1600.0)

#define MAX 30000 //for current saturation
#define MIN -30000
    
#define I_MAX 500
#define I_MIN -500
    
    
    float ComputePID(float setPoint, float actualPosition, PIDVar *pidVar);


#ifdef	__cplusplus
}
#endif

#endif	/* PID_H */

