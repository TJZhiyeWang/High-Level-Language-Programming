/*3班 王志业 1553449*/
#include <iostream>
#include "cmd_console_tools.h"
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>	//srand/rand函数
#include <time.h>	//time函数
using namespace std;
struct map
{
	int ocu;//0被占据，1未被占据
	int loc;//代表自己所处位置,自己占的位置为1
};
//生成初始地图和自己的位置
void Initmap(map game[][10], int *loc)
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
		{
			game[i][j].ocu = 0;
			game[i][j].loc = 0;
		}
	game[9][3].loc = 1;
	game[9][4].loc = 1;
	*loc = 3;
}
//随机生成阻挡物，在第一行
void block(map game[][10])
{
	srand((unsigned int)time(0));
	int i = rand() % 9;
	game[0][i].ocu = 1;
	game[0][i + 1].ocu = 1;
}
//整体下移(删除最后一行，第一行清零
void move_down(map game[][10])
{
	for (int i = 0; i < 10; i++)
		game[9][i].ocu = 0;
	for (int j = 9; j >= 1; j--)
		for (int i = 0; i < 10; i++)
			game[j][i].ocu = game[j - 1][i].ocu;
	for (int i = 0; i < 10; i++)
		game[0][i].ocu = 0;
}
//向左位移
void move_left(map game[][10], int *loc)
{
	if (*loc > 0)
	{
		game[9][*loc - 1].loc = 1;
		game[9][*loc + 1].loc = 0;
		(*loc) -= 1;
	}

}
//
void move_right(map game[][10], int *loc)
{
	if (*loc < 9)
	{
		game[9][*loc - 1].loc = 0;
		game[9][*loc + 1].loc = 1;
		(*loc) += 1;
	}

}
void print(map game[][10], int car)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	setcursor(hout, CURSOR_INVISIBLE);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (game[i][j].ocu == 1 && game[i][j].loc == 0)
				showstr(hout, j, i, " ", COLOR_HWHITE, 1);
			else if (game[i][j].loc == 1)
				showstr(hout, j, i, " ", car, 1);
			else
				showstr(hout, j, i, " ", COLOR_BLACK, 1);
		}
	}
	for (int i = 0; i < 10; i++)
	{
		showstr(hout, 10, i, "|", COLOR_BLACK, COLOR_WHITE);
		showstr(hout, i, 10, "-", COLOR_BLACK, COLOR_WHITE);
	}


}
int if_knock(map game[][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (game[i][j].loc + game[i][j].ocu == 2)
				return 1;
		}
	}
	return 0;
}
void menu()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	setfontsize(hout, L"新宋体", 60);
	gotoxy(hout, 15, 4);
	setcolor(hout, COLOR_BLACK, COLOR_RED);
	cout << "极品飞车" << endl;
	gotoxy(hout, 8, 6);
	cout << "press any key to pass...";

}
void menu2()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	setfontsize(hout, L"新宋体", 20);
	setcolor(hout, COLOR_BLACK, COLOR_HBLUE);
	gotoxy(hout, 100, 100);
	cout << "抵制不良游戏 拒绝盗版游戏\n"
		"注意自我保护 谨防上当受骗\n"
		"适度游戏益脑 过度游戏伤身\n"
		"合理安排时间 享受健康生活\n";
}
void menu3(int *car, int *diff)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	setcolor(hout, COLOR_BLACK, COLOR_HWHITE);
	cout << "快来选一辆你喜欢颜色的车吧！！！！！(输入车子对应的编号）" << endl;

	setcolor(hout, COLOR_BLACK, COLOR_HBLUE);
	cout << "1.█" << "亮蓝色保时捷（马力：10 操控：8）" << endl;
	setcolor(hout, COLOR_BLACK, COLOR_HGREEN);
	cout << "2.█" << "亮蓝色宝马（马力：9 操控：9）" << endl;
	setcolor(hout, COLOR_BLACK, COLOR_HRED);
	cout << "3.█" << "亮蓝色法拉利（马力：8 操控：10）" << endl;

	setcolor(hout, COLOR_BLACK, COLOR_HWHITE);
	cin >> *car;
	cout << "选择游戏难度：1.轻松（难度参考c++程序设计课后题\n"
		"2.噩梦（难度参考补充题,为保证游戏体验，强烈推荐）\n"
		"3.地狱（难度参考大作业，尤其是二维码！！！）\n";
	cin >> *diff;
	cout << "游戏说明，驾驶你的跑车驰骋在跑道上，***左右***键操控车辆躲避向你驶来的车辆。";
}
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	setconsoleborder(hout, 40, 20);


	menu();
	_getch();
	system("cls");
	menu2();
	Sleep(1000);
	int car, diff;
	menu3(&car, &diff);
loop:cout << "3秒后开始。。。";
	Sleep(3000);
	map gamemap[10][10];
	int loc, count = 1;
	Initmap(gamemap, &loc);
	float time_start, time_end;
	time_start = (float)clock();
	setconsoleborder(hout, 25, 15);
	while (1)
	{
		system("cls");
		print(gamemap, car);
		if (if_knock(gamemap) == 1)
			break;


		setcolor(hout, COLOR_BLACK, COLOR_HWHITE);
		time_end = (float)clock();
		if ((time_end - time_start) / CLK_TCK >= 1.0 / (double)diff)
		{
			move_down(gamemap);
			if (count % (4 - diff) == 0)
				block(gamemap);
			count++;
			time_start = time_end;
		}
		if (_kbhit())
		{
			switch (_getch())
			{
				case 77:
					move_right(gamemap, &loc);
					cin.clear();
					break;
				case 75:
					move_left(gamemap, &loc);
					cin.clear();
					break;
			}
		}



	}
	cout << "惨烈的车祸！！！是否花费5元钱购买复活币以继续游戏？（y/n)";
loop2:	char ch = _getch();
	if (ch == 'y')
	{
		cout << endl << "我的支付宝：1530180****，感谢支持";
		Sleep(2000);
		system("cls");
		goto loop;
	}
	else if (ch == 'n')
	{
		cout << endl << "没钱还敢玩游戏？？？滚去学习！！！";
	}
	else
		goto loop2;
	return 0;
}