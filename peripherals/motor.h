/* 
 * File:   motor.h
 * Author: Jennyston
 *
 * Created on February 13, 2017, 6:21 PM
 */

#ifndef MOTOR_H
#define	MOTOR_H

#ifdef	__cplusplus
extern "C" {
#endif

#define NUM_MOTORS 4
    
#define MOTOR_1 0
#define MOTOR_2 1
#define MOTOR_3 2
#define MOTOR_4 3
    
    void InitMotor(int motor);
    void SetMotorPower(unsigned short power, int motor);
    unsigned int GetMotorPower(int motor);


#ifdef	__cplusplus
}
#endif

#endif	/* MOTOR_H */

