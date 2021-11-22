#include <8052.h>
#include "lcd1602.h"
#include <stdlib.h>
#include <string.h>
#include "matrix_key.h"
#include "delay.h"

#define PASSWORD "5697"
#define PASSWORDLEN 4
#define CONFORM 10

void main(void) {
    unsigned char key;
    unsigned char buf[5];
    buf[4] = '\0';
    lcd1602_init();
    unsigned char index = 0;
    while(1) {
        lcd1602_write_character(0, 0, "password: ");
        key = matrix_key();
        if (key != 0) {
            // 密码区 1-9
            if (key >= 1 && key <= 9) {
                if (index < PASSWORDLEN) {
                    buf[index++] = '0' + key;
                }
            }

            if (key == CONFORM) {
                if (strcmp(buf, PASSWORD) == 0) {
                    lcd1602_write_character(0, 1, "OK    ");
                } else {
                    lcd1602_write_character(0, 1, "ERROR!");
                }
                delay(200);
                index = 0;
                buf[0] = '\0';
                buf[1] = '\0';
                buf[2] = '\0';
                buf[3] = '\0';
                // clear
                lcd1602_write_character(0, 1, "          ");
            }
        } 
        lcd1602_write_character(0, 1, buf);
    }
}