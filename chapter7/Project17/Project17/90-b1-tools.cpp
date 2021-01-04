/*1553449 3班 王志业*/
#define _CRT_SECURE_NO_WARNINGS
#include "90-b1.h"
//输入行和列的值（公用）
void int_xy(int *row, int *line)
{
	while (1)
	{
		cout << "please input the number of row(5-9)" << endl;
		cin >> *row;
		if (cin.fail())
		{
			cout << "you have input a wrong number...";
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}

		if (*row >= 5 && *row <= 9)
		{
			cin.ignore(1000, '\n');
			break;
		}
		cout << "you have input a wrong number...";
		cin.clear();
		cin.ignore(1000, '\n');

	}
	while (1)
	{
		cout << "please input the number of row(5-9)" << endl;
		cin >> *line;
		if (cin.fail())
		{
			cout << "you have input a wrong number...";
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}

		if (*line >= 5 && *line <= 9)
		{
			cin.ignore(1000, '\n');
			break;
		}
		cout << "you have input a wrong number...";
		cin.clear();
		cin.ignore(1000, '\n');

	}
}
//初始生成，内部数组
void set_ball(ball inside_array[][9], int row, int line)
{
	srand((unsigned int)time(0));
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < line; j++)
		{
			inside_array[i][j].cor = rand() % 9 + 1;
			inside_array[i][j].dis = 0;

		}
	}
}
//输出内部数组
void array_out(ball inside_array[][9], int row, int line)
{
	int i, j;
	cout << endl << "  " << "┃";
	for (i = 1; i <= line; i++)
		cout << i << " ";
	cout << endl;
	cout << "—" << "┿";
	for (i = 1; i <= line; i++)
		cout << "—";
	cout << endl;
	for (i = 0; i < row; i++)
	{
		cout << char(i + 'A') << " " << "┃";
		for (j = 0; j < line; j++)
			cout << inside_array[i][j].cor << " ";
		cout << endl;
	}
}
//读取鼠标位置及鼠标指令
int mouse_input(const HANDLE hout, ball inside_array[][9], int*pY, int*pX, int*pEY, int*pEX, int row, int line)
{
	const HANDLE hin = GetStdHandle(STD_INPUT_HANDLE);  //取标准输入设备对应的句柄

	int X = 0, Y = 0, mark = 0;//x stand for the line and y stand for the row;
	int action;
	enable_mouse(hin);

	while (1)
	{
		action = read_mouse(hin, X, Y);
		if (Y % 2 == 0 && Y / 2 >= 1 && Y / 2 <= row && (X % 4 == 2 || X % 4 == 3) && X / 4 >= 0 && X / 4 < line)
		{
			gotoxy(hout, 0, row * 2 + 2);
			cout << "[当前光标] " << setw(2) << char(Y / 2 - 1 + 'A') << "行" << setw(2) << char(X / 4 + '1') << "列        ";


			if (action == MOUSE_LEFT_BUTTON_CLICK&&mark == 0)
			{

				*pY = Y / 2 - 1;
				*pX = X / 4;
				showstr(hout, 2 + (X / 4) * 4, Y, "⊙", inside_array[*pY][*pX].cor, COLOR_HWHITE);
				mark = 1;
				setcolor(hout, COLOR_BLACK, COLOR_WHITE);
				continue;
			}

			if (action == MOUSE_LEFT_BUTTON_CLICK&&mark == 1)
			{
				*pEY = Y / 2 - 1;
				*pEX = X / 4;
				if ((*pX == *pEX || *pY == *pEY) && (*pX + *pY - *pEX - *pEY == 1 || *pX + *pY - *pEX - *pEY == -1))
				{
					ball_change(inside_array, *pX, *pY, *pEX, *pEY);
					gotoxy(hout, 0, row * 2 + 2);
					setcolor(hout, COLOR_BLACK, COLOR_WHITE);
					break;
				}
				else
				{
					mark = 0;
					showstr(hout, 2 + *pX * 4, 2 * (1 + *pY), "○", inside_array[*pY][*pX].cor, COLOR_HWHITE);
				}

			}

			if (action == MOUSE_RIGHT_BUTTON_CLICK)
				return 1;
		}

	}

	return 0;
}
//记录消除的分数（初始消除不得分）
void count_score(const HANDLE hout, ball inside_array[][9], int row, int line, int *pscore)
{
	int count = 0, i, j;
	for (i = 0; i < row; i++)
		for (j = 0; j < line; j++)
		{
			if (inside_array[i][j].cor == 0)
				count++;
		}
	*pscore += count;
	gotoxy(hout, 16, 0);
	setcolor(hout, COLOR_BLACK, COLOR_WHITE);
	cout << "your score:" << *pscore << setw(4) << "按鼠标右键退出";
}