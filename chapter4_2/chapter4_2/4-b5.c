/*王志业 1553449 3班*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void int2str_inverse(int num)
{
	int flag = 0;
	if (num < 0)
	{
		flag = 1;
		num = -num;
	}
	if (num < 1)
		return;
	printf("%d ", num % 10);
	int2str_inverse(num / 10);
	if (flag == 1)
		printf("-");
}
int main()
{
	int num;
	while (1)
	{
		printf("请输入一个整数\n");
		if (!scanf("%d", &num))
		{
			setbuf(stdin,NULL);
			continue;
		}
		break;
	}
	int2str_inverse(num);
	return 0;
}