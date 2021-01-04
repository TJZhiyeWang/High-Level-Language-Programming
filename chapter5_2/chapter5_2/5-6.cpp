/*1553449 Õı÷æ“µ 3∞‡*/
#include <iostream>
#include <iomanip>
#define size 10
using namespace std;
int main()
{
	int row, i;
	int a[size][size];
	a[0][0] = a[1][0] = a[1][1] = 1;
	for (row = 2; row < size; row++)
		for (i = 0; i <= row; i++)
		{
			if (i == 0 || i == row)
				a[row][i] = 1;
			else
				a[row][i] = a[row - 1][i] + a[row - 1][i - 1];
		}
	for (row = 0; row < size; row++)
		for (i = 0; i <= row; i++)
		{
			cout << setw(6) << a[row][i];

			if (i == row)
				cout << endl;
		}
	return 0;
}