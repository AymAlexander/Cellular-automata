#include "i2c.h"

void Wait()
{
	while(!(I2CMSST & 0x40));
	I2CMSST &= ~0x40;
}

void Start()
{
	I2CMSCR = 0x01;				//发送START命令
	Wait();
}

void SendData(char dat)
{
	I2CTXD = dat;					//写数据到数据缓存区
	I2CMSCR = 0x02;				//发送SEND命令
	Wait();
}

void RecvACK()
{
	I2CMSCR = 0x03;
	Wait();
}

char RecvData()
{
	I2CMSCR = 0x04;			//发送RECV命令
	Wait();
	return I2CRXD;
}

void SendACK()
{
	I2CMSST = 0x00;		//设置ACK信号
	I2CMSCR = 0x05;		//发送ACK命令
	Wait();
}

void SendNAK()
{
	I2CMSST = 0x01;		//设置NAK信号
	I2CMSCR = 0x05;		//发送ACK命令
	Wait();
}

void Stop()
{
	I2CMSCR = 0x06;		//发送STOP命令
	Wait();
}

void I2Cinit()
{
	P_SW2 = 0x80;
	I2CCFG = 0xe0;			//使能I2C主机模式
	I2CCFG = 0xc2;
	I2CMSST = 0x00;
}