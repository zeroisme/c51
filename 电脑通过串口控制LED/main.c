#include <8052.h>
#include "delay.h"
#include "uart.h"

void main(void) {
    uart_init();
    unsigned char data = 0;

    while (1) {
    }
}

void uart_routine() __interrupt 4 {
    // 处理接收中断
    if (RI == 1) {
        P2 = SBUF;
        uart_send_byte(SBUF);
        RI = 0;
    }
}