#include <8052.h>

// 串口参数初始化，4800bps@11.0592MHz
void uart_init(void) {
    PCON &= 0x7F;
    SCON = 0x50;
    TMOD &= 0x0F;
    TMOD |= 0x20;
    TL1 = 0xFA;
    TH1 = 0xFA;
    ET1 = 0;
    TR1 = 1;
    EA = 1;
    ES = 1;
}

// 通过串口发送一个字节的数据
void uart_send_byte(unsigned char byte) {
    SBUF = byte;
    while (TI == 0);
    TI = 0;
}

