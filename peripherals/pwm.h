/* 
 * File:   pwm.h
 * Author: Jennyston
 *
 * Created on March 31, 2016, 9:12 PM
 */

#ifndef PWM_H
#define	PWM_H

#ifdef	__cplusplus
extern "C" {
#endif

//#define PWM_PERIOD 65535/16    
#define PWM_PERIOD 65535/64
#define PWM_1 0
#define PWM_2 1
#define PWM_3 2
#define PWM_4 3
#define PWM_5 4
    

    void InitPWM(int channel);
    void SetPWMDutyCycle(unsigned short dutyCycle, int channel);
    unsigned short GetPWMDutyCycle(int channel);


#ifdef	__cplusplus
}
#endif

#endif	/* PWM_H */

