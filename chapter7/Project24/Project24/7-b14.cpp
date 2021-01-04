/*1553449 3班 王志业*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;
int main(int ag,char *argv[])
{
	unsigned char ch[17],*p=ch;
	char fname[99];
	ifstream fin;
	short row = 0, i = 0,count=0,j;
	if (ag == 2)
		strcpy(fname, argv[1]);
	else if (ag == 1)
	{
		cout << "请输入要打开的文件名称" << endl;
		cin >> fname;
	}
	else
		cout << "输入有误" << endl;
	fin.open(fname, ios::in);
	if (fin.is_open() == 0)
	{
		cout << "open failed" << endl;
		return -1;
	}
	while (!fin.eof())
	{
		p[i] = fin.get();
		
		if (i == 0)
		{
			printf("%08x", row);
			cout << ": ";
		}
		printf("%02x", p[i]);
		cout << " ";
		if (i == 7)
			cout << "- ";
		if (i == 15||fin.peek()==EOF)
		{
			cout << "  ";
			for (j = 0; j <= i; j++)
			{
				if (p[j] > 126 || p[j] < 33)
					cout << ".";
				else
				cout << p[j];
			}
			cout << endl;
			i = 0;
			row += 16;
			continue;
		}
		i++;
		
		
	}
	fin.close();
	return 0;
}