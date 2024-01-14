#include "pwm.h"
#include <xc.h>
#include "timers/timer2.h"

//private member variables
static volatile unsigned int *OCxCON;
static volatile unsigned int *OCxR;
static volatile unsigned int *OCxRS;

//forward routine declarations
void LoadPWMRegisters(int channel);

void InitPWM(int channel)
{
    LoadPWMRegisters(channel);
    
    InitTimer2();
    SetTimer2Interrupt(false);
    SetTimer2Period(PWM_PERIOD);
    //1:2 prescale ratio
    //SetTimer2Prescaler(0b001);
    //1:4 prescale ratio
    SetTimer2Prescaler(0b010);
    StartTimer2();
    
    //set duty cycle to 0%
    *OCxRS = 0x00;
    //set period
    *OCxR = PWM_PERIOD;
    //turn on PWM, 16-bit, timer 2, fault disabled
    *OCxCON = 0b1000000000000110;
}

void SetPWMDutyCycle(unsigned short dutyCycle, int channel)
{
    LoadPWMRegisters(channel);
    //*OCxRS = dutyCycle / 16;
    *OCxRS = dutyCycle / 64;
}

unsigned short GetPWMDutyCycle(int channel)
{
    LoadPWMRegisters(channel);
    return *OCxRS;
}

void LoadPWMRegisters(int channel)
{
    switch(channel)
    {
        case 0:
            OCxCON = &OC1CON;
            OCxR = &OC1R;
            OCxRS = &OC1RS;
            break;
        case 1:
            OCxCON = &OC2CON;
            OCxR = &OC2R;
            OCxRS = &OC2RS;
            break;
        case 2:
            OCxCON = &OC3CON;
            OCxR = &OC3R;
            OCxRS = &OC3RS;
            break;
        case 3:
            OCxCON = &OC4CON;
            OCxR = &OC4R;
            OCxRS = &OC4RS;
            break;
        case 4:
            OCxCON = &OC5CON;
            OCxR = &OC5R;
            OCxRS = &OC5RS;
            break;
    }
}

