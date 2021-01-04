/*1553449 王志业 3班*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	double c, f;
	scanf("%lf", &f);
	c = 5.0 / 9 * (f - 32);
	printf("华氏温度%.2lf所对应的摄氏温度为%.2lf", f, c);
	return 0;
}