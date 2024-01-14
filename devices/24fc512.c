#include "24fc512.h"
#include "../peripherals/i2c.h"
#include "../utilities/delay.h"

void WriteEEPROMByte(unsigned char addr, unsigned char byte) {
    IdleI2C();
    StartI2C();
    WriteI2CByte(EEPROM_I2C_ADDRESS);
    IdleI2C();

    GetI2CACKStatus();
    
    //write upper byte address
    WriteI2CByte(0);
    IdleI2C();

    GetI2CACKStatus();
    
    //write lower byte address
    WriteI2CByte(addr);
    IdleI2C();

    GetI2CACKStatus();
    
    //write byte
    WriteI2CByte(byte);
    IdleI2C();
    
    GetI2CACKStatus();
    
    StopI2C();
}

void WriteEEPROMData(unsigned char addr, unsigned char *data,
        unsigned char length) {
    
    IdleI2C();
    StartI2C();
    WriteI2CByte(EEPROM_I2C_ADDRESS);
    IdleI2C();

    GetI2CACKStatus();
    
    //write upper byte address
    WriteI2CByte(0);
    IdleI2C();

    GetI2CACKStatus();
    
    //write lower byte address
    WriteI2CByte(addr);
    IdleI2C();

    GetI2CACKStatus();
    
    for(int i = 0; i < length; i++) {
        //write at i
        WriteI2CByte(*(data+i));
        IdleI2C();
        GetI2CACKStatus();
    }
    
    StopI2C();
    //give time to write page
    for(int i = 0; i < 5; i++) {
        Delay1Ms();
    }
}

unsigned char ReadEEPROMByte(unsigned char addr) {
    IdleI2C();
    StartI2C();
    WriteI2CByte(EEPROM_I2C_ADDRESS);
    IdleI2C();

    GetI2CACKStatus();
    
    //write upper byte address
    WriteI2CByte(0);
    IdleI2C();

    GetI2CACKStatus();
    
    //write lower byte address
    WriteI2CByte(addr);
    IdleI2C();

    GetI2CACKStatus();
        
    RestartI2C();
    WriteI2CByte(EEPROM_I2C_ADDRESS | 0x01);
    IdleI2C();
    
    unsigned char data = ReadI2CByte();
    NotACKI2C();
     
    StopI2C();
    
    return data;
}

void ReadEEPROMData(unsigned char addr, unsigned char *data,
        unsigned char length) {
    
    IdleI2C();
    StartI2C();
    WriteI2CByte(EEPROM_I2C_ADDRESS);
    IdleI2C();

    GetI2CACKStatus();
    
    //write upper byte address
    WriteI2CByte(0);
    IdleI2C();

    GetI2CACKStatus();
    
    //write lower byte address
    WriteI2CByte(addr);
    IdleI2C();

    GetI2CACKStatus();
    
    RestartI2C();
    WriteI2CByte(EEPROM_I2C_ADDRESS | 0x01);
    IdleI2C();
    
    for(int i = 0; i < length; i++) {
        ACKI2C();
        *(data + i) = ReadI2CByte();
    }
     
    NotACKI2C();
    
    StopI2C();    
}