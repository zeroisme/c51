#include <8052.h>
#include "timer0.h"
#include "lcd1602.h"
#include <stdio.h>

unsigned char sec = 55, min=59, hour=23;

void main(void) {
    unsigned char key;

    timer0_init();
    lcd1602_init();

    P2 = 0xFE;
    lcd1602_write_character(0, 0, "Clock: ");
    while(1) {
        char buf[10];
        sprintf(buf, "%02d:%02d:%02d", hour, min, sec);
        lcd1602_write_character(0, 1, buf);
    };
}

void timer0_routine() __interrupt 1 {
    static unsigned count = 0;
    count++;
    TH0 = 0xFC;
    TL0 = 0x18;
    // 1ms
    if (count >= 1000) {
        count = 0;
        sec++;
        if (sec >= 60) {
            sec = 0;
            min++;
            if(min >= 60) {
                min = 0;
                hour++;
                if (hour >=24) {
                    hour = 0;
                }
            }
        }
    }
}