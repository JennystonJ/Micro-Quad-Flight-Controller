#include "timer4.h"
#include <xc.h>

void InitTimer4()
{
    T4CON = 0x0000;
}

bool IsTimer4Running()
{
    return (bool)T4CONbits.ON;
}

void SetTimer4Interrupt(bool enable)
{
    IEC0bits.T4IE = enable;
}

void StartTimer4()
{
    T4CONbits.ON = 1;
}

void StopTimer4()
{
    T4CONbits.ON = 0;
}

void SetTimer4Period(unsigned int period)
{
    PR4 = period;
}

void SetTimer4InterruptPriority(int priority)
{
    IPC4bits.T4IP = priority;
}

void SetTimer4Prescaler(int prescaler)
{
    T4CONbits.TCKPS = prescaler;
}

void ResetTimer4()
{
    TMR4 = 0x0000;
}
