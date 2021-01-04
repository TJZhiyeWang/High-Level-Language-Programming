/*王志业 1553449 3班*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <conio.h>
#include <Windows.h>
#define max_floor 10
#define width 8//界面字符间的宽度
#define delaytime 200
using namespace std;
int a[10], b[10], c[10];
int num_a, num_b, num_c, speed, print_flag;
int step = 1;
/* 将光标移动到指定位置 */
void gotoxy(HANDLE hout, int X, int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/* 在指定位置处打印一个指定的字符 */
void showch(HANDLE hout, int X, int Y, char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}
void print(char);
//显示步骤
void printstep(char initial,char target1,int num)
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	gotoxy(hout, 0, max_floor + width);
	cout << "第" << setw(4) << step << "步(" << num << "#: " << initial << "-->" << target1 << ")";
	if (print_flag)
	{
		print('A');
		print('B');
		print('C');
	}
}
void print(char stack)
{
	int i = 0;
	if (stack == 'A')
	{
		cout << "A:";
		for (; i < 10; i++)
		{
			if (a[i] != 0)
				cout << setw(2) << a[i];
			else
				cout << "  ";
		}
		cout << " ";
	}
	else if (stack == 'B')
	{
		cout << "B:";
		for (; i < 10; i++)
		{
			if (b[i] != 0)
				cout << setw(2) << b[i];
			else
				cout << "  ";
		}
		cout << " ";
	}
	else
	{
		cout << "C:";
		for (; i < 10; i++)
		{
			if (c[i] != 0)
				cout << setw(2) << c[i];
			else
				cout << "  ";
		}
		cout << " ";
	}

}
void cartoon_disappear(char source)
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	if (source == 'A')
	{
		showch(hout, width + 2, max_floor - num_a + 1, ' ');
	}
	if (source == 'B')
	{
		showch(hout, 2 * width + 2, max_floor - num_b + 1, ' ');
	}
	if (source == 'C')
	{
		showch(hout, 3 * width + 2, max_floor - num_c + 1, ' ');
	}
}
void cartoon_show(char target, int temp)
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	if (target == 'A')
	{
		showch(hout, width + 2, max_floor - num_a, temp + '0');
	}
	if (target == 'B')
	{
		showch(hout, 2 * width + 2, max_floor - num_b, temp + '0');
	}
	if (target == 'C')
	{
		showch(hout, 3 * width + 2, max_floor - num_c, temp + '0');
	}
}
void delay_time(int speed)
{
	switch(speed)
	{
		case 0:while (_getch() != '\r'); break;
		case 1:Sleep(delaytime); break;
		case 2:Sleep(speed*delaytime); break;
		case 3:Sleep(speed*delaytime); break;
		case 4:Sleep(speed*delaytime); break;
		case 5:Sleep(speed*delaytime); break;
	}
}
void move(char source, char target)
{
	int temp;
	cartoon_disappear(source);
	if (source == 'A')
	{
		num_a--;
		temp = a[num_a];
		a[num_a] = 0;
	}
	else if (source == 'B')
	{
		num_b--;
		temp = b[num_b];
		b[num_b] = 0;
	}
	else
	{
		num_c--;
		temp = c[num_c];
		c[num_c] = 0;
	}
	cartoon_show(target, temp);
	if (target == 'A')
	{
		a[num_a] = temp;
		num_a++;
	}
	else if (target == 'B')
	{
		b[num_b] = temp;
		num_b++;
	}
	else
	{
		c[num_c] = temp;
		num_c++;
	}

}


void Hanoi(int num, char initial, char target)
{
	char target1, temp;
	if (num == 0)
		return;
	if (initial == 'A')
	{
		if (target == 'B')
			target1 = 'C';
		else
			target1 = 'B';
	}
	else if (initial == 'B')
	{
		if (target == 'C')
			target1 = 'A';
		else
			target1 = 'C';
	}
	else if (initial == 'C')
	{
		if (target == 'A')
			target1 = 'B';
		else
			target1 = 'A';
	}
	temp = target;
	target = target1;
	target1 = temp;
	Hanoi(num - 1, initial, target);
	move(initial, target1);
	
	printstep(initial, target1,num);
	delay_time(speed);
	step++;
	Hanoi(num - 1, target, target1);
}

void my_interface()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int i = 0;
	gotoxy(hout, width,max_floor + 1 );
	for (; i < width * 2 + 5;i++)
		cout << "=";
	showch(hout,width+2 , max_floor + 2,'A');
	showch(hout, 2*width + 2,max_floor + 2 , 'B');
	showch(hout,3*width + 2 ,max_floor + 2 , 'C');
	i = 0;
	while (a[i] != 0)
	{
		showch(hout, width + 2, max_floor -i, a[i]+'0');
		i++;
	}
	i = 0;
	while (b[i] != 0)
	{
		showch(hout, 2*width + 2, max_floor - i, b[i] + '0');
		i++;
	}
	i = 0;
	while (c[i] != 0)
	{
		showch(hout, 3*width + 2, max_floor  - i, c[i] + '0');
		i++;
	}
	gotoxy(hout, 0, max_floor + width);
	cout << "初始：";
	if (print_flag)
	{
		print('A');
		print('B');
		print('C');
	}
	delay_time(speed);
}

int main()
{
	char initial, target;
	int num;
	while (1)
	{
		cout << "请输入汉诺塔的层数<1-10>:" << endl;
		cin >> num;

		if (!cin)
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (num <= 0)
			continue;
		break;
	}
	while (1)
	{
		cout << "请输入起始柱<A-C>:" << endl;
		cin >> initial;
		if ((initial >= 'A'&&initial <= 'C') || (initial >= 'a'&&initial <= 'c'))
		{
			if (initial >= 'a')
				initial -= 'a' - 'A';
			break;
		}
		else
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
	}
	if (initial == 'A')
	{
		num_a = num;
		for (int i = 0; i < num; i++)
		{
			a[i] = num - i;
		}
	}
	if (initial == 'B')
	{
		num_b = num;
		for (int i = 0; i < num; i++)
		{
			b[i] = num - i;
		}
	}
	if (initial == 'C')
	{
		num_c = num;
		for (int i = 0; i < num; i++)
		{
			c[i] = num - i;
		}
	}
	while (1)
	{
		cout << "请输入目标柱<A-C>:" << endl;
		cin >> target;
		if ((target >= 'A'&&target <= 'C'&&target != initial) || (target >= 'a'&&target <= 'c'&&target != initial + 32))
		{
			if (target >= 'a')
				target -= 'a' - 'A';
			break;
		}
		else
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
	}
	while (1)
	{
		cout << "请输入移动速度（0-5：0-按回车单步演示 1-延时最长 5-延时最短）" << endl;
		cin >> speed;
		if (!cin)
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else
		{
			if (speed >= 0 && speed <= 5)
				break;
		}
	}
	while (1)
	{
		cout << "请输入是否显示内部数组数值（0-不显示 1-显示）" << endl;
		cin >> print_flag;
		if (!cin)
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else
		{
			if (print_flag == 0 || print_flag==1)
				break;
		}
	}
	system("cls");
	cout << "从" << initial << "移动到" << target << "共" << num << "层，" << "延时设置为" << speed << "，";
	if (print_flag)
		cout << "显示内部数组" << endl;
	else
		cout << "不显示内部数组" << endl;
	my_interface();
	Hanoi(num, initial, target); 
	return 0;
}
