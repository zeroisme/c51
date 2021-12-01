#include <8052.h>
#include "matrix_led.h"

unsigned char annimation[] = {
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0xFF,0x08,0x08,0xFF,0x00,0xFF,0x89,0x89,
    0x00,0xFF,0x01,0x01,0x00,0xFF,0x01,0x01,
    0x00,0xFF,0x81,0xFF,0x00,0x00,0x7E,0x81,
    0x81,0x00,0xF9,0x89,0x86,0x00,0xFF,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

void main(void) {
    matrix_led_init();
    unsigned char count = 0;
    unsigned char offset = 0;
    while (1) {
        unsigned char i;
        for (i = 0; i < 8; i++) {
            matrix_led_display_column(i, annimation[i + offset]);
        }
        count ++;
        if (count > 15) {
            count = 0;
            offset++;
            if (offset > sizeof(annimation) - 8) {
                offset = 0;
            }
        }
    }
}