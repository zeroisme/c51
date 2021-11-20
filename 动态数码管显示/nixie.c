#include <8052.h>
#include "delay.h"
#define LED_NUM 8
										                                                                   
unsigned char NIXIE_TABLE[] = {
    // 0    1     2     3      4    5     6     7
    0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 
	// 8    9     A     B     C     D     E    F    
	0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71, 
    // empty
    0x00
};

void nixie(unsigned char led_number, unsigned char number) {
    // 最右边为第1个led数码显示管，最左边是最后一个数码显示管
    // 从左到右显示
    led_number = LED_NUM - led_number;

    // 选择led数码管
    P2_4 = (led_number >> 2) & 0x01;
    P2_3 = (led_number >> 1) & 0x01;
    P2_2 = led_number & 0x01;

    // 显示数字
    P0 = NIXIE_TABLE[number];
    // 消隐
    delay(1);
}