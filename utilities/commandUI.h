/* 
 * File:   commandUI.h
 * Author: Jennyston
 *
 * Created on March 10, 2016, 10:59 PM
 */

#ifndef COMMANDUI_H
#define	COMMANDUI_H

#ifdef	__cplusplus
extern "C" {
#endif
#include "../peripherals/uart.h"
    
#define PC_BUS UART_1
//230400 baud
//#define PC_BUS_BRG_VAL 51
//19200 baud
//#define PC_BUS_BRG_VAL 624
//115200 baud
#define PC_BUS_BRG_VAL 103
#define COMMAND_UI_NO_CHANGE 0
#define COMMAND_UI_CHANGE 1
    
    
    static Uart pcBus;
    void InitCommandUI();
    //returns status
    int StartCommandUI();

#ifdef	__cplusplus
}
#endif

#endif	/* COMMANDUI_H */

