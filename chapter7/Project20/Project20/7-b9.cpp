/*1553449 3班 王志业*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdio>
#include <conio.h>
#include <iomanip>
using namespace std;
struct stu
{
	struct stu *next;
	char *name;
};
int main(int argc, char *argv[])
{
	int M = 0, N = 0, count = 0, i, j, max = 0, flag = 0;
	ifstream fin1, fin2;
	ofstream fout;
	char s1[30], s2[30], s3[30];
	stu *head = NULL, *q = NULL, *p = NULL;
	if (argc < 3)
	{
		cerr << "请输入三个参数" << endl;
		return -1;
	}
	strcpy(s1, argv[1]);
	strcpy(s2, argv[2]);
	strcpy(s3, argv[3]);
	fin1.open(s1, ios::in);
	if (fin1.is_open() == 0)
	{
		cout << "can't open1" << endl;
		return -1;
	}
	while (1)
	{
		q = p;
		p = new(nothrow) stu;
		if (p == NULL)
		{
			cout << "no memory" << endl;
			return -1;
		}
		if (head == NULL)
			head = p;
		else
			q->next = p;
		char str[9] = "\0\0\0\0\0\0\0\0";
		fin1.getline(str, 8, '\n');



		if (strcmp(str, "NULL") == 0)
		{

			q->next = NULL;
			break;
		}
		N++;
		p->name = new(nothrow) char[strlen(str) + 1];
		if (p->name == NULL)
		{
			cout << "no memory" << endl;
			delete p;
			return -1;
		}

		strcpy(p->name, str);

	}
	fin1.close();


	fin2.open(s2, ios::in);
	if (fin2.is_open() == 0)
	{
		cout << "can't open" << endl;
		return -1;
	}
	while (1)
	{

		char ch[17] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
		int len, flag = 0;

		fin2.getline(ch, 17, '\n');
		len = strlen(ch);

		if (len > max)
			max = len - 1;

		for (i = 0; i < len; i++)
		{
			if (ch[i] == 'Y')
			{
				flag = 1;
				M++;
			}
		}

		if (flag == 0)
			break;
		count++;
	}
	fin2.close();
	fin2.open(s2, ios::in);
	if (fin2.is_open() == 0)
	{
		cout << "can't open" << endl;
		return -1;
	}
	short *room;
	room = new(nothrow) short[count + 1];
	if (room == NULL)
	{
		cout << "no memory" << endl;
		return -1;
	}
	for (i = 0; i < count; i++)
	{
		char ch[17];
		int len, flag = 0;
		room[i] = 0;
		fin2.getline(ch, 17, '\n');
		len = strlen(ch);
		for (j = 0; j < len; j++)
		{
			if (ch[j] == 'Y')
				room[i] += (short)pow(2.0, len - 1 - j);

		}
	}
	room[count] = 0;
	fin2.close();
	if (N > M)
	{
		cout << "无法分配座位";
		return 0;
	}
	fout.open(s3, ios::out);
	if (fout.is_open() == 0)
	{
		cout << "can't open" << endl;
		fout.close();
		return -1;
	}
	cout << "请选择排列方式，1代表先行后列顺序分配，2代表随机位置分配" << endl;
	int choice = int(_getch());
	switch (choice)
	{
		case '1':
		{
			p = head;
			for (i = 0; i < count; i++)
			{
				fout << "|    /   ";
				for (j = max; j >= 0; j--)
				{
					if ((room[i] & (0x0001 << j))>0 && flag == 0)
					{
						fout << "|" << setw(8) << p->name;
						p = p->next;
						if (p == NULL)

							flag = 1;
					}
					else
						fout << "|    /   ";
				}
				fout << "|" << endl;
			}
		};
		break;
		case '2':
		{
			int na = N;
			int num = M;
			p = head;
			srand((unsigned int)time(0));
			for (i = 0; i < count; i++)
			{
				fout << "|    /   ";
				for (j = max; j >= 0; j--)
				{
					if ((room[i] & (0x0001 << j))>0 && na > 0)
					{

						if ((rand() % num + 1) <= na)
						{
							fout << "|" << setw(8) << p->name;
							p = p->next;
							na--;
						}
						else
							fout << "|    /   ";
						num--;

					}
					else
						fout << "|    /   ";
				}
				fout << "|" << endl;
			}

		}
		break;

	}
	fout.close();
	delete room;
	p = head;
	while (p != NULL)
	{
		q = p->next;
		delete p->name;
		delete p;
		p = q;
	}
	return(0);



}