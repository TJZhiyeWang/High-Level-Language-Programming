/*王志业 3班 1553449*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int x, temp, i = 1;
	printf("请输入一个【0。。。99999】间的整数\n");
	scanf("%d", &x);
	temp = x;
	if ((temp /= 10) >= 1)
		i++;
	if ((temp /= 10) >= 1)
		i++;
	if ((temp /= 10) >= 1)
		i++;
	if ((temp /= 10) >= 1)
		i++;
	printf("%d位数\n", i);
	temp = x;
	printf("正序输出\n");
	if (i >= 5)
	{
		printf("%d ", temp / 10000);
		temp -= temp / 10000 * 10000;
	}
	if (i >= 4)
	{
		printf("%d ", temp / 1000);
		temp -= temp / 1000 * 1000;
	}
	if (i >= 3)
	{
		printf("%d ", temp / 100);
		temp -= temp / 100 * 100;
	}
	if (i >= 2)
	{
		printf("%d ", temp / 10);
		temp -= temp / 10 * 10;
	}
	printf("%d\n", temp);
	printf("逆序输出\n");
	temp = x;
	if (temp >= 1)
	{
		printf("%d", temp % 10);
		temp /= 10;
	}
	if (temp >= 1)
	{
		printf(" %d", temp % 10);
		temp /= 10;
	}
	if (temp >= 1)
	{
		printf(" %d", temp % 10);
		temp /= 10;
	}
	if (temp >= 1)
	{
		printf(" %d", temp % 10);
		temp /= 10;
	}
	if (temp >= 1)
	{
		printf(" %d", temp % 10);
		temp /= 10;
	}
	printf("\n");
	return 0;
}