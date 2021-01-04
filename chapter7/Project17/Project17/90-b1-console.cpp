/*1553449 3班 王志业*/
#define _CRT_SECURE_NO_WARNINGS
#include "90-b1.h"
//draw the color balls without fenge line
void draw2(ball inside_array[][9], int row, int line)
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	setconsoleborder(hout, 35, row + 6, row + 6);
	setfontsize(hout, L"新宋体", 20);
	setcursor(hout, CURSOR_INVISIBLE);
	cout << "屏幕：" << row + 6 << "行" << 35 << "列" << endl;


	showstr(hout, 0, 1, "┍", COLOR_HWHITE, COLOR_BLACK);
	for (int i = 0; i < line; i++)
		showstr(hout, i * 2 + 2, 1, "─", COLOR_HWHITE, COLOR_BLACK);
	showstr(hout, 2 * line + 2, 1, "┑", COLOR_HWHITE, COLOR_BLACK);

	for (int j = 0; j < row; j++)
	{
		showstr(hout, 0, 2 + j, "┃", COLOR_HWHITE, COLOR_BLACK);
		showstr(hout, 2 * (line + 1), 2 + j, "┃", COLOR_HWHITE, COLOR_BLACK);
	}


	showstr(hout, 0, row + 2, "┕", COLOR_HWHITE, COLOR_BLACK);
	for (int i = 0; i < line; i++)
		showstr(hout, 2 * i + 2, row + 2, "─", COLOR_HWHITE, COLOR_BLACK);
	showstr(hout, 2 * (line + 1), row + 2, "┙", COLOR_HWHITE, COLOR_BLACK);




	for (int i = 0; i < row; i++)
		for (int j = 0; j < line; j++)
		{
			showstr(hout, 2 * (j + 1), i + 2, "○", inside_array[i][j].cor, COLOR_HWHITE);
			Sleep(50);
		}

	setcursor(hout, CURSOR_VISIBLE_NORMAL);
	setcolor(hout, COLOR_BLACK, COLOR_WHITE);
	gotoxy(hout, 0, row + 3);
}
//draw the color balls with fenge line
void draw3(ball inside_array[][9], int row, int line)
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	setfontsize(hout, L"新宋体", 20);
	gotoxy(hout, 0, 0);
	setcolor(hout, COLOR_BLACK, COLOR_WHITE);
	cout << "屏幕：" << row * 2 + 5 << "行" << line * 2 + 21 << "列" << endl;

	showstr(hout, 0, 1, "┍", COLOR_HWHITE, COLOR_BLACK);
	for (int i = 0; i < line - 1; i++)
		showstr(hout, 4 * i + 2, 1, "─┯", COLOR_HWHITE, COLOR_BLACK);
	showstr(hout, 4 * line - 2, 1, "─┑", COLOR_HWHITE, COLOR_BLACK);

	for (int i = 0; i < row - 1; i++)
	{
		showstr(hout, 0, i * 2 + 2, "┃", COLOR_HWHITE, COLOR_BLACK);
		for (int j = 0; j < line - 1; j++)
			showstr(hout, 4 * j + 2, i * 2 + 2, "  ┃", COLOR_HWHITE, COLOR_BLACK);
		showstr(hout, 4 * line - 2, i * 2 + 2, "  ┃", COLOR_HWHITE, COLOR_BLACK);

		showstr(hout, 0, i * 2 + 3, "┝", COLOR_HWHITE, COLOR_BLACK);
		for (int j = 0; j < line - 1; j++)
			showstr(hout, 4 * j + 2, i * 2 + 3, "─┿", COLOR_HWHITE, COLOR_BLACK);
		showstr(hout, 4 * line - 2, i * 2 + 3, "─┥", COLOR_HWHITE, COLOR_BLACK);
	}


	showstr(hout, 0, 2 * row, "┃", COLOR_HWHITE, COLOR_BLACK);
	for (int j = 0; j < line - 1; j++)
		showstr(hout, 4 * j + 2, row * 2, "  ┃", COLOR_HWHITE, COLOR_BLACK);
	showstr(hout, 4 * line - 2, row * 2, "  ┃", COLOR_HWHITE, COLOR_BLACK);

	showstr(hout, 0, 2 * row + 1, "┕", COLOR_HWHITE, COLOR_BLACK);
	for (int j = 0; j < line - 1; j++)
		showstr(hout, 4 * j + 2, row * 2 + 1, "─┷", COLOR_HWHITE, COLOR_BLACK);
	showstr(hout, 4 * line - 2, row * 2 + 1, "─┙", COLOR_HWHITE, COLOR_BLACK);



	for (int i = 0; i < row; i++)
		for (int j = 0; j < line; j++)
			showstr(hout, 2 + j * 4, (i + 1) * 2, "○", inside_array[i][j].cor, COLOR_HWHITE);


	setcolor(hout, COLOR_BLACK, COLOR_WHITE);
	gotoxy(hout, 0, row * 2 + 2);

}
//可消除小球标明
void draw4(ball inside_array[][9], int row, int line)
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int flag = 0;
	system("cls");
	setfontsize(hout, L"新宋体", 20);
	gotoxy(hout, 0, 0);
	setcolor(hout, COLOR_BLACK, COLOR_WHITE);
	cout << "屏幕：" << row * 2 + 5 << "行" << line * 2 + 21 << "列" << endl;

	showstr(hout, 0, 1, "┍", COLOR_HWHITE, COLOR_BLACK);
	for (int i = 0; i < line - 1; i++)
		showstr(hout, 4 * i + 2, 1, "─┯", COLOR_HWHITE, COLOR_BLACK);
	showstr(hout, 4 * line - 2, 1, "─┑", COLOR_HWHITE, COLOR_BLACK);

	for (int i = 0; i < row - 1; i++)
	{
		showstr(hout, 0, i * 2 + 2, "┃", COLOR_HWHITE, COLOR_BLACK);
		for (int j = 0; j < line - 1; j++)
			showstr(hout, 4 * j + 2, i * 2 + 2, "  ┃", COLOR_HWHITE, COLOR_BLACK);
		showstr(hout, 4 * line - 2, i * 2 + 2, "  ┃", COLOR_HWHITE, COLOR_BLACK);

		showstr(hout, 0, i * 2 + 3, "┝", COLOR_HWHITE, COLOR_BLACK);
		for (int j = 0; j < line - 1; j++)
			showstr(hout, 4 * j + 2, i * 2 + 3, "─┿", COLOR_HWHITE, COLOR_BLACK);
		showstr(hout, 4 * line - 2, i * 2 + 3, "─┥", COLOR_HWHITE, COLOR_BLACK);
	}


	showstr(hout, 0, 2 * row, "┃", COLOR_HWHITE, COLOR_BLACK);
	for (int j = 0; j < line - 1; j++)
		showstr(hout, 4 * j + 2, row * 2, "  ┃", COLOR_HWHITE, COLOR_BLACK);
	showstr(hout, 4 * line - 2, row * 2, "  ┃", COLOR_HWHITE, COLOR_BLACK);

	showstr(hout, 0, 2 * row + 1, "┕", COLOR_HWHITE, COLOR_BLACK);
	for (int j = 0; j < line - 1; j++)
		showstr(hout, 4 * j + 2, row * 2 + 1, "─┷", COLOR_HWHITE, COLOR_BLACK);
	showstr(hout, 4 * line - 2, row * 2 + 1, "─┙", COLOR_HWHITE, COLOR_BLACK);



	for (int i = 0; i < row; i++)
		for (int j = 0; j < line; j++)
		{
			if (inside_array[i][j].dis>0)
			{
				showstr(hout, 2 + j * 4, (i + 1) * 2, "●", inside_array[i][j].cor, COLOR_BLACK);
				flag = 1;
			}
			else
				showstr(hout, 2 + j * 4, (i + 1) * 2, "○", inside_array[i][j].cor, COLOR_HWHITE);
		}
	if (flag == 0)
	{
		gotoxy(hout, 16, 0);
		setcolor(hout, COLOR_BLACK, COLOR_WHITE);
		cout << "未找到初始可消除项";
		return;
	}
	setcolor(hout, COLOR_BLACK, COLOR_WHITE);
	gotoxy(hout, 0, row * 2 + 2);

}
//消除并附加动画
void dis_act(ball inside_array[][9], int row, int line)
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int i, j;
	for (i = 0; i < row; i++)
		for (j = 0; j < line; j++)
		{
			if (inside_array[i][j].dis>0)
			{
				showstr(hout, 2 + j * 4, (i + 1) * 2, "  ", COLOR_HWHITE, COLOR_HWHITE);
				Sleep(50);//延时0.05秒
				showstr(hout, 2 + j * 4, (i + 1) * 2, "¤", inside_array[i][j].cor, COLOR_HWHITE);
				Sleep(50);
				showstr(hout, 2 + j * 4, (i + 1) * 2, "  ", COLOR_HWHITE, COLOR_HWHITE);
			}
		}
	setcolor(hout, COLOR_BLACK, COLOR_WHITE);
	gotoxy(hout, 0, row * 2 + 2);

}
//落下并填补附加动画
void down_reload(ball inside_array[][9], int row, int line)
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	srand((unsigned int)time(0));
	int i, j;
	for (i = row - 1; i >= 0; i--)
		for (j = line - 1; j >= 0; j--)
			if (inside_array[i][j].cor == 0)
				up_down(inside_array, i, j, i);
	for (i = 0; i < row; i++)
		for (j = 0; j < line; j++)
		{
			if (inside_array[i][j].cor == 0)
			{
				inside_array[i][j].cor = rand() % 9 + 1;
				showstr(hout, 2 + j * 4, (i + 1) * 2, "○", inside_array[i][j].cor, COLOR_HWHITE);
				Sleep(100);
			}
		}
	setcolor(hout, COLOR_BLACK, COLOR_WHITE);
	gotoxy(hout, 0, row * 2 + 2);
}
//标出可移动的球,若不可移动则变回普通形状
void mark_ball(ball inside_array[][9], int row, int line)
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < line; j++)
		{
			if (inside_array[i][j].cha>0)
				showstr(hout, 2 + j * 4, (i + 1) * 2, "◎", inside_array[i][j].cor, COLOR_HWHITE);
			else
				showstr(hout, 2 + j * 4, (i + 1) * 2, "○", inside_array[i][j].cor, COLOR_HWHITE);
		}
	}
	setcolor(hout, COLOR_BLACK, COLOR_WHITE);
	gotoxy(hout, 0, row * 2 + 2);
}
//交换两球的位置并出现动画
void ball_change(ball inside_array[][9], int x, int y, int ex, int ey)
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int temp;
	showstr(hout, 4 * x + 2, 2 * y + 2, "  ", COLOR_HWHITE, COLOR_HWHITE);
	showstr(hout, 4 * ex + 2, 2 * ey + 2, "  ", COLOR_HWHITE, COLOR_HWHITE);
	Sleep(500);
	showstr(hout, 4 * x + 2 + 2 * (ex - x), 2 * y + 2 + ey - y, "○", inside_array[y][x].cor, COLOR_HWHITE);
	Sleep(500);
	temp = inside_array[y][x].cor;
	inside_array[y][x].cor = inside_array[ey][ex].cor;
	inside_array[ey][ex].cor = temp;
	if (x - ex != 0)
		showstr(hout, 4 * x + 2 + 2 * (ex - x), 2 * y + 2 + ey - y, "┃", COLOR_HWHITE, COLOR_BLACK);
	if (y - ey != 0)
		showstr(hout, 4 * x + 2 + 2 * (ex - x), 2 * y + 2 + ey - y, "─", COLOR_HWHITE, COLOR_BLACK);
	showstr(hout, 4 * x + 2, 2 * y + 2, "○", inside_array[y][x].cor, COLOR_HWHITE);
	showstr(hout, 4 * ex + 2, 2 * ey + 2, "○", inside_array[ey][ex].cor, COLOR_HWHITE);

}