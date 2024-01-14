/* 
 * File:   timer3.h
 * Author: Jennyston
 *
 * Created on April 2, 2016, 11:17 PM
 */

#ifndef TIMER3_H
#define	TIMER3_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdbool.h>
    
    void InitTimer3();
    bool IsTimer3Running();
    void SetTimer3Interrupt(bool enable);
    void StartTimer3();
    void StopTimer3();
    void SetTimer3Period(unsigned int period);
    void SetTimer3InterruptPriority(int priority);
    void SetTimer3Prescaler(int prescaler);



#ifdef	__cplusplus
}
#endif

#endif	/* TIMER3_H */

