#ifndef __AT24C02_H__
#define __AT24C02_H__
void at24c02_write_byte(unsigned char address, unsigned char dat);
unsigned char at24c02_read_byte(unsigned char address);
#endif