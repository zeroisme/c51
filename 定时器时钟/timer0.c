#include <8052.h>

void timer0_init(void) {
    TMOD = TMOD & 0xf0;
    TMOD = TMOD | 0x01;

    // 65535
    TH0 = 0xFC;
    TL0 = 0x18;

    TR0 = 1;
    ET0 = 1;
    EA = 1;
}