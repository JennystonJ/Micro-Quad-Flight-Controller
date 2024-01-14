/* 
 * File:   timer4.h
 * Author: Jennyston
 *
 * Created on April 19, 2016, 9:15 PM
 */

#ifndef TIMER4_H
#define	TIMER4_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdbool.h>
    
    void InitTimer4();
    bool IsTimer4Running();
    void SetTimer4Interrupt(bool enable);
    void StartTimer4();
    void StopTimer4();
    void SetTimer4Period(unsigned int period);
    void SetTimer4InterruptPriority(int priority);
    void SetTimer4Prescaler(int prescaler);
    void ResetTimer4();


#ifdef	__cplusplus
}
#endif

#endif	/* TIMER4_H */

