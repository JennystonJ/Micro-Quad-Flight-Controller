/* 
 * File:   serialReceiver.h
 * Author: Jennyston
 *
 * Created on January 8, 2017, 5:51 PM
 */

#ifndef SERIALRECEIVER_H
#define	SERIALRECEIVER_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "../peripherals/uart.h"
#include <stdbool.h>
    
#define SERIAL_RX_BUS UART_2
//115200 baud
#define SERIAL_RX_UART_BRG 103
//125000 baud
//#define SERIAL_RX_UART_BRG 95
#define SERIAL_RX_TRIS_PIN TRISBbits.TRISB11
#define SERIAL_RX_LAT_PIN LATBbits.LATB11

#define NUM_DSM_MODES 4
#define DSM2_1024_22MS 0x01
#define DSM2_2048_11MS 0x12
#define DSMS_2048_22MS 0xA2
#define DSMX_2048_11MS 0xB2
    
#define RX_NUM_CHANNELS 16
#define RX_THROTTLE 0
#define RX_AILERON 1
#define RX_ELEVATOR 2
#define RX_RUDDER 3
#define RX_GEAR 4
#define RX_AUX_1 5
    
    void InitSRX(unsigned int urx, bool watchDog, char bindType);
    unsigned short GetSRXChannelAt(char index);
    char GetCurrentSRXMode();
    unsigned char GetNumSRXFades();
    void ResumeSRXWatchDog();
    void StopSRXWatchDog();
    
#ifdef	__cplusplus
}
#endif

#endif	/* SERIALRECEIVER_H */

