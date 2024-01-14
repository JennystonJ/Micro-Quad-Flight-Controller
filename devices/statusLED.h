/* 
 * File:   statusLED.h
 * Author: Jennyston
 *
 * Created on April 19, 2016, 8:51 PM
 */

#ifndef STATUSLED_H
#define	STATUSLED_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>
#include <stdbool.h>
    
#define RED_STATUS_LED LATAbits.LATA10
#define GREEN_STATUS_LED LATAbits.LATA7
#define BLUE_STATUS_LED LATBbits.LATB14
#define YELLOW_STATUS_LED LATAbits.LATA1
    
    void SetRedStatusLED(bool enabled);
    void SetGreenStatusLED(bool enabled);
    void SetBlueStatusLED(bool enabled);
    void SetYellowStatusLED(bool enabled);
    void SetStatusLEDArmed();
    void SetStatusLEDDisarmed();
    void SetStatusLEDWarning();
    void ClearStatusLED();

#ifdef	__cplusplus
}
#endif

#endif	/* STATUSLED_H */

