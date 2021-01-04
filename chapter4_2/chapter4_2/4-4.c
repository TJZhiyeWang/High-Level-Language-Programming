/*王志业 1553449 3班 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int fac(int n)
{
	if (n == 1)
		return 1;
	return n*fac(n - 1);
}
int main()
{
	int a, b, c;
	char temp;
	while (1)
	{
		printf("计算a!+b!+c!，请输入a,b,c的值\n");
		if (!scanf("%d", &a))
		{
			setbuf(stdin, NULL);
			continue;
		}
		while ((temp = getchar()) != EOF&&temp != ' ');
		if (!scanf("%d", &b))
		{
			setbuf(stdin, NULL);
			continue;
		}
		while ((temp = getchar()) != EOF&&temp != ' ');
		if (!scanf("%d", &c))
		{
			setbuf(stdin, NULL);
			continue;
		}
		setbuf(stdin, NULL);
		break;
	}
	printf("%d!+%d!+%d!=%d\n", a, b, c, fac(a) + fac(b) + fac(c));
	return 0;
}