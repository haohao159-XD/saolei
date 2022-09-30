#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable:4996)
#include <stdio.h>
#include "io.h"
#include <Windows.h>
void menu_1()
{
	printf("********************************\n");
	printf("*****      1.start        ******\n");
	printf("*****      2.exit         ******\n");
	printf("********************************\n");
}
void DisplayQipan(struct avcc* qipan)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	printf("---------------------扫雷游戏--------------------\n");
	for (int i1 = 0; i1 < ROW+1; i1++)
	{
		for (int i2 = 0; i2 < COL+1; i2++)
		{
			if (i1 == 0)
			{
				printf("%d ", i2);
			}
			else
			{
				if (i2 == 0)
				{
					printf("%d ", i1);
				}
				else
				{
					printf("%c ",qipan->show[i1][i2]);//这里为什么要用i1和i2呢
					//且听我慢慢道来
					//主循环用的是ROW+1,和COL+1
					//也就是打印坐标系+棋盘
					//这里原本qipan的show二维数组里,四周都有空位的
					//所以刚刚好,主循环i1和i2的0时,用来打印了坐标系
					//是1的时候就刚刚好用来打印棋盘,(变相跳过了棋盘四周qwq)

				}

			}
		}
		printf("\n");
	}
	printf("---------------------扫雷游戏--------------------\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);

}

void initializeQIPAN(struct avcc* qipan)
{
	int count1 = 0;
	for (int i1 = 0; i1 < ROWS; i1++)
	{
		for (int i2 = 0; i2 < COLS; i2++)
		{
			if (i1 < 10 && i1>0 && i2 < 10 && i2>0) //只初始化9*9中间的雷
			{
				qipan->show[i1][i2] = '*';//

				count1++;
			}
			qipan->boom[i1][i2] = 0;
		}
	}
	//printf("count1=%d\n", count1);
}
void playIO(struct avcc* qipan)
{
	puts("快点扫雷吧qwq:(请输入x,y坐标值,左边X轴,上分Y轴)");
	int x, y,mode;
	do
	{
		scanf("%d%d", &x, &y);
		if (qipan->show[x][y] != '*')
		{
			printf("此位置已被占用.请重新输入:(请输入x,y坐标值)");
			mode = 1;
			break;
		}
		else if (x<1 || x>ROW || y<1 || y>COL)
		{
			printf("此位置已被占用.请重新输入:(请输入x,y坐标值)");
			mode = 1;
			break;
		}
		else 
		{
			qipan->show[x][y] = 'F';
			system("cls");
			DisplayQipan(qipan);
			mode = 1;
		}
	} while (mode);

}