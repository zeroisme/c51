#include <8052.h>
#include <stdio.h>
#include "lcd1602.h"
#include "ds1302.h"

void main(void) {
    lcd1602_init();
    ds1302_init();
    tm time;
    time.year = 21;
    time.month = 12;
    time.day = 31;
    time.hour = 23;
    time.minute = 59;
    time.second = 59;
    ds1302_write_time(&time);
    char buf[20];
    
    while(1) {
        ds1302_read_time(&time);
        sprintf(buf, "Date: %02d-%02d-%02d", time.year, time.month, time.day);
        lcd1602_write_character(0, 0, buf);
        sprintf(buf, "TIME: %02d:%02d:%02d", time.hour, time.minute, time.second);
        lcd1602_write_character(0, 1, buf);
    }
}