#include "timer2.h"
#include <xc.h>

void InitTimer2()
{
    T2CON = 0x0000;
}

bool IsTimer2Running()
{
    return (bool)T2CONbits.ON;
}

void SetTimer2Interrupt(bool enable)
{
    IEC0bits.T2IE = enable;
}

void StartTimer2()
{
    T2CONbits.ON = 1;
}

void StopTimer2()
{
    T2CONbits.ON = 0;
}

void SetTimer2Period(unsigned int period)
{
    PR2 = period;
}

void SetTimer2InterruptPriority(int priority)
{
    IPC2bits.T2IP = priority;
}

void SetTimer2Prescaler(int prescaler)
{
    T2CONbits.TCKPS = prescaler;
}

