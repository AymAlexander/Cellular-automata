#include "STC8.h"
#include "oled.h"
#include "painting.h"       
#include "GOL.h"   

int main(void)
{	
	I2Cinit();
	OLED_Init();//初始化OLED
	OLED_ColorTurn(0);//0正常显示，1 反色显示
	OLED_DisplayTurn(0);//0正常显示 1 屏幕翻转显示
	while(1) 
	{		
			GOL(cache,cache_g);
			OLED_print(cache_g);
			GOL(cache_g,cache);
			OLED_print(cache);
	}
}