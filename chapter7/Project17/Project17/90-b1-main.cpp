/*1553449 3班 王志业*/
#define _CRT_SECURE_NO_WARNINGS
#include "90-b1.h"
using namespace std;
void menu()
{
	cout << "*********************************************************************\n"
		<< "1.内部数组，生成初始状态，寻找是否有初始可消除项\n"
		<< "2.内部数组，消除初始可消除项后用非0项下落并用0填充\n"
		<< "3.内部数组，消除初始可消除项后查找消除提示\n"
		<< "4.n*n的框架（无分割线），显示初始状态\n"
		<< "5.n*n的框架（有分割线），显示初始状态\n"
		<< "6.n*n的框架（有分割线），显示初始状态及初始可消除项\n"
		<< "7.n*n的框架（有分割线），消除初始可消除项后显示消除提示\n"
		<< "8.cmd图形界面完整版\n"
		<< "9.从文件中读取以验证查找消除提示的算法的正确性\n"
		<< "0.退出\n"

		<< "**********************************************************************\n"
		<< "[请选择0-8]";
}
void q1(HANDLE hout, ball inside_array[][9], int *row, int *line)
{
	int i, j, flag = 0;
	system("cls");
	int_xy(row, line);
	set_ball(inside_array, *row, *line);
	system("cls");
	array_out(inside_array, *row, *line);
	cout << "按回车键寻找可消除项";
	while (_getch() != 13);
	for (i = 0; i < *row; i++)
		for (j = 0; j < *line; j++)
		{
			if (find_dis(inside_array, i, j, *row, *line) != 0)
			{
				char ch[2] = "\0";
				ch[0] = char(inside_array[i][j].cor + '0');
				showstr(hout, 2 * j + 4, i + 3, ch, COLOR_YELLOW, COLOR_WHITE);
				flag = 1;
			}
		}
	gotoxy(hout, 0, *row + 4);
	if (flag == 0)
		cout << "\n未找到可消除项";
	setcursor(hout, CURSOR_VISIBLE_NORMAL);
	setcolor(hout, COLOR_BLACK, COLOR_WHITE);

}
void q2(HANDLE hout, ball inside_array[][9], int *row, int *line)
{
	int i, j, flag = 0;
	srand((unsigned int)time(0));
	q1(hout, inside_array, row, line);
	cout << "\n按回车键进行消除并下落";
	while (_getch() != 13);
	disappear(inside_array, *row, *line);
	for (i = *row - 1; i >= 0; i--)
		for (j = *line - 1; j >= 0; j--)
			if (inside_array[i][j].cor == 0)
				up_down1(inside_array, i, j, i);
	system("cls");
	array_out(inside_array, *row, *line);
	for (i = 0; i < *row; i++)
		for (j = 0; j < *line; j++)
			if (inside_array[i][j].cor == 0)
				showstr(hout, 2 * j + 4, i + 3, "0", COLOR_YELLOW, COLOR_WHITE);
	setcolor(hout, COLOR_BLACK, COLOR_WHITE);
	gotoxy(hout, 0, *row + 4);
	cout << "\n按回车键进行随机填补";
	while (_getch() != 13);
	for (i = 0; i < *row; i++)
		for (j = 0; j < *line; j++)
			if (inside_array[i][j].cor == 0)
			{
				inside_array[i][j].cor = rand() % 9 + 1;
				char ch[2] = "\0";
				ch[0] = char(inside_array[i][j].cor + '0');
				showstr(hout, 2 * j + 4, i + 3, ch, COLOR_YELLOW, COLOR_WHITE);
			}
	setcolor(hout, COLOR_BLACK, COLOR_WHITE);
	gotoxy(hout, 0, *row + 4);
}
void q3(HANDLE hout, ball inside_array[][9], int *row, int *line)
{
	int i, j;
	q2(hout, inside_array, row, line);
	cout << "\n按回车键查找可交换的小球";
	while (_getch() != 13);
	system("cls");
	array_out(inside_array, *row, *line);
	reset_dis(inside_array, *row, *line);
	reset_cha(inside_array, *row, *line);
	for (i = 0; i < *row; i++)
		for (j = 0; j < *line; j++)
			find_cha(inside_array, i, j, *row, *line);


	for (i = 0; i < *row; i++)
	{
		for (j = 0; j < *line; j++)
		{
			if (inside_array[i][j].cha == 1)
			{
				char ch[2] = "\0";
				ch[0] = char(inside_array[i][j].cor + '0');
				showstr(hout, 2 * j + 4, i + 3, ch, COLOR_YELLOW, COLOR_WHITE);
			}
		}
	}

	gotoxy(hout, 0, *row + 4);
	setcolor(hout, COLOR_BLACK, COLOR_WHITE);



}
void q4(HANDLE hout, ball inside_array[][9], int *row, int *line)
{
	system("cls");
	int_xy(row, line);
	set_ball(inside_array, *row, *line);
	system("cls");
	array_out(inside_array, *row, *line);
	cout << "按回车键显示图形";
	while (_getch() != 13);
	draw2(inside_array, *row, *line);
}
void q5(HANDLE hout, ball inside_array[][9], int *row, int *line)
{
	system("cls");
	int_xy(row, line);
	set_ball(inside_array, *row, *line);
	system("cls");
	array_out(inside_array, *row, *line);
	cout << "按回车键显示图形";
	while (_getch() != 13);
	draw3(inside_array, *row, *line);
}
void q6(HANDLE hout, ball inside_array[][9], int *row, int *line)
{
	int i, j;
	system("cls");
	int_xy(row, line);
	set_ball(inside_array, *row, *line);
	system("cls");
	array_out(inside_array, *row, *line);
	for (i = 0; i < *row; i++)
		for (j = 0; j < *line; j++)

			find_dis(inside_array, i, j, *row, *line);


	cout << "按回车键显示图形及初始可消除项";
	while (_getch() != 13);
	draw4(inside_array, *row, *line);
}
void q7(HANDLE hout, ball inside_array[][9], int *row, int *line)
{
	int i, j, flag = 0;
	system("cls");
	int_xy(row, line);
	set_ball(inside_array, *row, *line);
	system("cls");
	array_out(inside_array, *row, *line);
	cout << "\n按回车键显示图形及初始可消除项";
	while (_getch() != 13);
	while (1)
	{
		flag = 0;
		reset_dis(inside_array, *row, *line);
		for (i = 0; i < *row; i++)
			for (j = 0; j < *line; j++)
			{
				find_dis(inside_array, i, j, *row, *line);
				if (inside_array[i][j].dis>0)
					flag = 1;
			}
		draw4(inside_array, *row, *line);
		if (flag == 0)
			break;
		disappear(inside_array, *row, *line);
		while (_getch() != 13);
		cout << "\n按回车键消除初始可消除项";
		dis_act(inside_array, *row, *line);
		down_reload(inside_array, *row, *line);
	}
	gotoxy(hout, 0, *row * 2 + 2);
	cout << "\n按回车键显示消除提示";
	while (_getch() != 13);
	for (i = 0; i < *row; i++)
		for (j = 0; j < *line; j++)

			find_cha(inside_array, i, j, *row, *line);
	mark_ball(inside_array, *row, *line);
}
void q8(HANDLE hout, ball inside_array[][9], int *row, int *line)
{
	int x, y, ex, ey, flag1 = 0, flag = 0, i, j, score = 0;
	system("cls");
	int_xy(row, line);
	set_ball(inside_array, *row, *line);
	system("cls");
	array_out(inside_array, *row, *line);
	cout << "按回车键开始游戏";
	while (_getch() != 13);
	draw3(inside_array, *row, *line);
	while (1)
	{
		flag = 0;
		reset_dis(inside_array, *row, *line);
		for (i = 0; i < *row; i++)
			for (j = 0; j < *line; j++)
			{
				find_dis(inside_array, i, j, *row, *line);
				if (inside_array[i][j].dis>0)
					flag = 1;
			}

		if (flag == 0)
			break;
		disappear(inside_array, *row, *line);
		dis_act(inside_array, *row, *line);
		down_reload(inside_array, *row, *line);
	}
	gotoxy(hout, 0, *row * 2 + 2);
	for (i = 0; i < *row; i++)
		for (j = 0; j < *line; j++)
			find_cha(inside_array, i, j, *row, *line);
	mark_ball(inside_array, *row, *line);//初始小球消除下落并标出,基本同q7
	while (1)
	{
		flag1 = 0;//当有小球可移动时，将flag1置1，直到无小球可移动，退出循环
		reset_cha(inside_array, *row, *line);//重置小球是否可移动值
		if (mouse_input(hout, inside_array, &y, &x, &ey, &ex, *row, *line) == 1)
			break;//加入鼠标，可交换小球位置
		gotoxy(hout, 0, *row * 2 + 2);
		/*cout << "\n按回车键继续";
		while (_getch() != 13);*/
		while (1)//交换位置后，重置可消除值，然后判断消除，下落填补，继续消除直到无小球可消除
		{
			flag = 0;
			reset_dis(inside_array, *row, *line);
			for (i = 0; i < *row; i++)
				for (j = 0; j < *line; j++)
				{
					find_dis(inside_array, i, j, *row, *line);
					if (inside_array[i][j].dis>0)
						flag = 1;
				}
			if (flag == 0)
				break;
			disappear(inside_array, *row, *line);
			count_score(hout, inside_array, *row, *line, &score);
			/*while (_getch() != 13);
			cout << "\n按回车键消除初始可消除项";*/
			dis_act(inside_array, *row, *line);
			down_reload(inside_array, *row, *line);
		}
		gotoxy(hout, 0, *row * 2 + 2);
		/*cout << "\n按回车键显示消除提示";
		while (_getch() != 13);*/
		for (i = 0; i < *row; i++)//判断有无小球可移动，若可移动则标出
			for (j = 0; j < *line; j++)
			{

				find_cha(inside_array, i, j, *row, *line);
				if (inside_array[i][j].cha>0)
					flag1 = 1;
			}
		mark_ball(inside_array, *row, *line);
		if (flag1 == 0)
			break;
	}
}
void q9(HANDLE hout, ball inside_array[][9])
{
	ifstream fin, fin1;
	char p[20], p1[20];
	int row, line, i, j, x, y;
	system("cls");
	cout << "请输入学号<输入1651234 对应会打开1651234.dat>" << endl;
	cin >> p;
	strcpy(p1, p);
	strcat(p, ".dat");

	strcat(p1, ".ans");
	fin.open(p, ios::in);
	if (fin.is_open() == 0)
	{
		cout << "open failed";
		return;
	}
	fin >> row >> line;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < line; j++)
		{
			fin >> inside_array[i][j].cor;
		}
	}
	fin.close();
	cout << endl << "原始数组" << endl;
	array_out(inside_array, row, line);
	reset_cha(inside_array, row, line);
	for (i = 0; i < row; i++)
		for (j = 0; j < line; j++)
			find_cha(inside_array, i, j, row, line);
	cout << "我的算法判断结果：" << endl;
	getxy(hout, x, y);
	array_out(inside_array, row, line);

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < line; j++)
		{
			if (inside_array[i][j].cha == 1)
			{
				char ch[2] = "\0";
				ch[0] = char(inside_array[i][j].cor + '0');
				showstr(hout, 2 * j + 4, y + i + 3, ch, COLOR_YELLOW, COLOR_WHITE);
			}
		}
	}

	gotoxy(hout, 0, y + row + 3);
	setcolor(hout, COLOR_BLACK, COLOR_WHITE);
	reset_cha(inside_array, row, line);
	cout << "标准答案" << endl;
	fin1.open(p1, ios::in);
	if (fin1.is_open() == 0)
	{
		cout << "open failed";
		return;
	}

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < line; j++)
		{
			fin1 >> inside_array[i][j].cor;
			inside_array[i][j].cha = inside_array[i][j].cor;
			if (inside_array[i][j].cor>90)
				inside_array[i][j].cor -= 90;

		}
	}
	fin1.close();
	getxy(hout, x, y);
	array_out(inside_array, row, line);

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < line; j++)
		{
			if (inside_array[i][j].cha>90)
			{
				char ch[2] = "\0";
				ch[0] = char(inside_array[i][j].cor + '0');
				showstr(hout, 2 * j + 4, y + i + 3, ch, COLOR_YELLOW, COLOR_WHITE);
			}
		}
	}

	gotoxy(hout, 0, y + row + 3);
	setcolor(hout, COLOR_BLACK, COLOR_WHITE);
}
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int row, line, flag = 0;
	ball inside_array[9][9];
	while (1)
	{
		system("cls");
		menu();
		int choice = int(_getch());
		switch (choice)
		{
			case '1':
				q1(hout, inside_array, &row, &line);
				cout << "\n按回车键退出";
				while (_getch() != 13);
				continue;
			case '2':
				q2(hout, inside_array, &row, &line);
				cout << "\n按回车键退出";
				while (_getch() != 13);
				continue;
			case '3':
				q3(hout, inside_array, &row, &line);
				cout << "\n按回车键退出";
				while (_getch() != 13);
				continue;
			case '4':
				q4(hout, inside_array, &row, &line);
				cout << "\n按回车键退出";
				while (_getch() != 13);
				continue;
			case '5':
				q5(hout, inside_array, &row, &line);
				cout << "\n按回车键退出";
				while (_getch() != 13);
				continue;
			case '6':
				q6(hout, inside_array, &row, &line);
				cout << "\n按回车键退出";
				while (_getch() != 13);
				continue;
			case '7':
				q7(hout, inside_array, &row, &line);
				gotoxy(hout, 0, row * 2 + 2);
				cout << "\n按回车键退出";
				while (_getch() != 13);
				continue;
			case '8':
				q8(hout, inside_array, &row, &line);
				gotoxy(hout, 0, row * 2 + 2);
				cout << "已无可移动小球，游戏结束";
				cout << "\n按回车键退出";
				while (_getch() != 13);
				continue;
			case '9':
				q9(hout, inside_array);
				cout << "\n按回车键退出";
				while (_getch() != 13);
				continue;
			case '0':
				break;
			default:
				continue;

		}
		return 0;
	}
}