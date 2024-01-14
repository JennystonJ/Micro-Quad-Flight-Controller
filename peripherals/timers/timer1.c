#include "timer1.h"
#include <xc.h>

void InitTimer1()
{
    T1CON = 0x0000;
}

bool IsTimer1Running()
{
    return (bool)T1CONbits.ON;
}

void SetTimer1Interrupt(bool enable)
{
    IEC0bits.T1IE = enable;
}

void StartTimer1()
{
    T1CONbits.ON = 1;
}

void StopTimer1()
{
    T1CONbits.ON = 0;
}

void SetTimer1Period(unsigned int period)
{
    PR1 = period;
}

void SetTimer1InterruptPriority(int priority)
{
    IPC1bits.T1IP = priority;
}

void SetTimer1Prescaler(int prescaler)
{
    T1CONbits.TCKPS = prescaler;
}


