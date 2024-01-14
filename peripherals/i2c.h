/* 
 * File:   i2c.h
 * Author: Jennyston
 *
 * Created on April 1, 2016, 4:40 PM
 */

#ifndef I2C_H
#define	I2C_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdbool.h>
    
    void InitI2C();
    void StartI2C();
    void RestartI2C();
    void StopI2C();
    void WriteI2CByte(unsigned char byte);
    void IdleI2C();
    bool GetI2CACKStatus();
    void NotACKI2C();
    void ACKI2C();
    unsigned char ReadI2CByte();


#ifdef	__cplusplus
}
#endif

#endif	/* I2C_H */

