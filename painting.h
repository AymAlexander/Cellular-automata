#ifndef _painting_h
#define _painting_h

#include <REG51.H>
#include <math.h>

#define u8 unsigned char
#define u16 unsigned int 
	
u8 xdata cache[8][128];//����
u8 xdata cache_g[8][128];
//**************************************************�Դ����
void full(u8 *p,u8 a) reentrant//u8���͵�ָ��p��ָ��cache���׵�ַ
{
    u8 i,j;
	for(i=0;i<8;i++)
        for(j=0;j<128;j++)
            *p++=a;
}
//**************************************************��
void dian(u8 *p,u8 x,y) reentrant
{
	u8 i;
	for(i=(7-(y>>3));i>0;i--)//��ν����3λ����Ϊ�˻����ҳ
	//for(i=(y>>3);i>0;i--)
	{
		p+=128;//ȷ���ڵڼ�ҳ
	}
	*(p+x)|=128>>(y&7);//y&7��Ϊ��ȷ���ǵڼ�����
}
bit dudian(u8 *p,u8 x,y) reentrant
{
	u8 i;
	for(i=(7-(y>>3));i>0;i--)
	//for(i=(y>>3);i>0;i--)
	{
		p+=128;
	}
	if(*(p+x)&(128>>(y&7)))
		return 1;
	else
		return 0;
}

#endif