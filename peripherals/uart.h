/* 
 * File:   uart.h
 * Author: Jennyston
 *
 * Created on April 5, 2016, 4:11 PM
 */

#ifndef UART_H
#define	UART_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdbool.h>
    
#define UART_1 0
#define UART_2 1
    
    typedef struct
    {
        char uartBus;
        volatile int *UxMODE;
        volatile int *UxSTA;
        volatile int *UxTXREG;
        volatile int *UxRXREG;
        volatile int *UxBRG;
    }Uart;
    
    void InitUART(unsigned int uxbrg, char uartBus, Uart *uart);
    void WriteUARTData(unsigned char data, Uart *uart);
    void WriteUART16(unsigned short data, Uart *uart);
    void WriteUARTFloat32(float data, Uart *uart);
    void WriteUARTBool(bool boolean, Uart *uart);
    unsigned char ReadUARTChar(Uart *uart);
    unsigned int ReadUARTTimeMs(Uart *uart);
    unsigned short ReadUART16(Uart *uart);
    float ReadUARTFloat32(Uart *uart);
    void EnableUARTRXInterrupts(Uart *uart);

#ifdef	__cplusplus
}
#endif

#endif	/* UART_H */

