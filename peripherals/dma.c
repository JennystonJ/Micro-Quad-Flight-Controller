#include "dma.h"
#include <xc.h>

void InitDMA(volatile unsigned int *sourceAddress, unsigned char *destinationAddress,
        unsigned short destinationSize)
{
//    //ensure DMA is disabled
//    DMACONbits.ON = 0;
//    Nop();
//    //disable CRC
//    DCRCCON = 0x0000;
//    //disable channel 0 chaining
//    //set priority to 1
//    //enable channel 0
//    DCH0CON = 0b0000000010010001;
//    
//    //start DMA on U2RX interrupt
//    DCH0ECONbits.CHSIRQ = 54;
//    DCH0ECONbits.SIRQEN = 1;
//    //do not abort transfer on interrupt
//    DCH0ECONbits.AIRQEN = 0;
//    
//    //interrupt when destination is full
//    DCH0INTbits.CHDDIE = 1;
//    //clear interrupt flag
//    DCH0INTbits.CHDDIF = 0;
//    
    
//    IEC1CLR = 0x00010000;
//    IFS1CLR = 0x00010000;
//    
//    DMACONSET = 0x00008000;
//    DCH0CON = 0x03;
//    
//    DCH0ECON = (54 << 8) | 0x10;
//    
//    //set DMA interrupt priority
//    IPC10bits.DMA0IP = 5;
//    //enable DMA channel 0 interrupts
//    IEC1bits.DMA0IE = 1;
//    //clear interrupt flag
//    IFS1bits.DMA0IF = 0;
//    
//    DCH0SSA = &U2RXREG;
//    DCH0DSA = (unsigned int) destinationAddress;
//    
//    DCH0SSIZ = 1;
//    DCH0DSIZ = 14;
//    DCH0CSIZ = 1;
//    DCH0INTCLR = 0x00ff00ff;
//    DCH0INTSET = 0x00080000;
    
//    
//    //set source start address and source size to 1
//    DCH0SSA = (unsigned int)sourceAddress;
//    DCH0SSIZ = 1;
//    
//    //set destination start address and destination size
//    DCH0DSA = (unsigned int)destinationAddress;
//    DCH0DSIZ = destinationSize;
//    
//    //transfer 1 byte per an event
//    DCH0CSIZ = 1;
//    
//    
//    //enable channel 0
//    DCH0CONbits.CHBUSY = 1;
//    //enable DMA module
//    DMACON = 0b1000000000000000;
    
//    DMACONSET = 0x00008000;
//    DCH0CON = 0x03;
    
//    //start DMA on U2RX interrupt
//    DCH0ECONbits.CHSIRQ = 54;
//    DCH0ECONbits.SIRQEN = 1;
//    //do not abort transfer on interrupt
//    DCH0ECONbits.AIRQEN = 0;
    
    //set source start address and source size to 1
//    DCH0SSA = (unsigned int)sourceAddress;
//    DCH0SSIZ = 1;
//    
//    //set destination start address and destination size
//    DCH0DSA = (unsigned int)destinationAddress;
//    DCH0DSIZ = destinationSize;
//    
//    DCH0CSIZ = 1;
//    
//    DCH0INTCLR = 0x00FF00FF;
//    
//    //interrupt when destination is full
//    DCH0INTbits.CHDDIE = 1;
//    //clear interrupt flag
//    DCH0INTbits.CHDDIF = 0;
//    
//    DCH0CONSET = 0x80;
    
    DMACONbits.ON = 1;
    DCH0CONbits.CHPRI = 3;
    DCH0CONbits.CHAEN = 1;
    
    IEC1bits.DMA0IE = 0;
    IFS1bits.DMA0IF = 0;
    
    DCH0ECONbits.CHSIRQ = 54;
    DCH0ECONbits.SIRQEN = 1;
    
    DCH0SSA = ((unsigned int)&U2RXREG) & 0x1FFFFFFF;
    DCH0DSA = ((unsigned int) destinationAddress) & 0x1FFFFFFF;
    DCH0SSIZ = 1;
    DCH0DSIZ = destinationSize;
    DCH0CSIZ = 1;
    
    DCH0INT &= ~(0x00FF00FF);
    DCH0INTbits.CHDDIE = 1;
    //DCH0INTbits.CHBCIE = 1;
    DCH0INTbits.CHERIE = 1;
    
    IPC10bits.DMA0IP = 5;
    IPC10bits.DMA0IS = 2;
    IEC1bits.DMA0IE = 1;
    
    DCH0CONbits.CHEN = 1;
}