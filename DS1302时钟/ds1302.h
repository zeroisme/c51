#ifndef __DS1302_H__
#define __DS1302_H__
#include <stdint.h>
void ds1302_init();
void ds1302_disable_wp(void);
uint8_t ds1302_read_seconds(void);
void ds1302_write_seconds(uint8_t seconds);
#endif