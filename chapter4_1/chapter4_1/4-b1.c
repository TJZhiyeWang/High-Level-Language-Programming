/*王志业 1553449 3班*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int zeller(int year, int month, int day)
{
	int w, c, y, m, d;
	if (month < 3)
	{
		year--;
		m = month + 12;
	}
	else
		m = month;
	d = day;
	c = year / 100;
	y = year - 100 * c;
	w = (y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1);
	while (w < 0)
		w += 7;
	w %= 7;
	return w;
}

int main()
{
	int y, m, d;
	while (1)
	{
		printf("请输入年(1900-2100)、月、日:\n");
		scanf("%d%d%d", &y, &m, &d);
		if (y < 1900 || y>2100)
		{
			printf("年份超出范围\n");
			continue;
		}
		if (m > 12 || m < 1 || d < 1)
		{
			printf("非法\n");
			continue;
		}
		if (m != 2)
		{
			switch (m)
			{
				case 1:
					if (d > 31)
					{
						printf("非法\n");
						continue;
					}
					break;
				case 3:
					if (d > 31)
					{
						printf("非法\n");
						continue;
					}
					break;
				case 4:
					if (d > 30)
					{
						printf("非法\n");
						continue;
					}
					break;
				case 5:
					if (d > 31)
					{
						printf("非法\n");
						continue;
					}
					break;
				case 6:
					if (d > 30)
					{
						printf("非法\n");
						continue;
					}
					break;
				case 7:
					if (d > 31)
					{
						printf("非法\n");
						continue;
					}
					break;
				case 8:
					if (d > 31)
					{
						printf("非法\n");
						continue;
					}
					break;
				case 9:
					if (d > 30)
					{
						printf("非法\n");
						continue;
					}
					break;
				case 10:
					if (d > 31)
					{
						printf("非法\n");
						continue;
					}
					break;
				case 11:
					if (d > 30)
					{
						printf("非法\n");
						continue;
					}
					break;
				case 12:
					if (d > 31)
					{
						printf("非法\n");
						continue;
					}
					break;
			}
		}
		else
		{
			if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
			{
				if (d > 29)
				{
					printf("非法\n");
					continue;
				}
			}
			else
			{
				if (d > 28)
				{
					printf("非法\n");
					continue;
				}
			}
		}
		switch (zeller(y, m, d))
		{
			case 0: printf("星期日\n"); break;
			case 1: printf("星期一\n"); break;
			case 2: printf("星期二\n"); break;
			case 3: printf("星期三\n"); break;
			case 4: printf("星期四\n"); break;
			case 5: printf("星期五\n"); break;
			case 6: printf("星期六\n"); break;
		}
		break;
	}
	return 0;
}
