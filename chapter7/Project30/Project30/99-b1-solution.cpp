#include <iostream>
using namespace std;
int conflict1(int sdkarray[][9], int tar_x, int tar_y)
{
	int n, k, t, count = 0;
	for (n = 0; n < 9; n++)
		if (sdkarray[tar_x][tar_y] == sdkarray[tar_x][n] && tar_y != n)

			count++;


	for (n = 0; n < 9; n++)
		if (sdkarray[tar_x][tar_y] == sdkarray[n][tar_y] && tar_x != n)

			count++;


	for (k = tar_x / 3 * 3; k < tar_x / 3 * 3 + 3; k++)
		for (t = tar_y / 3 * 3; t < tar_y / 3 * 3 + 3; t++)
			if (sdkarray[tar_x][tar_y] == sdkarray[k][t] && tar_x != k&&tar_y != t)

				count++;


	return count;

}
int is_succ(int sdkarray[][9])
{
	int flag = 0, i, j;
	for (i = 0; i < 9; i++)
		for (j = 0; j < 9; j++)
		{
			if (sdkarray[i][j] == 0)
				flag = 1;
		}
	return flag;
}
int solving_sudoku(int sdkarray[][9])
{
	int i, j;
	int loc = -1;
	int *p[81], *q[81];
	static int array_try[9][9];
	for (i = 0; i < 9; i++)
		for (j = 0; j < 9; j++)
		{
			if (sdkarray[i][j] == 0)
			{
				loc++;
				p[loc] = &sdkarray[i][j];
				q[loc] = &array_try[i][j];
			}
			array_try[i][j] = 1;
		}
	loc = 0;
	int row, col;
	while (1)
	{

		if (*(p[loc]) != 10)
		{
			if (is_succ(sdkarray) == 0)
				return 1;
			*(p[loc]) = *(q[loc]);
			cout << (q[loc] - &array_try[0][0]) / 9  << " " << (q[loc] - &array_try[0][0]) % 9 ;
			if (conflict1(sdkarray, (q[loc] - &array_try[0][0]) / 9 , (q[loc] - &array_try[0][0]) % 9 ) != 0)
			{

				*(q[loc])++;
				continue;
			}
			else
			{
				loc++;
				/*cout << endl;
				for (row = 0; row < 9; row++) {
					for (col = 0; col < 9; col++)
						cout << sdkarray[row][col] << ' ';
					cout << endl;}*/
					
				continue;
			}
		}
		else
		{
			if (loc == -1)
				return 0;

			else
			{
				*(q[loc]) = 1;
				*(p[loc]) = 0;
				loc--;

			}
		}
	}
}

	

