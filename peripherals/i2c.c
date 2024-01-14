#include "i2c.h"
#include <xc.h>

void InitI2C()
{
    //set baud to 400 kHz
    I2C1BRG = 53;
    
    
    I2C1CONbits.ON = 0;
    Nop();
    Nop();
    Nop();
    I2C1CONbits.SIDL = 0;
    I2C1CONbits.SCLREL = 1;
    I2C1CONbits.STRICT = 0;
    I2C1CONbits.A10M = 0;
    I2C1CONbits.DISSLW = 1;
    I2C1CONbits.SMEN = 0;
    I2C1CONbits.GCEN = 0;
    I2C1CONbits.STREN = 0;
    I2C1CONbits.ACKDT = 0;
    I2C1CONbits.ACKEN = 0;
    I2C1CONbits.RCEN = 0;
    I2C1CONbits.PEN = 0;
    I2C1CONbits.RSEN = 0;
    I2C1CONbits.SEN = 0;
    
    
    I2C1RCV = 0x0000;
    I2C1TRN = 0x0000;
    
    I2C1CONbits.ON = 1;
}

void StartI2C()
{
    I2C1CONbits.SEN = 1;
    Nop();
    while(I2C1CONbits.SEN);
}

void RestartI2C()
{
    I2C1CONbits.RSEN = 1;
    Nop();
    while(I2C1CONbits.RSEN);  
}

void StopI2C()
{
    I2C1CONbits.PEN = 1;
    Nop();
    while(I2C1CONbits.PEN);   
}

void WriteI2CByte(unsigned char byte)
{
    I2C1TRN = byte;
    Nop();
    while(I2C1STATbits.TBF);
}

void IdleI2C()
{
    while(I2C1STATbits.TRSTAT);
}

bool GetI2CACKStatus()
{
    return(!I2C1STATbits.ACKSTAT);
}

void NotACKI2C()
{
    I2C1CONbits.ACKDT = 1;
    I2C1CONbits.ACKEN = 1;
    while(I2C1CONbits.ACKEN);
    I2C1CONbits.ACKDT = 0;
}

void ACKI2C()
{
    I2C1CONbits.ACKDT = 0;
    I2C1CONbits.ACKEN = 1;
    while(I2C1CONbits.ACKEN);
}

unsigned char ReadI2CByte()
{
    I2C1CONbits.RCEN = 1;
    Nop();
    while(!I2C1STATbits.RBF);
    return(I2C1RCV);
}

