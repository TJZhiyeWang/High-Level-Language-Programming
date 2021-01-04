/*王志业 3班 1553449*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	double x, y;
	int h;
	printf("坐标\n");
	scanf("%lf%lf", &x, &y);
	printf("该点高度为\n");
	if (x == 0)
		h = 0;
	else if (y == 0)
		h = 0;
	else if (x > 0)
	{
		if (y > 0)
			h = 1;
		else
			h = 4;
	}
	else
	{
		if (y > 0)
			h = 2;
		else
			h = 3;
	}
	printf("%d",h);
	return 0;
}