#ifndef __I2C_H__
#define __I2C_H__
void i2c_start(void);
void i2c_stop(void);
void i2c_write_byte(unsigned char dat);
void i2c_ack(void);
void i2c_nack(void);
unsigned char i2c_wait_ack(void);
unsigned char i2c_read_byte(unsigned char ack);
#endif