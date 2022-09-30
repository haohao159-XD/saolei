#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable:4996)
#include "game.h"
#include "io.h"
#include <stdio.h>

struct avcc QIPAN;
//char QIPAN[ROW][COL];
int main()
{
	
	menu_1();
	initializeQIPAN(&QIPAN);
	int mode;
	do
	{
		scanf("%d", &mode);
		switch (mode)
		{
		case 1:
		{
			puts("hello");
			DisplayQipan(&QIPAN);
			playIO(&QIPAN);
			break;
		}
		case 0:
		{
			break;
		}
		default:
		{
			puts("输入错误,请重新输入");
			break;
		}
		}

	} while (mode);
	return 0;
}