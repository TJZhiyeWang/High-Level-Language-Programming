/*1553449 王志业 3班*/
#define _CRT_SECURE_NO_WARNINGS
#include "90-b3.h"
#include "cmd_console_tools.h"

//读取现有的闹钟列表，返回头指针,尾指针
void read_file(alarm **head, alarm **q)
{
	fstream fin;
	alarm  *p = NULL;
	fin.open("clock.txt", ios::in | ios::binary | ios::out);
	if (fin.is_open() == 0)
	{
		return;
	}
	while (fin.peek() != EOF)
	{
		p = new(nothrow) alarm;
		if (p == NULL)
			cout << "no memory";
		if (*head == NULL)
			*head = p;
		else
			(*q)->next = p;
		*q = p;

		fin >> p->type >> p->hour >> p->min;

	}
	if ((*q) != NULL)
		(*q)->next = NULL;
	fin.close();
}
//保存现有的闹钟
void save_file(alarm *head)
{
	alarm *p;
	fstream fin;
	fin.open("clock.txt", ios::out | ios::binary);
	if (fin.is_open() == 0)
	{
		cout << "open failed";
	}
	p = head;
	while (p)
	{
		fin << p->type << " " << p->hour << " " << p->min << " ";
		p = p->next;
	}
	fin.close();
}
//建立一个闹钟,给入尾节点和类型
void set_alarm(char type, alarm **tail)
{
	system("cls");
	alarm *add;
	add = new(nothrow) alarm;
	if (add == NULL)
		cout << "no memory";

	switch (type)
	{
		case '1':
		{
			add->type = 'e';
			break;
		}
		case '2':
		{
			add->type = 'w';
			break;
		}
		case '3':
		{
			add->type = 's';
			break;
		}
		default:
		{
			delete add;
			cout << "输入有误，三秒后返回";
			Sleep(3000);
			return;
		}

	}
	cout << "请切换英语输入法以\"小时:分钟\"的形式输入闹钟时间";
	char s[3];
	cin.get(s, 3, ':');
	add->hour = atoi(s);
	cin.ignore();
	cin.get(s, 3, 13);
	add->min = atoi(s);
	if (*tail != NULL)
	{
		(*tail)->next = add;
		*tail = add;
	}
	else
		*tail = add;
	(*tail)->next = NULL;
	cout << "设置成功，进入功能1钟表界面生效，三秒后返回主界面";
	Sleep(3000);
}
void alarm_clock()
{
	system("cls");
	alarm *tail = NULL, *head = NULL;
	read_file(&head, &tail);
	alarm_menu();
	set_alarm(_getch(), &tail);
	if (head == NULL)
		head = tail;
	save_file(head);
}
void alarm_menu()
{
	cout << "************************************\n"
		<< "您想建立什么类型的闹钟？\n"
		<< "1.每日闹钟(Everyday)\n"
		<< "2.工作日闹钟(Workday)\n"
		<< "3.单次闹钟(Single)\n"
		<< "*************************************\n"
		<< "请输入您的选择：";
}

//检查现在时间是否到播放闹钟，是则播放
void is_time(tm tt)
{
	alarm *p = NULL, *tail = NULL, *head = NULL, *q = NULL;
	read_file(&head, &tail);
	p = head;

	while (p)
	{
		if (p->hour == tt.tm_hour&&p->min == tt.tm_min)
		{
			switch (p->type)
			{
				case 'e':
					PlaySound("test.wav", NULL, SND_ALIAS | SND_ASYNC);
					Sleep(10000);
					break;
				case 's':
				{
					PlaySound("test.wav", NULL, SND_ALIAS | SND_ASYNC);
					Sleep(10000);
					if (q != NULL)
					{
						q->next = p->next;
						delete p;
						p = q->next;
					}
					else
					{
						head = NULL;
						delete p;

					}
					continue;
				}
				case 'w':
				{
					if (tt.tm_wday < 5)
					{
						PlaySound("test.wav", NULL, SND_ALIAS | SND_ASYNC);
						Sleep(10000);
					}
					else
						break;
				}


			}

		}
		q = p;
		p = p->next;
	}
}