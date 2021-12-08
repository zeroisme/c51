#ifndef __DS1302_H__
#define __DS1302_H__
#include <stdint.h>

typedef struct {
    uint8_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    uint8_t second;
} tm;

void ds1302_init();
void ds1302_read_time(tm * t);
void ds1302_write_time(tm *t);
#endif