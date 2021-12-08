#include <8052.h>
#include <stdint.h>
#include "bcd.h"

__sbit __at (0xB6) DS1302_SCLK;
__sbit __at (0xB4) DS1302_IO;
__sbit __at (0xB5) DS1302_CE;

#define DS1302_WP 0x8E

#define SECONDS 0x80
#define MINUTES 0x82
#define HOUR 0x84
#define DAY 0x86
#define MONTH 0x88
#define WEEK 0x8A
#define YEAR 0x8C

void ds1302_init() {
    // 初始上电为高电平, 初始化置0
    DS1302_CE = 0;
    DS1302_SCLK = 0;
}

void write_byte(uint8_t dat) {
    uint8_t i;
    for(i = 0; i < 8; i++) {
        DS1302_IO = dat & 0x01;
        DS1302_SCLK = 1;
        DS1302_SCLK = 0;
        dat = dat >> 1;
    }
}

uint8_t read_byte(void) {
    uint8_t i, dat = 0;

    for(i = 0; i < 8; i++) {
        dat = dat >> 1;
        if(DS1302_IO) {
            dat |= 0x80;
        }
        DS1302_SCLK = 1;
        DS1302_SCLK = 0;
    }
    return dat;
}

void ds1302_write(uint8_t address, uint8_t dat) {
    DS1302_SCLK = 0;
    DS1302_CE = 1;
    write_byte(address);
    write_byte(dat);
    DS1302_CE = 0;
}

uint8_t ds1302_read(uint8_t address) {
    uint8_t dat;
    DS1302_SCLK = 0;
    DS1302_CE = 1;
    write_byte(address);
    dat = read_byte();
    DS1302_CE = 0;
    DS1302_SCLK = 1;
    DS1302_IO = 0;
    DS1302_IO = 1;

    return dat;
}

void ds1302_disable_wp(void) {
    ds1302_write(DS1302_WP, 0);
}

uint8_t ds1302_read_seconds(void) {
    uint8_t address = SECONDS | 1;
    return bcd_decode(ds1302_read(address));
}

void ds1302_write_seconds(uint8_t seconds) {
    uint8_t dat = bcd_encode(seconds);
    ds1302_write(SECONDS, dat);
}