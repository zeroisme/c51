#include <8052.h>
#include "lcd1602.h"
#include <stdlib.h>
#include "matrix_key.h"
#include "delay.h"

void main(void) {
    unsigned char key;
    unsigned char buf[3];
    lcd1602_init();
    while(1) {
        key = matrix_key();
        if (key != 0) {
            _itoa(key, buf, 10);
            lcd1602_write_character(0, 0, buf);
            delay(100);
        } 
        lcd1602_write_character(0, 0, "  ");
    }
}