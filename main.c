#include "STC8.h"
#include "oled.h"
#include "painting.h"       
#include "GOL.h"   

int main(void)
{	
	I2Cinit();
	OLED_Init();//��ʼ��OLED
	OLED_ColorTurn(0);//0������ʾ��1 ��ɫ��ʾ
	OLED_DisplayTurn(0);//0������ʾ 1 ��Ļ��ת��ʾ
	while(1) 
	{		
			GOL(cache,cache_g);
			OLED_print(cache_g);
			GOL(cache_g,cache);
			OLED_print(cache);
	}
}