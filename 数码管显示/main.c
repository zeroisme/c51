#include <8052.h>
#include "nixie.h"
#include "delay.h"

void main() {
    nixie(1, 1);
    delay(100);
    nixie(2, 2);
    delay(100);
    nixie(3, 3);
    delay(100);
    nixie(4, 4);
    delay(100);
    nixie(5, 5);
    delay(100);
    nixie(6, 6);
    delay(100);
    nixie(7, 7);
    delay(100);
    nixie(8, 8);
    while(1);
}