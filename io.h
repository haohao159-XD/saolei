#pragma once
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
struct avcc
{
	char show[ROWS][COLS];
	int boom[ROWS][COLS];
};
void menu_1();

void DisplayQipan(struct avcc* qipan);

void initializeQIPAN(struct avcc* qipan);

void playIO(struct avcc* qipan);
