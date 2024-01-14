#include "watchDogTimer.h"
#include <stdbool.h>
#include "peripherals/timers/timer4.h"


void InitWatchDogTimer()
{
    InitTimer4();
    
    SetTimer4InterruptPriority(7);
    SetTimer4Interrupt(true);
    
    SetTimer4Period(0xFFFF);
    SetTimer4Prescaler(0b101);
    
    StartTimer4();
}

void ResetWatchDogTimer()
{
    ResetTimer4();
}

void ResumeWatchDogTimer()
{
    StartTimer4();
}

void StopWatchDogTimer()
{
    StopTimer4();
}
