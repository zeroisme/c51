#include <8052.h>
#include "delay.h"

void main() {
    while(1) {
        P2_0 = 0;
        delay(500);
        P2_0 = 1;
        delay(500);
    }
}