#include "timer3.h"
#include <xc.h>

void InitTimer3()
{
    T3CON = 0x0000;
}

bool IsTimer3Running()
{
    return (bool)T3CONbits.ON;
}

void SetTimer3Interrupt(bool enable)
{
    IEC0bits.T3IE = enable;
}

void StartTimer3()
{
    T3CONbits.ON = 1;
}

void StopTimer3()
{
    T3CONbits.ON = 0;
}

void SetTimer3Period(unsigned int period)
{
    PR3 = period;
}

void SetTimer3InterruptPriority(int priority)
{
    IPC3bits.T3IP = priority;
}

void SetTimer3Prescaler(int prescaler)
{
    T3CONbits.TCKPS = prescaler;
}


