#include <8052.h>
#include "delay.h"
#include "uart.h"

void main(void) {
    uart_init();
    unsigned char data = 0;

    while (1) {
        uart_send_byte(data);
        data++;
        delay(200);
    }
}
