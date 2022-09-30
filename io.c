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
	printf("---------------------ɨ����Ϸ--------------------\n");
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
					printf("%c ",qipan->show[i1][i2]);//����ΪʲôҪ��i1��i2��
					//��������������
					//��ѭ���õ���ROW+1,��COL+1
					//Ҳ���Ǵ�ӡ����ϵ+����
					//����ԭ��qipan��show��ά������,���ܶ��п�λ��
					//���Ըոպ�,��ѭ��i1��i2��0ʱ,������ӡ������ϵ
					//��1��ʱ��͸ոպ�������ӡ����,(������������������qwq)

				}

			}
		}
		printf("\n");
	}
	printf("---------------------ɨ����Ϸ--------------------\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);

}

void initializeQIPAN(struct avcc* qipan)
{
	int count1 = 0;
	for (int i1 = 0; i1 < ROWS; i1++)
	{
		for (int i2 = 0; i2 < COLS; i2++)
		{
			if (i1 < 10 && i1>0 && i2 < 10 && i2>0) //ֻ��ʼ��9*9�м����
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
	puts("���ɨ�װ�qwq:(������x,y����ֵ,���X��,�Ϸ�Y��)");
	int x, y,mode;
	do
	{
		scanf("%d%d", &x, &y);
		if (qipan->show[x][y] != '*')
		{
			printf("��λ���ѱ�ռ��.����������:(������x,y����ֵ)");
			mode = 1;
			break;
		}
		else if (x<1 || x>ROW || y<1 || y>COL)
		{
			printf("��λ���ѱ�ռ��.����������:(������x,y����ֵ)");
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