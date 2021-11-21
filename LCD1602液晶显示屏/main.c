#include <8052.h>
#include "lcd1602.h"

void main(void) {
    lcd1602_init();
    lcd1602_write_character(0, 0, "Hello C51!");
    lcd1602_write_character(2, 1, "Write by zero!");
    while(1);
}