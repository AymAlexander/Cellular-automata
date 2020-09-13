#ifndef __OLED_H
#define __OLED_H

#include "STC8.h"		  	 
 
#define  u8 unsigned char 
#define  u16 unsigned int
#define  u32 unsigned int
	
#define OLED_CMD  0	//写命令
#define OLED_DATA 1	//写数据

//OLED控制用函数
void delay_ms(unsigned int ms);
void OLED_WR_Byte(u8 dat,u8 cmd);
void OLED_ColorTurn(u8 i);
void OLED_DisplayTurn(u8 i);
void OLED_Set_Pos(u8 x, u8 y);
void OLED_Display_On(void);
void OLED_Display_Off(void);
void OLED_Clear(void);
void OLED_Init(void);
void OLED_print(u8 *p);

#endif  