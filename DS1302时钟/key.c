#include "delay.h"
#include <8052.h>

// 返回值范围0-4，0表示无按键按下，1-4表示独立按键1-4被按下
unsigned char key_pressed() {
    unsigned char key_number = 0;
    if (P3_1 == 0) { delay(20); while(P3_1 == 0); delay(20); key_number = 1;}
    if (P3_0 == 0) { delay(20); while(P3_0 == 0); delay(20); key_number = 2;}
    if (P3_2 == 0) { delay(20); while(P3_2 == 0); delay(20); key_number = 3;}
    if (P3_3 == 0) { delay(20); while(P3_3 == 0); delay(20); key_number = 4;}
    return key_number;
}