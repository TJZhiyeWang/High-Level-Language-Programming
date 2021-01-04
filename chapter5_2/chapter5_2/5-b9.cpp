/*王志业 1553449 3班*/
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	int matrix[9][9];
	bool flag = true;   
	cout << "请输入9*9的矩阵，值为1-9之间" << endl;
	int i, j,x,y,kl,kh;
	for (i = 0; i < 9; i++)
		for (j = 0; j < 9; j++)
			cin >> matrix[i][j];



	for (int i = 0; i < 9; i++)      //第i行
		for (int j = 0; j < 8; j++)       //第j个数与后面的比较
			for (int k = j + 1; k < 9; k++)
				if (matrix[i][j] == matrix[i][k])
				{
					flag = false;
					j = 8;
					i = 9;
					break;
				}
	if (flag)
	{
		for (int i = 0; i < 9; i++)      //第i列
			for (int j = 0; j < 8; j++)       //第j个数与后面的比较
				for (int k = j + 1; k < 9; k++)
					if (matrix[j][i] == matrix[k][i])
					{
						flag = false;
						j = 8;
						i = 9;
						break;
					}
	}
	if (flag)
	{
		for (x = 0; x <= 2; x++)
			for ( y = 0; y <= 2; y++)
			{
				for (i = 0; i < 2; i++)      //大格中的第i行
					for (j = 0; j < 2; j++)       //大格中的第j列
						for ( kl = j + 1; kl <= 2; kl++)
							for (kh = 0; kh <= 2 - i; kh++)
								if (matrix[i + x * 3][j + y * 3] == matrix[i + kh + x * 3][kl + y * 3])
								{
									flag = false;
									kl = 3;
									j = 2;
									i = 2;
									y = 3;
									x = 3;
									break;
								}
			}

	}
	if (!flag)
		cout << "不";
	cout << "是数独的解" << endl;
	return 0;
}