#ifndef __NIXIE_H__
#define __NIXIE_H__

// led_number: 选择显示的led数码管
// number: 显示的数字，范围 0-F, 如果什么都不显示，则number为17
void nixie(unsigned char led_number, unsigned char number);
#endif