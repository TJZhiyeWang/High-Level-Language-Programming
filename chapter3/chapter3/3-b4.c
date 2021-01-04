/*Õı÷æ“µ 3∞‡ 1553449*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define pi 3.1415926
int main()
{
	int a, b, t;
	float s;
	scanf("%d%d%d", &a, &b, &t);
	s = 0.5*a*b*sin(t / 180.0*pi);
	printf("%.3f", s);
	return 0;
}