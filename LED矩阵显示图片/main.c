#include <8052.h>
#include "matrix_led.h"

void main(void) {
    matrix_led_init();
    while (1) {
        matrix_led_display_column(0, 0b00111100);
        matrix_led_display_column(1, 0b01000010);
        matrix_led_display_column(2, 0b10100101);
        matrix_led_display_column(3, 0b10000001);
        matrix_led_display_column(4, 0b10100101);
        matrix_led_display_column(5, 0b10011001);
        matrix_led_display_column(6, 0b01000010);
        matrix_led_display_column(7, 0b00111100);
    }
}