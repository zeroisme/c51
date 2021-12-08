#include <8052.h>
#include <stdio.h>
#include "lcd1602.h"
#include "ds1302.h"

void main(void) {
    lcd1602_init();
    ds1302_init();
    ds1302_disable_wp();
    ds1302_write_seconds(3);
    lcd1602_write_character(0, 0, "RTC: ");
    char buf[20];
    
    while(1) {
        sprintf(buf, "%02d", ds1302_read_seconds());
        lcd1602_write_character(0, 1, buf);
    }
}