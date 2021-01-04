/*1553449 3班 王志业*/
#define _CRT_SECURE_NO_WARNINGS
#include "90-b1.h"
//寻找数组中某一位置相邻行列中三个及以上颜色相同的,并统计可消除个数,返回消除球的个数。
int find_dis(ball inside_array[][9], int tar_x, int tar_y, int row, int line)
{
	int xcount = 0, ycount = 0;
	int i;
	xcount = 1;
	ycount = 1;
	inside_array[tar_x][tar_y].dis++;
	for (i = 1; i < row - tar_x; i++)
	{
		if (inside_array[i + tar_x][tar_y].cor == inside_array[tar_x][tar_y].cor)
		{
			xcount++;
			inside_array[i + tar_x][tar_y].dis++;
		}
		else
			break;
	}
	for (i = -1; i >= -tar_x; i--)
	{
		if (inside_array[i + tar_x][tar_y].cor == inside_array[tar_x][tar_y].cor)
		{
			xcount++;
			inside_array[i + tar_x][tar_y].dis++;
		}
		else
			break;
	}
	if (xcount < 3)
	{
		xcount = 0;
		inside_array[tar_x][tar_y].dis--;
		if (inside_array[tar_x + 1][tar_y].dis>0 && inside_array[tar_x + 1][tar_y].cor == inside_array[tar_x][tar_y].cor)
			inside_array[tar_x + 1][tar_y].dis--;
		if (inside_array[tar_x - 1][tar_y].dis > 0 && inside_array[tar_x - 1][tar_y].cor == inside_array[tar_x][tar_y].cor)
			inside_array[tar_x - 1][tar_y].dis--;
	}
	if (xcount == 0)
		inside_array[tar_x][tar_y].dis++;
	for (i = 1; i < line - tar_y; i++)
	{
		if (inside_array[tar_x][i + tar_y].cor == inside_array[tar_x][tar_y].cor)
		{
			ycount++;
			inside_array[tar_x][i + tar_y].dis++;
		}
		else
			break;
	}
	for (i = -1; i >= -tar_y; i--)
	{
		if (inside_array[tar_x][i + tar_y].cor == inside_array[tar_x][tar_y].cor)
		{
			ycount++;
			inside_array[tar_x][i + tar_y].dis++;
		}
		else
			break;
	}
	if (ycount < 3)
	{
		ycount = 0;
		if (xcount == 0)
			inside_array[tar_x][tar_y].dis--;
		if (inside_array[tar_x][tar_y - 1].dis>0 && inside_array[tar_x][tar_y - 1].cor == inside_array[tar_x][tar_y].cor)
			inside_array[tar_x][tar_y - 1].dis--;
		if (inside_array[tar_x][tar_y + 1].dis > 0 && inside_array[tar_x][tar_y + 1].cor == inside_array[tar_x][tar_y].cor)
			inside_array[tar_x][tar_y + 1].dis--;
	}
	/*}	*/
	if (ycount >= 3 && xcount >= 3)
		return xcount + ycount - 1;
	return xcount + ycount;

}
//指定位置若连成三个及以上将内部数组对应位置置0
void disappear(ball inside_array[][9], int row, int line)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < line; j++)
		{
			if (inside_array[i][j].dis>0)
				inside_array[i][j].cor = 0;
		}
	}
}
//碰到位置为0则将上面的数组值（不为0）赋值到下面，若上面为0则再往上找,并挪下出现动画
void up_down(ball inside_array[][9], int tar_x, int tar_y, int lowest)
{

	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	if (tar_x < 0)
		return;
	if (inside_array[tar_x][tar_y].cor == 0)
	{
		up_down(inside_array, tar_x - 1, tar_y, lowest);
	}
	if (inside_array[tar_x][tar_y].cor >0 && tar_x < lowest)
	{
		inside_array[tar_x + 1][tar_y].cor = inside_array[tar_x][tar_y].cor;
		inside_array[tar_x][tar_y].cor = 0;
		showstr(hout, 2 + tar_y * 4, (tar_x + 1) * 2, "  ", COLOR_HWHITE, COLOR_HWHITE);

		Sleep(50);//延时0.05秒
		showstr(hout, 2 + tar_y * 4, (tar_x + 1) * 2 + 1, "○", inside_array[tar_x + 1][tar_y].cor, COLOR_HWHITE);
		Sleep(50);
		showstr(hout, 4 * tar_y + 2, tar_x * 2 + 3, "─", COLOR_HWHITE, COLOR_BLACK);
		Sleep(50);
		showstr(hout, 2 + tar_y * 4, (tar_x + 2) * 2, "○", inside_array[tar_x + 1][tar_y].cor, COLOR_HWHITE);
	}

}
//同上，但无动画
void up_down1(ball inside_array[][9], int tar_x, int tar_y, int lowest)
{
	if (tar_x < 0)
		return;
	if (inside_array[tar_x][tar_y].cor == 0)
	{
		up_down1(inside_array, tar_x - 1, tar_y, lowest);
	}
	if (inside_array[tar_x][tar_y].cor > 0 && tar_x < lowest)
	{
		inside_array[tar_x + 1][tar_y].cor = inside_array[tar_x][tar_y].cor;
		inside_array[tar_x][tar_y].cor = 0;
	}
}
//在特定位置填入一个随机颜色的球
void reload(ball inside_array[][9], int tar_x, int tar_y, int row, int line)
{
	srand((unsigned int)time(0));
	if (inside_array[tar_x][tar_y].cor == 0)
		inside_array[tar_x][tar_y].cor = rand() % 9 + 1;
}
//将一个数组的dis值重置为0
void reset_dis(ball inside_array[][9], int row, int line)
{
	int i, j;
	for (i = 0; i < row; i++)
		for (j = 0; j < line; j++)
			inside_array[i][j].dis = 0;
}
//将一个数组的cha值重置为0
void reset_cha(ball inside_array[][9], int row, int line)
{
	int i, j;
	for (i = 0; i < row; i++)
		for (j = 0; j < line; j++)
			inside_array[i][j].cha = 0;
}
//找出某一位置所有可以互换的彩球
void find_cha(ball inside_array[][9], int tar_x, int tar_y, int row, int line)
{
	int temp;
	if (tar_x > 0)
	{
		temp = inside_array[tar_x][tar_y].cor;
		inside_array[tar_x][tar_y].cor = inside_array[tar_x - 1][tar_y].cor;
		inside_array[tar_x - 1][tar_y].cor = temp;
		if (find_dis(inside_array, tar_x, tar_y, row, line)>0)
		{
			inside_array[tar_x][tar_y].cha = 1;
			inside_array[tar_x - 1][tar_y].cha = 1;
		}
		temp = inside_array[tar_x][tar_y].cor;
		inside_array[tar_x][tar_y].cor = inside_array[tar_x - 1][tar_y].cor;
		inside_array[tar_x - 1][tar_y].cor = temp;
	}
	reset_dis(inside_array, row, line);
	if (tar_x < row - 1)
	{
		temp = inside_array[tar_x][tar_y].cor;
		inside_array[tar_x][tar_y].cor = inside_array[tar_x + 1][tar_y].cor;
		inside_array[tar_x + 1][tar_y].cor = temp;
		if (find_dis(inside_array, tar_x, tar_y, row, line)>0)
		{
			inside_array[tar_x][tar_y].cha = 1;
			inside_array[tar_x + 1][tar_y].cha = 1;
		}
		temp = inside_array[tar_x][tar_y].cor;
		inside_array[tar_x][tar_y].cor = inside_array[tar_x + 1][tar_y].cor;
		inside_array[tar_x + 1][tar_y].cor = temp;
	}
	reset_dis(inside_array, row, line);
	if (tar_y > 0)
	{
		temp = inside_array[tar_x][tar_y].cor;
		inside_array[tar_x][tar_y].cor = inside_array[tar_x][tar_y - 1].cor;
		inside_array[tar_x][tar_y - 1].cor = temp;
		if (find_dis(inside_array, tar_x, tar_y, row, line) > 0)
		{
			inside_array[tar_x][tar_y].cha = 1;
			inside_array[tar_x][tar_y - 1].cha = 1;
		}
		temp = inside_array[tar_x][tar_y].cor;
		inside_array[tar_x][tar_y].cor = inside_array[tar_x][tar_y - 1].cor;
		inside_array[tar_x][tar_y - 1].cor = temp;
	}
	reset_dis(inside_array, row, line);
	if (tar_y < line - 1)
	{
		temp = inside_array[tar_x][tar_y].cor;
		inside_array[tar_x][tar_y].cor = inside_array[tar_x][tar_y + 1].cor;
		inside_array[tar_x][tar_y + 1].cor = temp;
		if (find_dis(inside_array, tar_x, tar_y, row, line)>0)
		{
			inside_array[tar_x][tar_y].cha = 1;
			inside_array[tar_x][tar_y + 1].cha = 1;
		}
		temp = inside_array[tar_x][tar_y].cor;
		inside_array[tar_x][tar_y].cor = inside_array[tar_x][tar_y + 1].cor;
		inside_array[tar_x][tar_y + 1].cor = temp;
	}
	reset_dis(inside_array, row, line);
}