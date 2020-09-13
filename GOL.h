#ifndef INC_GOL_H_
#define INC_GOL_H_

#include <painting.h>
//#include <painting_g.h>

#define u8 unsigned char
#define u16 unsigned int
//·¶Î§ÏŞÖÆ
u8 limit_x(u8 x)
{
	if(x>128)
		return 127;
	else if(x==128)
		return 0;
	else
		return x;
}
u8 limit_y(u8 y)
{
	if(y>64)
		return 63;
	else if(y==64)
		return 0;
	else
		return y;
}
//¼ìË÷ÖÜÎ§Ò»È¦
u8 around(u8 *p,u8 x,y) reentrant
{
	u8 num=0;
	if(x==0||x==127||y==0||y==63)
	{
		if(	dudian(p,	limit_x(x-1)	,	limit_y(y-1)	)	)num++;
		if(	dudian(p,	limit_x(x-1)	,	y				)	)num++;
		if(	dudian(p,	limit_x(x-1)	,	limit_y(y+1)	)	)num++;
		if(	dudian(p,	x				,	limit_y(y-1)	)	)num++;
		if(	dudian(p,	x				,	limit_y(y+1)	)	)num++;
		if(	dudian(p,	limit_x(x+1)	,	limit_y(y-1)	)	)num++;
		if(	dudian(p,	limit_x(x+1)	,	y				)	)num++;
		if(	dudian(p,	limit_x(x+1)	,	limit_y(y+1)	)	)num++;
		return p;
	}
	else
	{
		if(	dudian(p,	x-1	,y-1)	)num++;
		if(	dudian(p,	x-1	,y)		)num++;
		if(	dudian(p,	x-1	,y+1)	)num++;
		if(	dudian(p,	x	,y-1)	)num++;
		if(	dudian(p,	x	,y+1)	)num++;
		if(	dudian(p,	x+1	,y-1)	)num++;
		if(	dudian(p,	x+1	,y	)	)num++;
		if(	dudian(p,	x+1	,y+1)	)num++;
	}
	return num;
}

void GOL(u8 *p,u8 *q) reentrant
{
	u8 x,y;
	full(q,0);
	for(x=0;x<128;x++)
	{
		for(y=0;y<64;y++)
		{
			switch(around(p,x,y))
			{
			case 2:
				if(dudian(p,x,y))
					dian(q,x,y);
				break;
			case 3:
				dian(q,x,y);
				break;
			default:
				break;
			}
		}
	}
}


#endif 