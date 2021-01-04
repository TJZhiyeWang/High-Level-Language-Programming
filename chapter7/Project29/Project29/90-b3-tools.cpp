/*1553449 Õı÷æ“µ 3∞‡*/
#include "90-b3.h"
#include "cmd_console_tools.h"
void show_y_m_d(tm tt, int x, int y)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	gotoxy(hout, x, y);
	int year[4], month[2], date[2];
	int i = 0;
	tt.tm_year += 1900;
	tt.tm_mon += 1;
	for (i = 0; i < 4; i++)
	{
		year[i] = tt.tm_year % 10;
		tt.tm_year /= 10;

	}
	for (i = 3; i >= 0; i--)
	{
		show_void(x, y);
		show_num(year[i], x, y);
		x += 9;
	}
	show_digit_sys(x, y);
	x += 8;
	for (i = 0; i < 2; i++)
	{
		month[i] = tt.tm_mon % 10;
		tt.tm_mon = tt.tm_mon / 10;

	}
	for (i = 1; i >= 0; i--)
	{
		show_void(x, y);
		show_num(month[i], x, y);
		x += 9;
	}
	show_digit_sys(x, y);
	x += 8;
	for (i = 0; i < 2; i++)
	{
		date[i] = tt.tm_mday % 10;
		tt.tm_mday = tt.tm_mday / 10;

	}
	for (i = 1; i >= 0; i--)
	{
		show_void(x, y);
		show_num(date[i], x, y);
		x += 9;
	}
}
void show_digit_sys(int x, int y)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);

	gotoxy(hout, x, y);
	cout << "      ";
	gotoxy(hout, x, ++y);
	cout << "      ";
	gotoxy(hout, x, ++y);
	cout << "      ";
	gotoxy(hout, x, ++y);
	cout << "******";
	gotoxy(hout, x, ++y);
	cout << "      ";
	gotoxy(hout, x, ++y);
	cout << "      ";
	gotoxy(hout, x, ++y);
	cout << "      ";
}