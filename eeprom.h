/* 
 * File:   eeprom.h
 * Author: Jenny
 *
 * Created on September 17, 2022, 9:55 PM
 */

#ifndef EEPROM_H
#define	EEPROM_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "pidVar.h"
    
#define EEPROM_INIT_ADDR 0
#define EEPROM_RATE_PID 1
#define EEPROM_PID_PITCH EEPROM_RATE_PID
#define EEPROM_PID_ROLL (EEPROM_PID_PITCH + sizeof(PIDVar))
#define EEPROM_PID_YAW (EEPROM_PID_ROLL + sizeof(PIDVar))

#ifdef	__cplusplus
}
#endif

#endif	/* EEPROM_H */

