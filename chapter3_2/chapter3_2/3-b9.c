/*王志业 1553449 3班*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int y, m, d;
	printf("请输入年、月、日: \n");
	scanf("%d%d%d", &y, &m, &d);
	if (m > 12 || m < 1 || d < 1)
		printf("输入错误-月份不正确");
		
	else
		if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
			switch (m)
			{
				case 1:
					if (d > 31)
						printf("输入错误-日与月的关系非法 \n");
					else
						printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, d);
					break;
				case 2:
					if (d > 29)
						printf("输入错误-日与月的关系非法 \n");
					else
						printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, d+31);
					break;
				case 3:
					if (d > 31)
						printf("输入错误-日与月的关系非法 \n");
					else
						printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, d+60);
					break;
				case 4:
					if (d > 30)
						printf("输入错误-日与月的关系非法 \n");
					else
						printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, d+91);
					break;
				case 5:
					if (d > 31)
						printf("输入错误-日与月的关系非法 \n");
					else
						printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, d+121);
					break;
				case 6:
					if (d > 30)
						printf("输入错误-日与月的关系非法 \n");
					else
						printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, d+152);
					break;
				case 7:
					if (d > 31)
						printf("输入错误-日与月的关系非法 \n");
					else
						printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, d+182);
					break;
				case 8:
					if (d > 31)
						printf("输入错误-日与月的关系非法 \n");
					else
						printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, d+213);
					break;
				case 9:
					if (d > 30)
						printf("输入错误-日与月的关系非法 \n");
					else
						printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, d+244);
					break;
				case 10:
					if (d > 31)
						printf("输入错误-日与月的关系非法 \n");
					else
						printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, d+274);
					break;
				case 11:
					if (d > 30)
						printf("输入错误-日与月的关系非法 \n");
					else
						printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, d+305);
					break;
				case 12:
					if (d > 31)
						printf("输入错误-日与月的关系非法 \n");
					else
						printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, d+335);
					break;
			}
		else
			switch (m)
			{
				case 1:
					if (d > 31)
						printf("输入错误-日与月的关系非法 \n");
					else
						printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, d);
					break;
				case 2:
					if (d > 28)
						printf("输入错误-日与月的关系非法 \n");
					else
						printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, d+31);
					break;
				case 3:
					if (d > 31)
						printf("输入错误-日与月的关系非法 \n");
					else
						printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, d+59);
					break;
				case 4:
					if (d > 30)
						printf("输入错误-日与月的关系非法 \n");
					else
						printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, d+90);
					break;
				case 5:
					if (d > 31)
						printf("输入错误-日与月的关系非法 \n");
					else
						printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, d+120);
					break;
				case 6:
					if (d > 30)
						printf("输入错误-日与月的关系非法 \n");
					else
						printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, d+151);
					break;
				case 7:
					if (d > 31)
						printf("输入错误-日与月的关系非法 \n");
					else
						printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, d+181);
					break;
				case 8:
					if (d > 31)
						printf("输入错误-日与月的关系非法 \n");
					else
						printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, d+212);
					break;
				case 9:
					if (d > 30)
						printf("输入错误-日与月的关系非法 \n");
					else
						printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, d+243);
					break;
				case 10:
					if (d > 31)
						printf("输入错误-日与月的关系非法 \n");
					else
						printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, d+273);
					break;
				case 11:
					if (d > 30)
						printf("输入错误-日与月的关系非法 \n");
					else
						printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, d+304);
					break;
				case 12:
					if (d > 31)
						printf("输入错误-日与月的关系非法 \n");
					else
						printf("%d-%d-%d是%d年的第%d天\n", y, m, d, y, d+334);
					break;
			}

	return 0;
}

