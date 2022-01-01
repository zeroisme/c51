#include <8052.h>
#include "timer0.h"
#include "delay.h"

__sbit __at (0xA5) BEEP;
#define S 100
#define P 0
#define L1 1
#define L1U 2
#define L2 3
#define L2U 4
#define L3 5
#define L4 6
#define L4U 7
#define L5 8
#define L5U 9
#define L6 10
#define L6U 11
#define L7 12
#define M1 13
#define M1U 13
#define M2 15
#define M2U 16
#define M3 17
#define M4 18
#define M4U 19
#define M5 20
#define M5U 21
#define M6 22
#define M6U 23
#define M7 24
#define H1 25
#define H1U 26
#define H2 27
#define H2U 28
#define H3 29
#define H4 30
#define H4U 31
#define H5 32
#define H5U 33
#define H6 34
#define H6U 35
#define H7 36

unsigned int TIMER_RELOAD[] = {
    0,
    63465,63577,63691,63792,63892,63981,64070,64152,64229,64303,64372,64438,
    64499,64557,64612,64664,64713,64759,64803,64844,64883,64919,64954,64987,
    65017,65047,65074,65100,65124,65148,65169,65190,65209,65228,65245,65261,

};

// 小星星
// __code unsigned char MUSIC[] = {
//     M1, 4,
//     M1, 4,
//     M5, 4,
//     M5, 4,

//     M6, 4,
//     M6, 4,
//     M5, 4+4,

//     M4, 4,
//     M4, 4,
//     M3, 4,
//     M3, 4,
    
//     M2, 4,
//     M2, 4,
//     M1, 4+4,

//     M5, 4,
//     M5, 4,
//     M4, 4,
//     M4, 4,

//     M3, 4,
//     M3, 4,
//     M2, 4+4,

//     M5, 4,
//     M5, 4,
//     M4, 4,
//     M4, 4,

//     M3, 4,
//     M3, 4,
//     M2, 4+4,

//     M1, 4,
//     M1, 4,
//     M5, 4,
//     M5, 4,

//     M6, 4,
//     M6, 4,
//     M5, 4+4,

//     M4, 4,
//     M4, 4,
//     M3, 4,
//     M3, 4,

//     M2, 4,
//     M2, 4,
//     M1, 4+4,
// };

// 月亮代表我的心
__code unsigned char MUSIC[] = {
    M3, 2,
    M4, 2,
    M5, 4+4,
    M6, 4,

    M3, 2,
    M2, 2,
    M1, 4+4+4,

    M4, 2,
    M5, 2,
    M6, 4 + 4,
    H1, 1,
    M7, 1,
    M6, 2,

    M5, 4+4+4,
    L5, 4,

    M1, 4+2,
    M3, 2,
    M5, 4+2,
    M1, 2,

    L7, 4+2,
    M3, 2,
    M5, 4,
    P, 2,
    M5, 2,

    M6, 4+2,
    M7, 2,
    H1, 4+2,
    M6, 2,

    M5, 4+4+4,
    M3, 2,
    M2, 2,

    M1, 4+2,
    M1, 2,
    M1, 4,
    M3, 2,
    M2, 2,

    M1, 4+2,
    M1, 2,
    M1, 4,
    M2, 2,
    M3, 2,

    M2, 4+2,
    M1, 2,
    L6, 4,
    M3, 4,

    M2, 4+4+4,
    L5, 4,

    M2, 4+2,
    L6, 2,
    L7, 4,
    M1, 2,
    M2, 2,

    M1, 4+4+4,
    M5, 4,

    M3, 4+2,
    M2, 2,
    M1, 4,
    M5, 4,

    L7, 4+4+4,
    L6, 2,
    L7, 2,

    L6, 4+2,
    L7, 2,
    L6, 4,
    L5, 4,

    M3, 4+4+4,
    M5, 4,

    M3, 4+2,
    M2, 2,
    M1, 4,
    M5, 4,

    L7, 4+4+4,
    L6, 2,
    L7, 2,

    M1, 4+2,
    M1, 2,
    M1, 4,
    M2, 2,
    M3, 2,

    M2, 4+4+4,
    M5, 4,

    M2, 4+2,
    L6, 2,
    L7, 4+2,
    M1, 1,
    M2, 1,

    M1, 4+4+4+4,

    M2, 4+2,
    L6, 2,
    L7, 4+2,
    M1, 1,
    M2, 1,

    M1, 4+4+4,
    M3, 2,
    M2, 2,
    
    M1, 4+2,
    M1, 2,
    M1, 4,
    M3, 2,
    M2, 2,

    M1, 4+2,
    M1, 2,
    M1, 4,
    M2, 2,
    M3, 2,

    M2, 4+2,
    L6, 2,
    L7, 4,
    M1, 2,
    M2, 2,

    M1, 4+4+4+4,


};

unsigned char music_select = 0;
unsigned char timer_reload = 0;
void main() {
    timer0_init();
    while(1) {
        if (music_select < sizeof(MUSIC)) {
            timer_reload = MUSIC[music_select];
            music_select ++;
            unsigned char t = MUSIC[music_select++];
            delay(S/4 * t);
            TR0 = 0;
            delay(1);
            TR0 = 1;
        } else {
            TR0 = 0;
            while(1) {};
        }
    }
}

void timer0_routine() __interrupt 1 {
    if (timer_reload != 0) {
        TH0 = (TIMER_RELOAD[timer_reload] >> 8) & 0xFF;
        TL0 = TIMER_RELOAD[timer_reload] & 0xFF;
        // 1ms
        BEEP = !BEEP;
    }
}