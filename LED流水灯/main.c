#include <8052.h>
#include "delay.h"

void main() {
    unsigned char index = 0;
    while(1) {
        P2 = ~(1 << index);
        index = (index + 1) % 8;
        delay(10);
    }
}