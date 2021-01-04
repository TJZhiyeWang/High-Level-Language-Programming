/*王志业 3班 1553449*/
/*已验证 1651574 贾昊霖 1550276 马跃泷 1651025 汪涵  1653733 卢依雯 1652571 袁小丁*/ 
#define _CRT_SECURE_NO_WARNINGS
#include <time.h>
#include <stdio.h> 
#define line 26
#define col 10
#define mine 50
int main()
{
	char matrix[col][line];
	int i, k = 0, j;
	char num = '0';
	for (i = 0; i < col; i++)
		for (j = 0; j < line; j++)
		    scanf("%c ",&matrix[i][j]);
	for (i = 0; i < col; i++)
	{
		for (j = 0; j < line; j++)
		{
			if (matrix[i][j] == '*')
				k++;
		}
	}
	if (k != 50)
	{
		printf("错误\n");
		return 0;
	}


	for (i = 0; i < col; i++)
	{
		for (j = 0; j < line; j++)
		{
			num = '0';
			if (matrix[i][j] != '*')
			{
				if (i > 0)
				{
					if (matrix[i - 1][j] == '*')
						num++;
					if (j > 0)
						if (matrix[i - 1][j - 1] == '*')
							num++;
					if (j < line - 1)
						if (matrix[i - 1][j + 1] == '*')
							num++;
				}

				if (i < col - 1)
				{
					if (matrix[i + 1][j] == '*')
						num++;
					if (j > 0)
						if (matrix[i + 1][j - 1] == '*')
							num++;
					if (j < line - 1)
						if (matrix[i + 1][j + 1] == '*')
							num++;
				}
				if (j > 0)
				{
					if (matrix[i][j - 1] == '*')
						num++;

				}
				if (j < line - 1)
					if (matrix[i][j + 1] == '*')
						num++;
				if (num != matrix[i][j])
				{
					printf("错误\n");
					return 0;
				}

			}

		}
	}
	printf("正确\n");
	return 0;
}
