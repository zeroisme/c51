#include <8052.h>

__sbit __at (0xA0) SDA ;
__sbit __at (0xA1) SCL ;

void delay_10us(unsigned char ten_us)
{
	while(ten_us--);
}

void i2c_start(void) {
    SCL = 1;
    SDA = 1;
    delay_10us(1);
    SDA = 0; // SCL为高电平时SDA下降沿（高到低）
    delay_10us(1);
    SCL = 0; // 准备发送或接收数据
}

void i2c_stop(void) {
    SDA = 0;
    SCL = 1;
    delay_10us(1);
    SDA = 1; // 当SCL为高电平时，SDA由低变为高
    delay_10us(1);
}

void i2c_ack(void) {
    SCL = 0;
    SDA = 0;
    delay_10us(1);
    SCL = 1;
    delay_10us(1);
    SCL = 0;
}

void i2c_nack(void) {
    SCL = 0;
    SDA = 1;
    delay_10us(1);
    SCL = 1;
    delay_10us(1);
    SCL = 0;
}

unsigned char i2c_wait_ack(void) {
    unsigned time = 0;

    SCL = 1;
    delay_10us(1);
    while(SDA) { // 等待SDA为低电平
        time ++;
        if (time > 100) { // 超时强制结束I2c通信
            i2c_stop();
            return 1;
        }
    }
    SCL = 0;
    return 0;
}

void i2c_write_byte(unsigned char dat) {
    unsigned char i;
    SCL = 0;
    for(i=0; i<8; i++) {
        if ((dat & 0x80) > 0) {
            SDA = 1;
        } else {
            SDA = 0;
        }
        dat <<= 1;
        delay_10us(1);
        SCL = 1;
        delay_10us(1);
        SCL = 0;
        delay_10us(1);
    }
}

unsigned char i2c_read_byte(unsigned char ack) {
    unsigned char i, dat = 0;
    for(i=0; i<8; i++) {
        
        SCL = 0;
        delay_10us(1);
        SCL = 1;
        dat <<= 1;
        if (SDA) dat++;
        delay_10us(1);
    }

    if (!ack) {
        i2c_nack();
    } else {
        i2c_ack();
    }
    return dat;
}