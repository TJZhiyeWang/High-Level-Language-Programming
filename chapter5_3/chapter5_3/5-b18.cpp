/*Õı÷æ“µ 1553449 3∞‡*/
#include <iostream>
#include <iomanip>
#include <time.h>
#include <stdlib.h> 
#define line 26
#define col 10
#define mine 50
using namespace std;
int main()
{
	char matrix[col][line];
	srand((unsigned)time(0));
	int i, j,k;
	for (i = 0; i < col; i++)
		for (j = 0; j < line; j++)
			matrix[i][j] = '0';
	for (k = 0; k < mine; k++)
	{
		i = rand() % col;
		j = rand() % line;
		if (matrix[i][j] != '*')
			matrix[i][j] = '*';
		else
			k--;
	}
	for (i = 0; i < col; i++)
	{
		for (j = 0; j < line; j++)
		{
			if (matrix[i][j] != '*')
			{
				if (i > 0)
				{
					if (matrix[i - 1][j] == '*')
						matrix[i][j]++;
					if (j > 0)
						if (matrix[i-1][j - 1] == '*')
							matrix[i][j]++;
					if (j < line - 1)
						if (matrix[i-1][j + 1] == '*')
							matrix[i][j]++;
				}

				if (i < col - 1)
				{
					if (matrix[i + 1][j] == '*')
						matrix[i][j]++;
					if (j > 0)
						if (matrix[i + 1][j - 1] == '*')
							matrix[i][j]++;
					if (j < line - 1)
						if (matrix[i + 1][j + 1] == '*')
							matrix[i][j]++;
				}
				if (j > 0)
				{
					if (matrix[i][j - 1] == '*')
						matrix[i][j]++;

				}
				if (j < line - 1)
					if (matrix[i][j+1] == '*')
						matrix[i][j]++;

			}
		}
	}
	
	for (i = 0; i < col; i++)
	{
		for (j = 0; j < line; j++)
			cout<<matrix[i][j]<<" ";
		cout << endl;
	}

	return 0;
}
