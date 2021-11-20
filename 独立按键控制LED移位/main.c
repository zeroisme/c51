#include <8052.h>
#include "delay.h"

void main() {
    unsigned char index = 0;
    while(1) {
        if (P3_1 == 0) {
            delay(20);
            while(P3_1==0);
            delay(20);
            index--;
        }

        if(P3_0 == 0) {
            delay(20);
            while(P3_0==0);
            delay(20);
            index++;
        }
        index = index % 8;
        P2 = ~(1 << index);
    }
}