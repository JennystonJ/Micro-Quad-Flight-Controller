#include "uart.h"
#include "../utilities/delay.h"
#include <xc.h>

#define FLOAT_LENGTH 4

void LoadUARTRegisters(char uartBus, Uart *uart);
void FlushUARTBuffer(Uart* uart);
void ClearUARTRXOverrun(Uart *uart);

void InitUART(unsigned int uxbrg, char uartBus, Uart *uart)
{
    LoadUARTRegisters(uartBus, uart);
    uart->uartBus = uartBus;
    //230400 baud
    //U1BRG = 51;
    //19200 baud
    //U1BRG = 624;
    *(uart->UxBRG) = uxbrg;
    *(uart->UxSTA) = 0b0001010000000000;
    //Enable UART module
    //8-bit TX/RX
    //Wake enabled
    //High-Speed mode
    //wake from sleep mode
    *(uart->UxMODE) = 0b1000000010001000;
    FlushUARTBuffer(uart);
}

void EnableUARTRXInterrupts(Uart *uart)
{
    switch(uart->uartBus)
    {
        case UART_1:
            IFS1bits.U1RXIF = 0;
            IEC1bits.U1RXIE = 1;
            break;
        case UART_2:
            IFS1bits.U2RXIF = 0;
            IEC1bits.U2RXIE = 1;
            IPC9bits.U2IP = 2;
            break;
    }
}

void WriteUARTData(unsigned char data, Uart *uart)
{
    //while(U1STAbits.UTXBF);
    while(*(uart->UxSTA) & 0x200 > 0);
    *(uart->UxTXREG) = data;
}

void WriteUART16(unsigned short data, Uart *uart)
{
    WriteUARTData(data >> 8, uart);
    WriteUARTData(data & 0xFF, uart);
}

void WriteUARTBool(bool boolean, Uart *uart)
{
    WriteUARTData(boolean? 1 : 0, uart);
}

void WriteUARTFloat32(float data, Uart *uart)
{
    unsigned char *ptrByte = (unsigned char *)&data;
    
    for(int i = 0; i < FLOAT_LENGTH; i++)
    {
        WriteUARTData(*(ptrByte+i), uart);
    }
}

unsigned char ReadUARTChar(Uart *uart)
{
    //while(!U1STAbits.URXDA);
    while(!(*(uart->UxSTA) & 0x01));
    return *(uart->UxRXREG);
}

unsigned int ReadUARTTimeMs(Uart *uart)
{
    FlushUARTBuffer(uart);
    
    unsigned int timeInMs = 0;
    while(!(*(uart->UxSTA) & 0x01))
    {
        Delay1Ms();
        timeInMs++;
    }
    
    return timeInMs;
}

unsigned short ReadUART16(Uart *uart)
{
    unsigned short upperByte = ReadUARTChar(uart) << 8;
    unsigned short lowerByte = ReadUARTChar(uart) & 0xFF;
    
    return upperByte | lowerByte;
}

bool ReadUARTBool(Uart *uart)
{
    return (bool)ReadUARTChar(uart);
}


float ReadUARTFloat32(Uart *uart)
{
    float data;
    unsigned char *ptrByte = (unsigned char *)&data;
    
    for(int i = 0; i < FLOAT_LENGTH; i++)
    {
        *(ptrByte+i) = ReadUARTChar(uart);
    }
    
    return data;
}

//private

void ClearUARTRXOverrun(Uart *uart)
{
    *(uart->UxSTA) = *(uart->UxSTA) & 0b11111111111111111111111111111101;
}

void LoadUARTRegisters(char uartBus, Uart *uart)
{
    if(uartBus == UART_1)
    {
        uart->UxMODE = &U1MODE;
        uart->UxSTA = &U1STA;
        uart->UxTXREG = &U1TXREG;
        uart->UxRXREG = &U1RXREG;
        uart->UxBRG = &U1BRG;
    }
    else if(uartBus == UART_2)
    {
        uart->UxMODE = &U2MODE;
        uart->UxSTA = &U2STA;
        uart->UxTXREG = &U2TXREG;
        uart->UxRXREG = &U2RXREG;
        uart->UxBRG = &U2BRG;   
    }
}

void FlushUARTBuffer(Uart *uart)
{
    unsigned char data;
    while(*(uart->UxSTA) & 0x01)
    {
        //discard data
        data = *(uart->UxRXREG);
    }
    ClearUARTRXOverrun(uart);
}
