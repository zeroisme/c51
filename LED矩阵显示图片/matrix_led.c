#include <8052.h>
#include "delay.h"

__sbit __at (0xB4) SER;
__sbit __at (0xB6) SCK;
__sbit __at (0xB5) RCK;
__sfr __at (0x80) LED_COLUMN;

void _74hc595_write_byte(unsigned char byte) {
    unsigned char i;
    for (i=0; i < 8; i++) {
        SER = byte & 0x80;
        SCK = 1;
        SCK = 0;
        byte = byte << 1;
    }
    RCK = 1;
    RCK = 0;
}

void matrix_led_init() {
    RCK = 0;
    SCK = 0;
}

void matrix_led_display_column(unsigned char column, unsigned char byte) {
    _74hc595_write_byte(byte);
    LED_COLUMN = ~(0x80 >> column);
    delay(1);
    LED_COLUMN = 0xFF;
}