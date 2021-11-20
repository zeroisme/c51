#include <8052.h>

void main() {
    while(1) {
        if (P3_1) {
            P2_0 = 1;
        } else {
            P2_0 = 0;
        }
    }
}