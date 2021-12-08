#ifndef __LCD1602_H__
#define __LCD1602_H__

void lcd1602_init(void);
void lcd1602_write_character(unsigned char x, unsigned char y, unsigned char *p);
#endif