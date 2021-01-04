/*王志业 1553449 3班*/
/*已验证 1651574 贾昊霖 1550276 马跃泷 1651025 汪涵  1653733 卢依雯 1652571 袁小丁*/ 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
int main()
{
	int length, Caps, Low, Num, Other;
	int Len = 0, C = 0, L = 0, N = 0, O = 0;
	char pass[10][17],temp;
	int i, j;
	scanf("%d%d%d%d%d\n",&length, &Caps, &Low, &Num, &Other);
	for (i = 0; i < 10; i++)
	{
		Len = 0;
		C = 0; 
		L = 0;
		N = 0;
		O = 0;
		for (j = 0; j < length; j++)
		{
			scanf("%c",&pass[i][j]) ;
			if (pass[i][j] == '\0')
			{
				printf("错误\n");
				return 0;
			}
			else if (pass[i][j] >= 65 && pass[i][j] <= 90)
				C++;
			else if (pass[i][j] >= 97 && pass[i][j] <= 122)
				L++;
			else if (pass[i][j] >= 48 && pass[i][j] <= 57)
				N++;
			else
				O++;
		}
		scanf("%c",&temp);
		if(C<Caps||L<Low||N<Num||O<Other)
		{
			printf("错误\n");
			return 0;
		}
	}
	
		printf("正确\n");
		return 0;
	


}
