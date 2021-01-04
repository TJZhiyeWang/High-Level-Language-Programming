/*1553449 3班 王志业*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int year, month, week, mday, i, j;
	printf("请输入年份(2000-2030)和月份(1-12) ：");
	scanf("%d%d", &year, &month);
	printf("请输入%d年%d月1日的星期(0-6表示星期日-星期六) ：", year, month);
	scanf("%d", &week);
	printf("\n");
	printf("%d年%d月的月历为：\n", year, month);
	printf("星期日  星期一  星期二  星期三  星期四  星期五  星期六\n");
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		mday = 31;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		mday = 30;
	else if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		mday = 29;
	else
		mday = 28;
	i = 1;
	printf("   ");
	if (week == 0)
		printf("%d", i);
	else
		printf(" ");
	for (j = 1; j <= week; j++)
	{
		if (j == week)
			printf("%8d", i);
		else
			printf("        ");
	}
	for (i = 2; i <= mday; i++)
	{
		if ((i + week) % 7 != 1)
		{
			printf("%8d", i);
			continue;
		}
		printf("\n");
		printf("%4d", i);
	}
	printf("\n");
	return 0;


}