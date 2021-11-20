#include <8052.h>
#include "nixie.h"
#include "delay.h"

void main() {
    while(1) {
        nixie(1, 1);
        nixie(2, 2);
        nixie(3, 3);
    }
}