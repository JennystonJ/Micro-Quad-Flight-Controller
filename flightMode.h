/* 
 * File:   flightMode.h
 * Author: Jennyston
 *
 * Created on December 17, 2016, 4:21 PM
 */

#ifndef FLIGHTMODE_H
#define	FLIGHTMODE_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef enum
    {
        RATE_MODE,
        ANGLE_MODE
    } FlightMode;

    FlightMode GetFlightMode();
    void SetFlightMode(FlightMode flightMode);

#ifdef	__cplusplus
}
#endif

#endif	/* FLIGHTMODE_H */

