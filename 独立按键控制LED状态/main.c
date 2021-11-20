#include <8052.h>
#include "delay.h"

void main() {
    unsigned char index = 0;
    while(1) {
        if (P3_1 == 0) {
            // delay 消抖
            delay(20);
            while (P3_1 == 0);
            delay(20);
            // keil 使用 ~P2_0, sdcc 使用~P2_0(类型提升？)
            P2_0 = !P2_0;
        }
    }
}