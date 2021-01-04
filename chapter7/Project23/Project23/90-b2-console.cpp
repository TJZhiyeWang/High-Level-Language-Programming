/*1553449 3班 王志业*/
#define _CRT_SECURE_NO_WARNINGS
#include "90-b2.h"
#include "cmd_console_tools.h"
//构建数独界面，已有数字标记为蓝色，0与填写的数字标记为黄色，冲突的数字标记为红色
void draw(sdk sdkarray[][9])
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int i, j, k;
	showstr(hout, 0, 0, "-", COLOR_BLACK, COLOR_HWHITE);
	char ch2[2] = { char('a' - 1) };
	char ch1[2] = { "0" };
	for (i = 0; i < 12; i++)
		for (j = 0; j < 24; j++)
		{
			if (i == 0 && (j - 1) % 8 == 0)
			{

				for (k = 1; k < 8; k++)
				{
					if (k % 2 == 0)
					{
						ch2[0]++;
						showstr(hout, j + k, i, ch2, COLOR_BLACK, COLOR_HWHITE);
					}
					else
						showstr(hout, j + k, i, "-", COLOR_BLACK, COLOR_HWHITE);
				}
			}
			if (i % 4 == 0)
			{

				if ((j - 1) % 8 == 0)
					showstr(hout, j, i, "+", COLOR_BLACK, COLOR_HWHITE);


				else if (i != 0)
					showstr(hout, j, i, "-", COLOR_BLACK, COLOR_HWHITE);

			}
			else
			{
				if ((j - 1) % 8 == 0)
					showstr(hout, j, i, "|", COLOR_BLACK, COLOR_HWHITE);
				if (j == 0)
				{

					ch1[0] += 1;
					showstr(hout, j, i, ch1, COLOR_BLACK, COLOR_HWHITE);
				}
			}
		}
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			char ch3[2] = { char(sdkarray[i][j].num + '0') };
			if (sdkarray[i][j].num != 0 && sdkarray[i][j].p == '1')
				showstr(hout, 3 + 2 * j + 2 * (j / 3), 1 + i + i / 3, ch3, COLOR_BLACK, COLOR_HBLUE);
			else
				showstr(hout, 3 + 2 * j + 2 * (j / 3), 1 + i + i / 3, ch3, COLOR_BLACK, COLOR_HYELLOW);

		}
	}
	setcolor(hout, COLOR_BLACK, COLOR_WHITE);
}
//将该位置数字变红
void turn_red(sdk sdkarray[][9], int i, int j)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	char ch3[2] = { char(sdkarray[i][j].num + '0') };
	showstr(hout, 3 + 2 * j + 2 * (j / 3), 1 + i + i / 3, ch3, COLOR_WHITE, COLOR_HRED);
	setcolor(hout, COLOR_BLACK, COLOR_WHITE);
}
//冲突区域位置背景色变白(first white than red)
void turn_white(sdk sdkarray[][9], int i, int j)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	char ch3[2] = { char(sdkarray[i][j].num + '0') };
	if (sdkarray[i][j].num != 0)
		showstr(hout, 3 + 2 * j + 2 * (j / 3), 1 + i + i / 3, ch3, COLOR_WHITE, COLOR_HBLUE);
	else
		showstr(hout, 3 + 2 * j + 2 * (j / 3), 1 + i + i / 3, ch3, COLOR_WHITE, COLOR_HYELLOW);
	setcolor(hout, COLOR_BLACK, COLOR_WHITE);
}
//伪图形界面下显示当前文件,返回选择的文件指针
char* display(char **result, const int count)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int i, j, address = 1, array_add = 0;
	int width = 0, length = 3;
	setcursor(hout, CURSOR_INVISIBLE);
	for (i = 0; i < count; i++)
		if (strlen(result[i])>unsigned(width))
			width = strlen(result[i]);
	char *s;//为空行
	s = new(nothrow) char[width + 1];
	for (i = 0; i < width; i++)
		s[i] = ' ';
	s[width] = '\0';
	showstr(hout, 10, 10, "┏", COLOR_BLACK, COLOR_HWHITE);
	for (i = 2; i <= width; i += 2)
		showstr(hout, 10 + i, 10, "━", COLOR_BLACK, COLOR_HWHITE);
	showstr(hout, 10 + i, 10, "┓", COLOR_BLACK, COLOR_HWHITE);
	for (j = 1; j <= length; j++)
		showstr(hout, 10 + i, 10 + j, "┃", COLOR_BLACK, COLOR_HWHITE);
	showstr(hout, 10 + i, 10 + j, "┛", COLOR_BLACK, COLOR_HWHITE);
	for (; i >= 1; i -= 2)
		showstr(hout, 8 + i, 10 + j, "━", COLOR_BLACK, COLOR_HWHITE);
	showstr(hout, 10, 10 + j, "┗", COLOR_BLACK, COLOR_HWHITE);
	for (; j > 1; j--)
		showstr(hout, 10, 9 + j, "┃", COLOR_BLACK, COLOR_HWHITE);
	showstr(hout, 12, 10 + address, result[array_add], COLOR_WHITE, COLOR_HWHITE);
	showstr(hout, 12, 12, result[array_add + 1], COLOR_BLACK, COLOR_HWHITE);
	showstr(hout, 12, 13, result[array_add + 2], COLOR_BLACK, COLOR_HWHITE);
	while (1)
	{
		switch (_getch())
		{
			case 13:
			{
				gotoxy(hout, 20, 20);
				setcolor(hout, COLOR_BLACK, COLOR_HWHITE);
				delete s;
				cout << result[array_add];
				return result[array_add];
			}
			continue;
			case 72://如果读取到上箭头
			{

				if (array_add > 0)
				{
					if (address > 1)
					{
						showstr(hout, 12, 10 + address, s, COLOR_BLACK, COLOR_HWHITE);
						showstr(hout, 12, 10 + address, result[array_add], COLOR_BLACK, COLOR_HWHITE);
						array_add--;
						address--;
					}
					else
					{
						array_add--;
						showstr(hout, 12, 12, s, COLOR_BLACK, COLOR_HWHITE);
						showstr(hout, 12, 13, s, COLOR_BLACK, COLOR_HWHITE);
						showstr(hout, 12, 12, result[array_add + 1], COLOR_BLACK, COLOR_HWHITE);
						showstr(hout, 12, 13, result[array_add + 2], COLOR_BLACK, COLOR_HWHITE);

					}
					showstr(hout, 12, 10 + address, s, COLOR_WHITE, COLOR_HWHITE);
					showstr(hout, 12, 10 + address, result[array_add], COLOR_WHITE, COLOR_HWHITE);


				}
			}
			continue;
			case 80://如果读取到下键头
			{
				if (array_add < count - 1)
				{

					if (address < 3)
					{
						showstr(hout, 12, 10 + address, s, COLOR_BLACK, COLOR_HWHITE);
						showstr(hout, 12, 10 + address, result[array_add], COLOR_BLACK, COLOR_HWHITE);
						array_add++;
						address++;
					}
					else
					{
						array_add++;
						showstr(hout, 12, 11, s, COLOR_BLACK, COLOR_HWHITE);
						showstr(hout, 12, 12, s, COLOR_BLACK, COLOR_HWHITE);
						showstr(hout, 12, 11, result[array_add - 2], COLOR_BLACK, COLOR_HWHITE);
						showstr(hout, 12, 12, result[array_add - 1], COLOR_BLACK, COLOR_HWHITE);
					}
					showstr(hout, 12, 10 + address, s, COLOR_WHITE, COLOR_HWHITE);
					showstr(hout, 12, 10 + address, result[array_add], COLOR_WHITE, COLOR_HWHITE);
				}
			}
			continue;
			default:
				continue;

		}
	}

}
void draw1(sdk sdkarray[][9])
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int i, j;


	setconsoleborder(hout, 6 + 6 * 10, 3 + 3 * 10);

	for (i = 0; i < 9; i++)
	{
		setcolor(hout, COLOR_BLACK, COLOR_HWHITE);
		gotoxy(hout, 2, 3 + 3 * i);
		cout << char('a' + i);
		gotoxy(hout, 6 + 6 * i, 1);
		cout << i + 1;
	}
	for (i = 0; i < 9; i++)
		for (j = 0; j < 9; j++)
		{
			if (sdkarray[i][j].p == '1')
			{
				setcolor(hout, COLOR_BLACK, COLOR_HBLUE);
				gotoxy(hout, 6 + 6 * j, 3 + 3 * i);
				cout << sdkarray[i][j].num;
				showstr(hout, 6 + 6 * j, 3 + 3 * i - 1, "═", COLOR_BLACK, COLOR_HBLUE);
				showstr(hout, 6 + 6 * j, 3 + 3 * i + 1, "═", COLOR_BLACK, COLOR_HBLUE);
				showstr(hout, 6 + 6 * j - 2, 3 + 3 * i, "║", COLOR_BLACK, COLOR_HBLUE);
				showstr(hout, 6 + 6 * j + 2, 3 + 3 * i, "║", COLOR_BLACK, COLOR_HBLUE);
				showstr(hout, 6 + 6 * j - 2, 3 + 3 * i - 1, "╔", COLOR_BLACK, COLOR_HBLUE);
				showstr(hout, 6 + 6 * j + 2, 3 + 3 * i - 1, "╗", COLOR_BLACK, COLOR_HBLUE);
				showstr(hout, 6 + 6 * j - 2, 3 + 3 * i + 1, "╚", COLOR_BLACK, COLOR_HBLUE);
				showstr(hout, 6 + 6 * j + 2, 3 + 3 * i + 1, "╝", COLOR_BLACK, COLOR_HBLUE);
			}
			if (sdkarray[i][j].p == '0')
			{
				setcolor(hout, COLOR_BLACK, COLOR_HYELLOW);
				gotoxy(hout, 6 + 6 * j, 3 + 3 * i);
				cout << sdkarray[i][j].num;
				showstr(hout, 6 + 6 * j, 3 + 3 * i - 1, "═", COLOR_BLACK, COLOR_HYELLOW);
				showstr(hout, 6 + 6 * j, 3 + 3 * i + 1, "═", COLOR_BLACK, COLOR_HYELLOW);
				showstr(hout, 6 + 6 * j - 2, 3 + 3 * i, "║", COLOR_BLACK, COLOR_HYELLOW);
				showstr(hout, 6 + 6 * j + 2, 3 + 3 * i, "║", COLOR_BLACK, COLOR_HYELLOW);
				showstr(hout, 6 + 6 * j - 2, 3 + 3 * i - 1, "╔", COLOR_BLACK, COLOR_HYELLOW);
				showstr(hout, 6 + 6 * j + 2, 3 + 3 * i - 1, "╗", COLOR_BLACK, COLOR_HYELLOW);
				showstr(hout, 6 + 6 * j - 2, 3 + 3 * i + 1, "╚", COLOR_BLACK, COLOR_HYELLOW);
				showstr(hout, 6 + 6 * j + 2, 3 + 3 * i + 1, "╝", COLOR_BLACK, COLOR_HYELLOW);
			}
		}
}
//标记出正在尝试的位置
void mark(sdk sdkarray[][9], int i, int j)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	setcolor(hout, COLOR_WHITE, COLOR_HRED);
	gotoxy(hout, 6 + 6 * j, 3 + 3 * i);
	cout << sdkarray[i][j].num << " ";
	showstr(hout, 6 + 6 * j, 3 + 3 * i - 1, "═", COLOR_WHITE, COLOR_HRED);
	showstr(hout, 6 + 6 * j, 3 + 3 * i + 1, "═", COLOR_WHITE, COLOR_HRED);
	showstr(hout, 6 + 6 * j - 2, 3 + 3 * i, "║", COLOR_WHITE, COLOR_HRED);
	showstr(hout, 6 + 6 * j + 2, 3 + 3 * i, "║", COLOR_WHITE, COLOR_HRED);
	showstr(hout, 6 + 6 * j - 2, 3 + 3 * i - 1, "╔", COLOR_WHITE, COLOR_HRED);
	showstr(hout, 6 + 6 * j + 2, 3 + 3 * i - 1, "╗", COLOR_WHITE, COLOR_HRED);
	showstr(hout, 6 + 6 * j - 2, 3 + 3 * i + 1, "╚", COLOR_WHITE, COLOR_HRED);
	showstr(hout, 6 + 6 * j + 2, 3 + 3 * i + 1, "╝", COLOR_WHITE, COLOR_HRED);
}
//将标记过正在尝试的再转回普通形态
void mark_back(sdk sdkarray[][9], int i, int j)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

	if (sdkarray[i][j].p == '1')
	{
		setcolor(hout, COLOR_BLACK, COLOR_HBLUE);
		gotoxy(hout, 6 + 6 * j, 3 + 3 * i);
		cout << sdkarray[i][j].num << " ";
		showstr(hout, 6 + 6 * j, 3 + 3 * i - 1, "═", COLOR_BLACK, COLOR_HBLUE);
		showstr(hout, 6 + 6 * j, 3 + 3 * i + 1, "═", COLOR_BLACK, COLOR_HBLUE);
		showstr(hout, 6 + 6 * j - 2, 3 + 3 * i, "║", COLOR_BLACK, COLOR_HBLUE);
		showstr(hout, 6 + 6 * j + 2, 3 + 3 * i, "║", COLOR_BLACK, COLOR_HBLUE);
		showstr(hout, 6 + 6 * j - 2, 3 + 3 * i - 1, "╔", COLOR_BLACK, COLOR_HBLUE);
		showstr(hout, 6 + 6 * j + 2, 3 + 3 * i - 1, "╗", COLOR_BLACK, COLOR_HBLUE);
		showstr(hout, 6 + 6 * j - 2, 3 + 3 * i + 1, "╚", COLOR_BLACK, COLOR_HBLUE);
		showstr(hout, 6 + 6 * j + 2, 3 + 3 * i + 1, "╝", COLOR_BLACK, COLOR_HBLUE);
	}
	if (sdkarray[i][j].p == '0')
	{
		setcolor(hout, COLOR_BLACK, COLOR_HYELLOW);
		gotoxy(hout, 6 + 6 * j, 3 + 3 * i);
		cout << sdkarray[i][j].num << " ";
		showstr(hout, 6 + 6 * j, 3 + 3 * i - 1, "═", COLOR_BLACK, COLOR_HYELLOW);
		showstr(hout, 6 + 6 * j, 3 + 3 * i + 1, "═", COLOR_BLACK, COLOR_HYELLOW);
		showstr(hout, 6 + 6 * j - 2, 3 + 3 * i, "║", COLOR_BLACK, COLOR_HYELLOW);
		showstr(hout, 6 + 6 * j + 2, 3 + 3 * i, "║", COLOR_BLACK, COLOR_HYELLOW);
		showstr(hout, 6 + 6 * j - 2, 3 + 3 * i - 1, "╔", COLOR_BLACK, COLOR_HYELLOW);
		showstr(hout, 6 + 6 * j + 2, 3 + 3 * i - 1, "╗", COLOR_BLACK, COLOR_HYELLOW);
		showstr(hout, 6 + 6 * j - 2, 3 + 3 * i + 1, "╚", COLOR_BLACK, COLOR_HYELLOW);
		showstr(hout, 6 + 6 * j + 2, 3 + 3 * i + 1, "╝", COLOR_BLACK, COLOR_HYELLOW);
	}
}