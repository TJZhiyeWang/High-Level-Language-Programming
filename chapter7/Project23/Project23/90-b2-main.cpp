/*1553449 3班 王志业*/
#define _CRT_SECURE_NO_WARNINGS
#include "90-b2.h"
#include "cmd_console_tools.h"
//menu
void menu()
{
	system("cls");
	cout << "================================================================\n"
		<< "1.字符界面下的数独求解\n"
		<< "2.cmd伪图形界面下的数独求解\n"
		<< "3.在图形界面下自动求解\n"
		<< "4.加分项1\n"
		<< "0.退出\n"
		<< "==================================================================";
}
void q1(char *filename)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	sdk sdkarray[9][9];
	int m, n, row, line, num;
	char choice[4];
	sdk *p = NULL, *head = NULL, *q = NULL;
	system("cls");

	read_file(sdkarray, filename);
	while (1)
	{
		int flag = 0;
		system("cls");
		draw(sdkarray);
		gotoxy(hout, 0, 15);
		for (n = 0; n < 9; n++)
			for (m = 0; m < 9; m++)
			{
				if (sdkarray[n][m].num != 0)
					conflict1(sdkarray, n, m);
				else
					flag = 1;

			}
		if (flag == 0)
		{
			for (n = 0; n < 9; n++)
				for (m = 0; m < 9; m++)
					if (conflict1(sdkarray, n, m)>0)
						flag = 1;
			if (flag == 0)
			{
				cout << "恭喜完成";
				break;
			}
		}

		cout << "请按照'1a7'格式输入：";
		cin >> choice;
		if (strcmp(choice, "bk") == 0)
		{
			if (p == NULL)
				cout << "已经退回第一步";
			else
			{
				back(&p, &q);
				if (p == NULL)
					head = NULL;
			}

		}
		else
		{
			plot(sdkarray, choice, &row, &line, &num);
			chain(sdkarray, row, line, &p, &q, &head);
		}

	}
}
void q2()
{
	system("cls");
	char **result;
	int count/*当前目录下的文件数量*/;
	result = EnumFiles(&count);
	q1(display(result, count));
}
void q3()
{
	system("cls");
	char **result;
	int count/*当前目录下的文件数量*/;
	result = EnumFiles(&count);
	sdk sdkarray[9][9];
	sdk *p = NULL, *head = NULL, *q = NULL;
	read_file(sdkarray, display(result, count));
	draw1(sdkarray);
	find(sdkarray, &p, &q, &head);
}
void q4()
{
	system("cls");
	char **result;
	int count/*当前目录下的文件数量*/;
	result = EnumFiles(&count);
	sdk sdkarray[9][9];
	sdk *p = NULL, *head = NULL, *q = NULL;
	read_file(sdkarray, display(result, count));
	draw1(sdkarray);
	keyboard(sdkarray, &p, &q, &head);
}
int main()
{
	char n;
	menu();
	while (1)
	{
		switch (n = _getch())
		{
			case '1':
			{
				system("cls");
				char filename[33];
				cout << "请输入要打开的文件名" << endl;
				cin >> filename;
				q1(filename);
				continue;
			}
			case '2':
			{
				q2();
				continue;
			}
			case '3':
			{
				q3();
				continue;
			}
			case '4':
			{
				q4();
				continue;
			}
			case '0':
				break;
			default:
				continue;
		}

	}

	return 0;
}

