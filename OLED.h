#ifndef __OLED_H
#define __OLED_H

#include "STC8.h"		  	 
 
#define  u8 unsigned char 
#define  u16 unsigned int
#define  u32 unsigned int
	
#define OLED_CMD  0	//д����
#define OLED_DATA 1	//д����

//OLED�����ú���
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