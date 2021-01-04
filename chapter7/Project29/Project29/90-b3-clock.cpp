/*1553449 王志业 3班*/
#define _CRT_SECURE_NO_WARNINGS
#include "90-b3.h"
#include "cmd_console_tools.h"
//构建表盘
void face()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int x, y, r = 400;
	int a = 500, b = 250;
	setconsoleborder(hout, 1000, 500);
	setfontsize(hout, L"新宋体", 1);
	showstr(hout, a, b, "●", COLOR_BLACK, COLOR_HWHITE);
	for (x = a - r; x <= a + r; x += 2)
	{
		y = int(b + 0.5*sqrt(r*r - (x - a) *(x - a)));

		showstr(hout, x, y, "●", COLOR_BLACK, COLOR_HWHITE);
		y = int(b - 0.5*sqrt(r*r - (x - a) *(x - a)));

		showstr(hout, x, y, "●", COLOR_BLACK, COLOR_HWHITE);
	}
	for (y = b - r / 2; y <= b + r / 2; y++)
	{
		x = int(a + sqrt(r*r - 4 * (y - b)*(y - b)));
		showstr(hout, x, y, "●", COLOR_BLACK, COLOR_HWHITE);
		x = (int)(a - sqrt(r*r - 4 * (y - b)*(y - b)));
		showstr(hout, x, y, "●", COLOR_BLACK, COLOR_HWHITE);
	}

}
//删除上一次构建的秒针
void delete_second_hand(tm tt)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int a = 500, b = 250;
	int x = a, y = b, r = 350;
	double k;
	if (tt.tm_sec == 0)
		tt.tm_sec += 60;
	if (tt.tm_sec - 1 > 0 && tt.tm_sec - 1 < 30)
	{
		k = tan(-(double(15 - (tt.tm_sec - 1)) / 60.0)*pi * 2);
		while ((x - a)*(x - a) + 4 * (y - b)*(y - b) <= r*r)
		{
			{
				showstr(hout, x, y, "  ", COLOR_BLACK, COLOR_HWHITE);
				x++;
				y = b + k*(x - a);
			}
		}
		if (k == tan(-(double(15 - tt.tm_min) / 60.0)*pi * 2))
		{
			minute_hand(tt);
		}
		else if (k == tan(-(double(3 - tt.tm_hour % 12) / 12.0)*pi * 2))
		{
			hour_hand(tt);
		}

	}
	else if (tt.tm_sec - 1 > 30 && tt.tm_sec - 1 < 60)
	{
		k = tan(-(double(75 - (tt.tm_sec - 1)) / 60.0)*pi * 2);

		while ((x - a)*(x - a) + 4 * (y - b)*(y - b) <= r*r)
		{
			showstr(hout, x, y, "  ", COLOR_BLACK, COLOR_HWHITE);
			x--;
			y = b + k*(x - a);
		}
		if (k == tan(-(double(75 - tt.tm_min) / 60.0)*pi * 2))
		{
			minute_hand(tt);
		}
		else if (k == tan(-(double(15 - tt.tm_hour % 12) / 12.0)*pi * 2))
		{
			hour_hand(tt);
		}

	}
	else if (tt.tm_sec - 1 == 30)
	{
		while ((x - a)*(x - a) + 4 * (y - b)*(y - b) <= r*r)
		{
			showstr(hout, x, y, "  ", COLOR_BLACK, COLOR_HWHITE);
			y++;
		}
		if (tt.tm_sec - 1 == tt.tm_min)
			minute_hand(tt);
		else if (tt.tm_hour % 12 == 6)
			hour_hand(tt);
	}
	else if (tt.tm_sec - 1 == 0)
	{
		while ((x - a)*(x - a) + 4 * (y - b)*(y - b) <= r*r)
		{
			showstr(hout, x, y, "  ", COLOR_BLACK, COLOR_HWHITE);
			y--;
		}
		if (tt.tm_sec - 1 == tt.tm_min)
			minute_hand(tt);
		else if (tt.tm_hour % 12 == 0)
			hour_hand(tt);
	}

}
//构建秒针
void second_hand(tm tt)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int a = 500, b = 250;
	int x = a, y = b, r = 350;
	double k;

	if (tt.tm_sec > 0 && tt.tm_sec < 30)
	{
		k = tan(-(double(15 - tt.tm_sec) / 60)*pi * 2);
		while ((x - a)*(x - a) + 4 * (y - b)*(y - b) <= r*r)
		{
			showstr(hout, x, y, "●", COLOR_BLACK, COLOR_HWHITE);
			x += 2;
			y = b + k*(x - a);
		}
	}
	else if (tt.tm_sec > 30 && tt.tm_sec < 60)
	{
		k = tan(-(double(75 - tt.tm_sec) / 60)*pi * 2);
		while ((x - a)*(x - a) + 4 * (y - b)*(y - b) <= r*r)
		{
			showstr(hout, x, y, "●", COLOR_BLACK, COLOR_HWHITE);
			x -= 2;
			y = b + k*(x - a);
		}
	}
	else if (tt.tm_sec == 30)
	{
		while ((x - a)*(x - a) + 4 * (y - b)*(y - b) <= r*r)
		{
			showstr(hout, x, y, "●", COLOR_BLACK, COLOR_HWHITE);
			y++;
		}
	}
	else if (tt.tm_sec == 0)
	{
		while ((x - a)*(x - a) + 4 * (y - b)*(y - b) <= r*r)
		{
			showstr(hout, x, y, "●", COLOR_BLACK, COLOR_HWHITE);
			y--;
		}
	}

}
//构建分针
void minute_hand(tm tt)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int a = 500, b = 250;
	int x = a, y = b, r = 250;
	double k;

	if (tt.tm_min > 0 && tt.tm_min < 30)
	{
		k = tan(-(double(15 - tt.tm_min) / 60.0)*pi * 2);
		if (k != tan(-(double(15 - tt.tm_sec) / 60.0)*pi * 2) && k != tan(-(double(3 - tt.tm_hour % 12) / 12.0)*pi * 2))
		{
			while ((x - a)*(x - a) + 4 * (y - b)*(y - b) <= r*r)
			{
				showstr(hout, x, y, "●", COLOR_BLACK, COLOR_HWHITE);
				x += 2;
				y = b + k*(x - a);
			}
		}
	}
	else if (tt.tm_min > 30 && tt.tm_min < 60)
	{
		k = tan(-(double(75 - tt.tm_min) / 60.0)*pi * 2);
		if (k != tan(-(double(75 - tt.tm_sec) / 60.0)*pi * 2) && k != tan(-(double(15 - tt.tm_hour % 12) / 12.0)*pi * 2))
		{
			while ((x - a)*(x - a) + 4 * (y - b)*(y - b) <= r*r)
			{
				showstr(hout, x, y, "●", COLOR_BLACK, COLOR_HWHITE);
				x -= 2;
				y = b + k*(x - a);
			}
		}
	}
	else if (tt.tm_min == 30)
	{
		while ((x - a)*(x - a) + 4 * (y - b)*(y - b) <= r*r)
		{
			showstr(hout, x, y, "●", COLOR_BLACK, COLOR_HWHITE);
			y++;
		}
	}
	else if (tt.tm_min == 0)
	{
		while ((x - a)*(x - a) + 4 * (y - b)*(y - b) <= r*r)
		{
			showstr(hout, x, y, "●", COLOR_BLACK, COLOR_HWHITE);
			y--;
		}
	}

}
//删除分针
void delete_minute_hand(tm tt)
{

	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int a = 500, b = 250;
	int x = a, y = b, r = 250;
	double k;
	if (tt.tm_min == 0)
		tt.tm_min += 60;
	if (tt.tm_min - 1 > 0 && tt.tm_min - 1 < 30)
	{
		k = tan(-(double(15 - (tt.tm_min - 1)) / 60.0)*pi * 2);
		while ((x - a)*(x - a) + 4 * (y - b)*(y - b) <= r*r)
		{
			showstr(hout, x, y, "  ", COLOR_BLACK, COLOR_HWHITE);
			x += 2;
			y = b + k*(x - a);
		}
		if (k == tan(-(double(3 - tt.tm_hour % 12) / 12.0)*pi * 2))
		{
			hour_hand(tt);
		}
	}
	else if (tt.tm_min - 1 > 30 && tt.tm_min - 1 < 60)
	{
		k = tan(-(double(75 - (tt.tm_min - 1)) / 60.0)*pi * 2);
		while ((x - a)*(x - a) + 4 * (y - b)*(y - b) <= r*r)
		{
			showstr(hout, x, y, "  ", COLOR_BLACK, COLOR_HWHITE);
			x -= 2;
			y = b + k*(x - a);
		}
		if (k == tan(-(double(15 - tt.tm_hour % 12) / 12.0)*pi * 2))
		{
			hour_hand(tt);
		}
	}
	else if (tt.tm_min - 1 == 30)
	{
		while ((x - a)*(x - a) + 4 * (y - b)*(y - b) <= r*r)
		{
			showstr(hout, x, y, "  ", COLOR_BLACK, COLOR_HWHITE);
			y++;
		}
		if (tt.tm_hour % 12 == 6)
			hour_hand(tt);
	}
	else if (tt.tm_min - 1 == 0)
	{
		while ((x - a)*(x - a) + 4 * (y - b)*(y - b) <= r*r)
		{
			showstr(hout, x, y, "  ", COLOR_BLACK, COLOR_HWHITE);
			y--;
		}
		if (tt.tm_hour % 12 == 0)
			hour_hand(tt);
	}

}
//构建时针
void hour_hand(tm tt)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int a = 500, b = 250;
	int x = a, y = b, r = 150;
	double k;

	if (tt.tm_hour % 12 > 0 && tt.tm_hour % 12 < 6)
	{
		k = tan(-(double(3 - tt.tm_hour % 12) / 12.0)*pi * 2);
		while ((x - a)*(x - a) + 4 * (y - b)*(y - b) <= r*r)
		{
			showstr(hout, x, y, "●", COLOR_BLACK, COLOR_HWHITE);
			x += 2;
			y = b + k*(x - a);
		}
	}
	else if (tt.tm_hour % 12 > 6 && tt.tm_hour % 12 < 12)
	{
		k = tan(-(double(15 - tt.tm_hour % 12) / 12.0)*pi * 2);
		while ((x - a)*(x - a) + 4 * (y - b)*(y - b) <= r*r)
		{
			showstr(hout, x, y, "●", COLOR_BLACK, COLOR_HWHITE);
			x -= 2;
			y = b + k*(x - a);
		}
	}
	else if (tt.tm_hour % 12 == 6)
	{
		while ((x - a)*(x - a) + 4 * (y - b)*(y - b) <= r*r)
		{
			showstr(hout, x, y, "●", COLOR_BLACK, COLOR_HWHITE);
			y++;
		}
	}
	else if (tt.tm_hour % 12 == 0)
	{
		while ((x - a)*(x - a) + 4 * (y - b)*(y - b) <= r*r)
		{
			showstr(hout, x, y, "●", COLOR_BLACK, COLOR_HWHITE);
			y--;
		}
	}
}
//删除时针
void delete_hour_hand(tm tt)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int a = 500, b = 250;
	int x = a, y = b, r = 150;
	double k;
	if (tt.tm_hour == 0)
		tt.tm_sec += 12;
	if (tt.tm_hour % 12 - 1 > 0 && tt.tm_hour % 12 - 1 < 6)
	{
		k = tan(-(double(3 - (tt.tm_hour % 12 - 1)) / 12.0)*pi * 2);
		if (k != tan(-(double(15 - tt.tm_sec) / 60.0)*pi * 2) && k != tan(-(double(15 - (tt.tm_min - 1)) / 60.0)*pi * 2))
		{
			while ((x - a)*(x - a) + 4 * (y - b)*(y - b) <= r*r)
			{
				showstr(hout, x, y, "  ", COLOR_BLACK, COLOR_HWHITE);
				x++;
				y = b + k*(x - a);
			}
		}
	}
	else if (tt.tm_hour % 12 - 1 > 6 && tt.tm_hour % 12 - 1 < 12)
	{
		k = tan(-(double(15 - (tt.tm_hour % 12 - 1)) / 12.0)*pi * 2);
		if (k != tan(-(double(75 - tt.tm_sec) / 60.0)*pi * 2) && k != tan(-(double(75 - (tt.tm_min - 1)) / 60.0)*pi * 2))
		{
			while ((x - a)*(x - a) + 4 * (y - b)*(y - b) <= r*r)
			{
				showstr(hout, x, y, "  ", COLOR_BLACK, COLOR_HWHITE);
				x--;
				y = b + k*(x - a);
			}
		}
	}
	else if (tt.tm_hour % 12 - 1 == 6)
	{
		while ((x - a)*(x - a) + 4 * (y - b)*(y - b) <= r*r)
		{
			showstr(hout, x, y, "  ", COLOR_BLACK, COLOR_HWHITE);
			y++;
		}
	}
	else if (tt.tm_hour % 12 - 1 == 0)
	{
		while ((x - a)*(x - a) + 4 * (y - b)*(y - b) <= r*r)
		{
			showstr(hout, x, y, "  ", COLOR_BLACK, COLOR_HWHITE);
			y--;
		}
	}
}
void hand_clock()
{
	system("cls");
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int last_sec = -1, last_min = -1, last_hour = -1;
	struct tm *tt;	//struct tm 为系统定义的结构体

	face();
	while (1)
	{
		time_t input_time = time(0);
		tt = localtime(&input_time);
		if (tt->tm_sec > last_sec || tt->tm_sec == 0)
		{
			second_hand(*tt);
			delete_second_hand(*tt);
		}
		if (tt->tm_min > last_min || tt->tm_min == 0)
		{
			minute_hand(*tt);
			delete_minute_hand(*tt);
			is_time(*tt);
		}
		if (tt->tm_hour > last_hour || tt->tm_hour % 12 == 0)
		{
			hour_hand(*tt);
			delete_hour_hand(*tt);
			show_y_m_d(*tt, 450, 470);
		}
		last_hour = tt->tm_hour;
		last_sec = tt->tm_sec;
		last_min = tt->tm_min;
		if (_kbhit() == 0)
			continue;
		else
		{
			if (_getch() == 9)
				break;

		}
	}

}
void show_digit_0()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int x, y;
	getxy(hout, x, y);
	cout << "********";
	gotoxy(hout, x, ++y);
	cout << "*      *";
	gotoxy(hout, x, ++y);
	cout << "*      *";
	gotoxy(hout, x, ++y);
	cout << "*      *";
	gotoxy(hout, x, ++y);
	cout << "*      *";
	gotoxy(hout, x, ++y);
	cout << "*      *";
	gotoxy(hout, x, ++y);
	cout << "********";
}
void show_digit_1()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int x, y;
	getxy(hout, x, y);
	cout << "   **   ";
	gotoxy(hout, x, ++y);
	cout << "   **   ";
	gotoxy(hout, x, ++y);
	cout << "   **   ";
	gotoxy(hout, x, ++y);
	cout << "   **   ";
	gotoxy(hout, x, ++y);
	cout << "   **   ";
	gotoxy(hout, x, ++y);
	cout << "   **   ";
	gotoxy(hout, x, ++y);
	cout << "   **   ";
}
void show_digit_2()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int x, y;
	getxy(hout, x, y);
	cout << "********";
	gotoxy(hout, x, ++y);
	cout << "       *";
	gotoxy(hout, x, ++y);
	cout << "       *";
	gotoxy(hout, x, ++y);
	cout << "********";
	gotoxy(hout, x, ++y);
	cout << "*       ";
	gotoxy(hout, x, ++y);
	cout << "*       ";
	gotoxy(hout, x, ++y);
	cout << "********";
}
void show_digit_3()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int x, y;
	getxy(hout, x, y);
	cout << "********";
	gotoxy(hout, x, ++y);
	cout << "       *";
	gotoxy(hout, x, ++y);
	cout << "       *";
	gotoxy(hout, x, ++y);
	cout << "********";
	gotoxy(hout, x, ++y);
	cout << "       *";
	gotoxy(hout, x, ++y);
	cout << "       *";
	gotoxy(hout, x, ++y);
	cout << "********";
}
void show_digit_4()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int x, y;
	getxy(hout, x, y);
	cout << "*      *";
	gotoxy(hout, x, ++y);
	cout << "*      *";
	gotoxy(hout, x, ++y);
	cout << "*      *";
	gotoxy(hout, x, ++y);
	cout << "********";
	gotoxy(hout, x, ++y);
	cout << "       *";
	gotoxy(hout, x, ++y);
	cout << "       *";
	gotoxy(hout, x, ++y);
	cout << "       *";
}
void show_digit_5()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int x, y;
	getxy(hout, x, y);
	cout << "********";
	gotoxy(hout, x, ++y);
	cout << "*       ";
	gotoxy(hout, x, ++y);
	cout << "*       ";
	gotoxy(hout, x, ++y);
	cout << "********";
	gotoxy(hout, x, ++y);
	cout << "       *";
	gotoxy(hout, x, ++y);
	cout << "       *";
	gotoxy(hout, x, ++y);
	cout << "********";
}
void show_digit_6()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int x, y;
	getxy(hout, x, y);
	cout << "********";
	gotoxy(hout, x, ++y);
	cout << "*       ";
	gotoxy(hout, x, ++y);
	cout << "*       ";
	gotoxy(hout, x, ++y);
	cout << "********";
	gotoxy(hout, x, ++y);
	cout << "*      *";
	gotoxy(hout, x, ++y);
	cout << "*      *";
	gotoxy(hout, x, ++y);
	cout << "********";
}
void show_digit_7()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int x, y;
	getxy(hout, x, y);
	cout << "********";
	gotoxy(hout, x, ++y);
	cout << "       *";
	gotoxy(hout, x, ++y);
	cout << "       *";
	gotoxy(hout, x, ++y);
	cout << "       *";
	gotoxy(hout, x, ++y);
	cout << "       *";
	gotoxy(hout, x, ++y);
	cout << "       *";
	gotoxy(hout, x, ++y);
	cout << "       *";
}
void show_digit_8()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int x, y;
	getxy(hout, x, y);
	cout << "********";
	gotoxy(hout, x, ++y);
	cout << "*      *";
	gotoxy(hout, x, ++y);
	cout << "*      *";
	gotoxy(hout, x, ++y);
	cout << "********";
	gotoxy(hout, x, ++y);
	cout << "*      *";
	gotoxy(hout, x, ++y);
	cout << "*      *";
	gotoxy(hout, x, ++y);
	cout << "********";
}
void show_digit_9()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int x, y;
	getxy(hout, x, y);
	cout << "********";
	gotoxy(hout, x, ++y);
	cout << "*      *";
	gotoxy(hout, x, ++y);
	cout << "*      *";
	gotoxy(hout, x, ++y);
	cout << "********";
	gotoxy(hout, x, ++y);
	cout << "       *";
	gotoxy(hout, x, ++y);
	cout << "       *";
	gotoxy(hout, x, ++y);
	cout << "********";
}
void show_digit_void()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int x, y;
	getxy(hout, x, y);
	cout << "       ";
	gotoxy(hout, x, ++y);
	cout << "       ";
	gotoxy(hout, x, ++y);
	cout << "       ";
	gotoxy(hout, x, ++y);
	cout << "       ";
	gotoxy(hout, x, ++y);
	cout << "       ";
	gotoxy(hout, x, ++y);
	cout << "       ";
	gotoxy(hout, x, ++y);
	cout << "       ";
}
void show_digit_face()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	setconsoleborder(hout, 100, 50);
	setfontsize(hout, L"新宋体", 24);
	int i;
	for (i = 10; i < 54; i++)
		showstr(hout, i, 10, "*", COLOR_BLACK, COLOR_HWHITE);
	for (i = 11; i <= 19; i++)
		showstr(hout, 53, i, "*", COLOR_BLACK, COLOR_HWHITE);
	for (i = 53; i >= 10; i--)
		showstr(hout, i, 20, "*", COLOR_BLACK, COLOR_HWHITE);
	for (i = 19; i >= 10; i--)
		showstr(hout, 10, i, "*", COLOR_BLACK, COLOR_HWHITE);
	show_digit_shine();
}
void show_digit_shine()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	showstr(hout, 31, 13, "**", COLOR_HWHITE, COLOR_HWHITE);
	showstr(hout, 31, 14, "**", COLOR_HWHITE, COLOR_HWHITE);
	showstr(hout, 31, 16, "**", COLOR_HWHITE, COLOR_HWHITE);
	showstr(hout, 31, 17, "**", COLOR_HWHITE, COLOR_HWHITE);
	setcolor(hout, COLOR_BLACK, COLOR_HWHITE);
}
void show_digit_dark()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	showstr(hout, 31, 13, "**", COLOR_BLACK, COLOR_BLACK);
	showstr(hout, 31, 14, "**", COLOR_BLACK, COLOR_BLACK);
	showstr(hout, 31, 16, "**", COLOR_BLACK, COLOR_BLACK);
	showstr(hout, 31, 17, "**", COLOR_BLACK, COLOR_BLACK);
	setcolor(hout, COLOR_BLACK, COLOR_HWHITE);
}
//指定位置输出显示的数字,x 列，y行为数字左上角
void show_num(int num, int x, int y)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	gotoxy(hout, x, y);
	switch (num)
	{
		case 0:
			show_digit_0();
			break;
		case 1:
			show_digit_1();
			break;
		case 2:
			show_digit_2();
			break;
		case 3:
			show_digit_3();
			break;
		case 4:
			show_digit_4();
			break;
		case 5:
			show_digit_5();
			break;
		case 6:
			show_digit_6();
			break;
		case 7:
			show_digit_7();
			break;
		case 8:
			show_digit_8();
			break;
		case 9:
			show_digit_9();
			break;
	}
}
void show_void(int x, int y)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	gotoxy(hout, x, y);
	show_digit_void();
}
void digit_clock()
{
	system("cls");
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	struct tm *tt;
	int last_sec = -1, last_min = -1, last_hour = -1;
	show_digit_face();
	while (1)
	{
		time_t input_time = time(0);
		tt = localtime(&input_time);
		if (tt->tm_sec > last_sec || tt->tm_sec == 0)
		{
			show_digit_dark();
			Sleep(200);
			show_digit_shine();
		}
		if (tt->tm_min > last_min || tt->tm_min == 0)
		{
			int min1, min2;
			min2 = tt->tm_min % 10;
			min1 = tt->tm_min / 10;
			show_void(34, 12);
			show_void(44, 12);
			show_num(min1, 34, 12);
			show_num(min2, 44, 12);
			is_time(*tt);
		}
		if (tt->tm_hour > last_hour || tt->tm_hour % 12 == 0)
		{
			int hour1, hour2;
			hour2 = tt->tm_hour % 10;
			hour1 = tt->tm_hour / 10;
			show_void(12, 12);
			show_void(22, 12);
			show_num(hour1, 12, 12);
			show_num(hour2, 22, 12);
			show_y_m_d(*tt, 10, 23);
		}
		last_hour = tt->tm_hour;
		last_sec = tt->tm_sec;
		last_min = tt->tm_min;
		if (_kbhit() == 0)
			continue;
		else
		{
			if (_getch() == 9)
				break;
		}

	}
}