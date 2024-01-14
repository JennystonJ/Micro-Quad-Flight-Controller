/* 
 * File:   24fc512.h
 * Author: Jennyston
 *
 * Created on September 17, 2022, 7:51 PM
 */

#ifndef FC512_H
#define	FC512_H

#ifdef	__cplusplus
extern "C" {
#endif

#define EEPROM_I2C_ADDRESS 0b10100000 //address with end write bit
    
    void WriteEEPROMByte(unsigned char addr, unsigned char byte);
    void WriteEEPROMData(unsigned char addr, unsigned char *data,
        unsigned char length);
    unsigned char ReadEEPROMByte(unsigned char addr);
    void ReadEEPROMData(unsigned char addr, unsigned char *data,
        unsigned char length);


#ifdef	__cplusplus
}
#endif

#endif	/* FC512_H */
