#ifndef __I2C_H__
#define __I2C_H__

#include "STC8.H"
#include "intrins.h"

sbit SDA = P1^4;
sbit SCL = P1^5;

void Wait();
void Start();
void SendData(char dat);
void RecvACK();
char RecvData();
void SendACK();
void SendNAK();
void Stop();
void I2Cinit();

#endif