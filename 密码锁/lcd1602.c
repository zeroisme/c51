#include <8052.h>

__sbit __at (0xA6) lcd1602_rs ;
__sbit __at (0xA5) lcd1602_rw ;
__sbit __at (0xA7) lcd1602_e ;
__sfr __at (0x80) lcd1602_sent_dat;

#define lcd1602_dat lcd1602_rs=1;
#define lcd1602_com lcd1602_rs=0;
#define lcd1602_write lcd1602_rw=0;
#define lcd1602_read lcd1602_rw=1;
#define lcd1602_e_able lcd1602_e=1;
#define lcd1602_e_unable lcd1602_e=0;

#define _nop_() __asm NOP __endasm

void delay80us() {
    unsigned char i;

    _nop_();
    i = 37;
    while (--i);
}

void lcd1602_write_dat(unsigned char dat) {
    lcd1602_sent_dat = dat;
    lcd1602_dat;
    lcd1602_write;

    // delay
    delay80us();
    lcd1602_e_able;
    delay80us();

    lcd1602_e_unable;
    delay80us();
}

void lcd1602_write_com(unsigned char com) {
    lcd1602_sent_dat = com;
    lcd1602_com;
    lcd1602_write;
    delay80us();
    lcd1602_e_able;
    delay80us();
    lcd1602_e_unable;
    delay80us();
}

void lcd1602_init(void) {
    delay80us();
    lcd1602_write_com(0x38); // 设置8位格式， 2行， 5x7
    lcd1602_write_com(0x0c); // 整体显示，关光标，不闪烁
    lcd1602_write_com(0x06); // 设定输入方式，增量不移位
    lcd1602_write_com(0x01); // 清除屏幕显示
    lcd1602_write_com(0x02); // 光标归位
}

// 显示字符串
// y 指定显示行 0 - 第一行， 其它 第二行
// x 指定显示列 0 - 第一列，依次类推
void lcd1602_write_character(unsigned char x, unsigned char y, unsigned char *p) {
    unsigned char address;
    if (y == 0) {
        address = 0x80 + x;
    } else {
        address = 0xc0 + x;
    }
    lcd1602_write_com(address);
    while (*p != '\0') {
        lcd1602_write_dat(*p++);
    }
}
