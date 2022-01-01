#include <8052.h>
#include <stdio.h>
#include "timer0.h"
#include "at24c02.h"
#include "lcd1602.h"
#include "delay.h"

void main(void) {
    // timer0_init();
    lcd1602_init();

    unsigned char dat = 0;
    unsigned char status;

    at24c02_write_byte(0, 0xA);
    delay(10);
    dat = at24c02_read_byte(0);
    char buf[5];

    sprintf(buf, "%03d", dat);
    lcd1602_write_character(0, 0, buf);

    while(1) {


    }
}