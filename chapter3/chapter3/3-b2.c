/*王志业 3班 1553449*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int inte;
	scanf("%d", &inte);
	printf("万位：%d\n", inte / 10000);
	inte -= inte / 10000 * 10000;
	printf("千位：%d\n", inte / 1000);
	inte -= inte / 1000 * 1000;
	printf("百位：%d\n", inte / 100);
	inte -= inte / 100 * 100;
	printf("十位：%d\n", inte / 10);
	inte -= inte / 10 * 10;
	printf("个位：%d", inte);
	return 0;
}