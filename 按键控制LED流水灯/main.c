#include <8052.h>
#include "key.h"
#include "timer0.h"

unsigned char led_mod = 0;

void main(void) {
    unsigned char key;

    timer0_init();

    P2 = 0xFE;
    
    while(1) {
        key = key_pressed();
        if (key == 1) {
            led_mod++;
            led_mod %= 2;
        }
    };
}

void timer0_routine() __interrupt 1 {
    static unsigned count = 0;
    count++;
    TH0 = 0xFC;
    TL0 = 0x18;
    // 1ms
    if (count >= 500) {
        count = 0;
        if (led_mod == 0) {
            unsigned char left_bit = (P2 >> 7) & 0x01;
            P2 = (P2 << 1) | left_bit;
        } else {
            unsigned char right_bit = (P2 & 0x01) << 7;
            P2 = right_bit | (P2 >> 1);
        }
    }
}