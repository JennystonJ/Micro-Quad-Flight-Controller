/* 
 * File:   timer1.h
 * Author: Jennyston
 *
 * Created on April 7, 2016, 3:02 PM
 */

#ifndef TIMER1_H
#define	TIMER1_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdbool.h>
    
    void InitTimer1();
    bool IsTimer1Running();
    void SetTimer1Interrupt(bool enable);
    void StartTimer1();
    void StopTimer1();
    void SetTimer1Period(unsigned int period);
    void SetTimer1InterruptPriority(int priority);
    void SetTimer1Prescaler(int prescaler);

#ifdef	__cplusplus
}
#endif

#endif	/* TIMER1_H */

