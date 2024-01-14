/* 
 * File:   timer2.h
 * Author: Jennyston
 *
 * Created on March 31, 2016, 10:39 PM
 */

#ifndef TIMER2_H
#define	TIMER2_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdbool.h>
    
    void InitTimer2();
    bool IsTimer2Running();
    void SetTimer2Interrupt(bool enable);
    void StartTimer2();
    void StopTimer2();
    void SetTimer2Period(unsigned int period);
    void SetTimer2InterruptPriority(int priority);
    void SetTimer2Prescaler(int prescaler);


#ifdef	__cplusplus
}
#endif

#endif	/* TIMER2_H */

