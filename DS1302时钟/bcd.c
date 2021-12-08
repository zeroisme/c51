#include <stdint.h>

uint8_t bcd_encode(uint8_t decimal) {
    uint8_t tens, ones;
    tens = decimal / 10;
    ones = decimal % 10;

    return (tens * 16) + ones;
}

uint8_t bcd_decode(uint8_t bcd_dat) {
    uint8_t tens, ones;
    tens = bcd_dat / 16;
    ones = bcd_dat % 16;

    return (tens * 10) + ones;
}