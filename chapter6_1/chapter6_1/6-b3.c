/*1553449 王志业 3班*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void merge(int *list_a, int *list_b, int *list_c)
{
	int i = 0, j = 0, anew = 0;
	while (*(list_c + anew) != -1)
	{
		while (*(list_a + i) != -1 && *(list_b + j) != -1)
		{
			if (*(list_a + i) >= *(list_b + j))
			{
				if (anew == 0 || *(list_c + anew - 1) != *(list_a + i))
				{
					*(list_c + anew) = *(list_a + i);
					anew++;
				}
				i++;
			}
			else
			{
				if (*(list_c + anew - 1) != *(list_b + j))
				{
					*(list_c + anew) = *(list_b + j);
					anew++;
				}
				j++;
			}
		}
		while (*(list_a + i) != -1 && *(list_b + j) == -1)
		{
			if (*(list_c + anew - 1) != *(list_a + i))
			{
				*(list_c + anew) = *(list_a + i);
				anew++;
			}
			i++;
		}
		while (*(list_a + i) == -1 && *(list_b + j) != -1)
		{
			if (*(list_c + anew - 1) != *(list_b + j))
			{
				*(list_c + anew) = *(list_b + j);
				anew++;
			}
			j++;
		}
		if (*(list_a + i) == -1 && *(list_b + j) == -1)
			*(list_c + anew) = -1;
	}
}
int main()
{
	int a[21] ;
	int b[21] ;
	int c[41];
	int i = 0;
    printf("输入第一个数组降序，以-1结束：\n");
	while (scanf("%d",a+i))
	{
		if (*(a + i) == -1)
			break;
		i++;
	}
	printf("输入第二个数组降序，以-1结束：\n");
	i = 0;
	while (scanf("%d",b+i))
	{
		if (*(b + i) == -1)
			break;
		i++;
	}
	i = 0;
	printf("第一个数组的内容为：\n");
	while (*(a + i) != -1)
	{
		printf("%d ",*(a + i));
		i++;
	}
	i = 0;
	printf("\n第二个数组的内容为：\n");
	while (*(b + i) != -1)
	{
		printf("%d ",*(b + i));
		i++;
	}

	merge(a, b, c);
	i = 0;
	printf("\n合并后的数组：\n") ;
	while (*(c + i) != -1)
	{
		printf("%d ",*(c + i));
		i++;
	}
	printf("\n");
	return 0;
}
