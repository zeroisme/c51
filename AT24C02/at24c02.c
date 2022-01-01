#include "i2c.h"
#include "at24c02.h"

#define EEPROM_ADDRESS 0xA0 // AT24C02地址为 1010 0000

void at24c02_write_byte(unsigned char address, unsigned char dat) {
    i2c_start();
    i2c_write_byte(EEPROM_ADDRESS);
    i2c_wait_ack();
    i2c_write_byte(address);
    i2c_wait_ack();
    i2c_write_byte(dat);
    i2c_wait_ack();
    i2c_stop();
}

unsigned char at24c02_read_byte(unsigned char address) {
    unsigned char dat = 0;
    i2c_start();
    i2c_write_byte(EEPROM_ADDRESS);
    i2c_wait_ack();
    i2c_write_byte(address);
    i2c_wait_ack();
    i2c_start();
    i2c_write_byte(EEPROM_ADDRESS | 1);
    i2c_wait_ack();
    dat = i2c_read_byte(0);
    i2c_stop();
    return dat;
}