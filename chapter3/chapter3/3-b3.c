/*王志业 1553449 3班*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
	double num;
	int s;
	scanf("%lf",&num);
	s = (int)floor(num*10e-10);
	printf("十亿位%d\n", s);
	s = (int)floor(num*10e-9) - s * 10;
	printf("亿位%d\n", s);
	s = (int)floor(num*10e-8) - (int)floor(num*10e-9) * 10;
	printf("千万位%d\n", s);
	s = (int)floor(num*10e-7) - (int)floor(num*10e-8) * 10;
	printf("百万位%d\n", s);
	s = (int)floor(num*10e-6) - (int)floor(num*10e-7) * 10;
	printf("十万位%d\n", s);
	s = (int)floor(num*10e-5) - (int)floor(num*10e-6) * 10;
	printf("万位%d\n", s);
	s = (int)floor(num*10e-4) - (int)floor(num*10e-5) * 10;
	printf("千位%d\n", s);
	s = (int)floor(num*10e-3) - (int)floor(num*10e-4) * 10;
	printf("百位%d\n", s);
	s = (int)floor(num*10e-2) - (int)floor(num*10e-3) * 10;
	printf("十位%d\n", s);
	s = (int)floor(num*10e-1) - (int)floor(num*10e-2) * 10;
	printf("个位%d\n", s);
	num += 1e-5;
	s = (int)floor(num * 10) - (int)floor(num) * 10;
	printf("十分位%d\n", s);
	s = (int)floor(num * 100) - (int)floor(num * 10) * 10;
	printf("百分位%d\n", s);
	return 0;

}