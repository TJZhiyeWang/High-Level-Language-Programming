/*1553449 王志业 3班*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
void input_int(int *num, int low, int high)
{
	char c;
	while (1)
	{
		if (scanf("%d",num)!=1)
		{
			while((c=getchar())!=EOF&&c!='\n');
		}
			
		else if (*num >= low && *num <= high)
			break;
	}
}
void input_int_1(int *num, int low)
{
	char c;
	while (1)
	{
		if (scanf("%d",num)!=1)
		{
			while((c=getchar())!=EOF&&c!='\n');
		}
		else if (*num >= low)
			break;
	}
}
void move(int *pa, int n, int m)
{
	int temp,k,i;
	for ( k = 1; k <= m; k++)
	{
		temp = *(pa + n - 1);
		for (i = n - 1; i >= 1; i--) 
		{
			*(pa + i) = *(pa + i - 1);
		}
		*pa = temp;
	}
}
int main()
{
	int n, m,i;
	int array[20];
	char c;
	printf("请输入整数的数量n《10-20》：\n");
	input_int(&n, 10, 20);
	printf("请输入%d个整数：\n",n);
	for (i = 0; i < n; i++)
	{
		while (1)
		{
			
			
			if (scanf("%d",array+i)!=1)
			{
			  while((c=getchar())!=EOF&&c!='\n');
			}
			else if (*(array + i) > 0)
				break;
		}
	}
	printf("输入的整数序列为：\n");
    for (i = 0; i < n; i++)
	{
		printf("%d ",*(array + i));
	}
	printf("\n请输入位移m：");
	input_int_1(&m, 1);
	
	move(array, n, m);
	printf("移动后的整数序列为：\n");
	for (i = 0; i < n; i++)
		printf("%d ",*(array + i));
	printf("\n");
	return 0;
}
