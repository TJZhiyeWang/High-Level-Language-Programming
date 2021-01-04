/*1553449 王志业 3班*/
#include <iostream>
using namespace std;
void input_int(int *num, int low, int high)
{
	while (1)
	{
		cin >> *num;
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else if (*num >= low && *num <= high)
			break;
	}
}
void input_int(int *num, int low)
{
	while (1)
	{
		cin >> *num;
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else if (*num >= low)
			break;
	}
}
void move(int *pa, int n, int m)
{
	int temp[20], k;
	for (k = 0; k < n; k++)
	{
		*(temp + k) = *(pa + k);
	}
	for (k = 0; k < n; k++)
	{
		*(pa+(m+k)%n)= *(temp+k);
	}
}
int main()
{
	int n, m, i;
	int array[20];
	cout << "请输入整数的数量n《10-20》：";
	input_int(&n, 10, 20);
	cout << "请输入" << n << "个整数：" << endl;
	for (i = 0; i < n; i++)
	{
		while (1)
		{
			cin >> *(array + i);
			if (!cin.good())
			{
				cin.clear();
				cin.ignore(1024, '\n');
			}
			else if (*(array + i) > 0)
				break;
		}
	}
	cout << "输入的整数序列为：" << endl;
	for (i = 0; i < n; i++)
	{
		cout << *(array + i) << " ";
	}
	cout << endl;
	cout << "请输入位移m：";
	input_int(&m, 1);

	move(array, n, m);
	cout << "移动后的整数序列为：" << endl;
	for (i = 0; i < n; i++)
	{
		cout << *(array + i) << " ";
	}
	cout << endl;
	return 0;
}
