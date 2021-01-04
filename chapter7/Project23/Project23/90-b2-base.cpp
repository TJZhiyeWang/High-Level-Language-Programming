/*1553449 3班 王志业*/
#define _CRT_SECURE_NO_WARNINGS
#include "90-b2.h"
#include "cmd_console_tools.h"
//judge if there are conflicts in the array ,return the number of mistakes 
int conflict(sdk sdkarray[][9], int tar_x, int tar_y)
{
	int n, m, k, t, count = 0;
	for (n = 0; n < 9; n++)
		if (sdkarray[tar_x][tar_y].num == sdkarray[tar_x][n].num && tar_y != n)
		{
			count++;
			for (m = 0; m < 9; m++)
			{
				turn_white(sdkarray, tar_x, m);
				if (sdkarray[tar_x][tar_y].num == sdkarray[tar_x][n].num && tar_y != n)
					turn_red(sdkarray, tar_x, n);

			}
			turn_red(sdkarray, tar_x, tar_y);
			break;
		}
	for (n = 0; n < 9; n++)
		if (sdkarray[tar_x][tar_y].num == sdkarray[n][tar_y].num && tar_x != n)
		{
			count++;
			for (m = 0; m < 9; m++)
			{
				turn_white(sdkarray, m, tar_y);
				if (sdkarray[tar_x][tar_y].num == sdkarray[n][tar_y].num && tar_x != n)
					turn_red(sdkarray, n, tar_y);

			}
			turn_red(sdkarray, tar_x, tar_y);
			break;
		}

	for (k = tar_x / 3 * 3; k < tar_x / 3 * 3 + 3; k++)
		for (t = tar_y / 3 * 3; t < tar_y / 3 * 3 + 3; t++)
			if (sdkarray[tar_x][tar_y].num == sdkarray[k][t].num && tar_x != k&&tar_y != t)
			{
				count++;
				for (k = tar_x / 3 * 3; k < tar_x / 3 * 3 + 3; k++)
					for (t = tar_y / 3 * 3; t < tar_y / 3 * 3 + 3; t++)
					{
						turn_white(sdkarray, k, t);
						if (sdkarray[tar_x][tar_y].num == sdkarray[k][t].num && tar_x != k&&tar_y != t)
							turn_red(sdkarray, k, t);

					}
				turn_red(sdkarray, tar_x, tar_y);
			}

	return count;

}
int conflict1(sdk sdkarray[][9], int tar_x, int tar_y)
{
	int n, k, t, count = 0;
	for (n = 0; n < 9; n++)
		if (sdkarray[tar_x][tar_y].num == sdkarray[tar_x][n].num && tar_y != n)

			count++;


	for (n = 0; n < 9; n++)
		if (sdkarray[tar_x][tar_y].num == sdkarray[n][tar_y].num && tar_x != n)

			count++;


	for (k = tar_x / 3 * 3; k < tar_x / 3 * 3 + 3; k++)
		for (t = tar_y / 3 * 3; t < tar_y / 3 * 3 + 3; t++)
			if (sdkarray[tar_x][tar_y].num == sdkarray[k][t].num && tar_x != k&&tar_y != t)

				count++;


	return count;

}
//建立一个双向链表来记录每次更改的数字
void chain(sdk sdkarray[][9], int row, int line, sdk **p, sdk **q, sdk **head)
{
	*p = &sdkarray[row][line];

	if ((*head) == NULL)
	{
		*head = *p;

	}
	else
	{
		(*p)->lnext = *q;

		(*q)->rnext = *p;
	}

	*q = *p;

}
//后退一步（不可删除节点）
void back(sdk **p, sdk **q)
{
	(*p)->num = 0;
	*p = (*q)->lnext;
	*q = *p;


}
//搜索算法：从（0，0）尝试每一个num==0的位置代入可以使conflict==0的数字
void find(sdk sdkarray[][9], sdk **p, sdk **q, sdk **head)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int i, j;
	for (i = 0; i < 9; i++)
		for (j = 0; j < 9; j++)
		{
			if (sdkarray[i][j].num == 0)
			{
                *p = &sdkarray[i][j];
				if (*head == NULL)
					*head = *p;
				else
				{
					(*p)->lnext = *q;
					(*q)->rnext = *p;
				}
				*q = *p;
				while (1)
				{
					if ((*p)->try_num != 10)
					{
                        (*p)->num = (*p)->try_num;
						mark(sdkarray, (*p)->x, (*p)->y);
						if (conflict1(sdkarray, i, j) != 0)
						{
							(*p)->try_num++;
							continue;
						}
						mark_back(sdkarray, (*p)->x, (*p)->y);
						find(sdkarray, p, q, head);
					}
					else
					{
						if ((*p)->lnext == NULL)
						{
							setcolor(hout, COLOR_BLACK, COLOR_HWHITE);
							gotoxy(hout, 2, 30);
							cout << "wrong!!!";
							exit(-1);
						}
						else
						{
							(*p)->try_num = 1;
							(*p)->num = 0;
							mark_back(sdkarray, (*p)->x, (*p)->y);
							*p = (*p)->lnext;
							*q = *p;
							(*p)->try_num++;
							return;
						}
					}
				}
			}
		}
	cout << endl << "congratulations!!!";


}
//加分题1：通过键盘上下左右箭头控制选择方框按回车输入数字按Bacspace回退一步
void keyboard(sdk sdkarray[][9], sdk **p, sdk **q, sdk **head)
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	int i = 0, j = 0;//记录当前的位置
	mark(sdkarray, i, j);
	while (1)
	{
		switch (_getch())
		{
			case 72:
			{
				if (i > 0)
				{
					i--;
					mark(sdkarray, i, j);
					mark_back(sdkarray, i + 1, j);
				}
				continue;
			}

			case 80:
			{
				if (i < 8)
				{
					i++;
					mark(sdkarray, i, j);
					mark_back(sdkarray, i - 1, j);
				}
				continue;
			}
			case 75:
			{
				if (j > 0)
				{
					j--;
					mark(sdkarray, i, j);
					mark_back(sdkarray, i, j + 1);
				}
				continue;
			}
			case 77:
			{
				if (j < 8)
				{
					j++;
					mark(sdkarray, i, j);
					mark_back(sdkarray, i, j - 1);
				}
				continue;
			}
			case 13:
			{
				if (sdkarray[i][j].p == '0')
				{
					chain(sdkarray, i, j, p, q, head);
					int num;
					while (1)
					{
						setcolor(hout, COLOR_BLACK, COLOR_HWHITE);
						gotoxy(hout, 2, 30);
						cout << "请输入当前位置要更改的数字";
						num = _getch() - '0';
						gotoxy(hout, 2, 30);
						cout << "                               ";
						if (num > 0 && num < 10)
						{
							sdkarray[i][j].num = num;
							mark(sdkarray, i, j);
							break;
						}
						gotoxy(hout, 2, 30);
						cout << "输入有误请重新输入";

						cout << "                               ";
					}
				}
				else
				{
					setcolor(hout, COLOR_BLACK, COLOR_HWHITE);
					gotoxy(hout, 2, 30);
					cout << "该位置数字不可更改";
					cout << "                               ";
				}
				continue;
			}
			case 8:
			{
				if ((*p)->lnext == NULL)
					cout << "已经退回第一步";
				else
				{
					back(p, q);
					mark_back(sdkarray, i, j);
					mark(sdkarray, (*p)->x, (*p)->y);
					i = (*p)->x;
					j = (*p)->y;
				}
			}
			continue;
			default:
				continue;
		}
	}
}
