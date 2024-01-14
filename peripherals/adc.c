#include "adc.h"
#include <xc.h>
#include "../utilities/delay.h"

void InitADC()
{
    AD1CON1CLR = 0x8000;
    
    
    
    //auto convert
    AD1CON1 = 0x00E0;
    AD1CON1bits.ASAM = 1;
    
    AD1CSSL = 0;
    
    //external vref+
    AD1CON2 = 0b0010000000000000;
    //AD1CON3 = 0b1001111100000000;
    //Use Fast RC (8MHz)
    
    //AD1CON3 = 0b1000000011111111;
    //AD1CON3 = 0b1001111111111111;
    //Use PBCLK
    AD1CON3 = 0b0001111100000100;
    
    //Select AN8 as input
    AD1CHS = 0x08 << 16;
    
    AD1CON1bits.ON = 1;
    
    Delay1Ms();
    
    //start sampling
    AD1CON1bits.SAMP = 1;
}

unsigned short GetADCResult()
{
//    AD1CHS = 0x08 << 16;
    
    //SAMP is set automatically as per InitADC()
    //AD1CON1bits.SAMP = 1;
    //while(AD1CON1bits.SAMP);
    //while(!AD1CON1bits.DONE);
    
    return ADC1BUF0;
}