/*1553449 3班 王志业*/
#include <iostream>
using namespace std;
int s=5;
void merge(int *a, int *b, int *c)
{
	
	int i = 0, j = 0, temp = 0;
	while (*(c + temp) != -1)
	{
		while (*(a + i) != -1 && *(b + j) != -1)
		{
			if (*(a + i) <= *(b + j))
			{
				*(c + temp) = *(a + i);
				temp++;
				i++;
			}
			else
			{
				*(c + temp) = *(b + j);
				temp++;
				j++;
			}
		}
		while (*(a + i) != -1 && *(b + j) == -1)
		{
			*(c + temp) = *(a + i);
			temp++;
			i++;
		}
		while (*(a + i) == -1 && *(b + j) != -1)
		{
			*(c + temp) = *(b + j);
			temp++;
			j++;
		}
		if (*(a + i) == -1 && *(b + j) == -1)
			*(c + temp) = -1;
	}
}
void test();
void test1(int &p)
{
	return;
}
int main()
{
	void merge(int *la, int *lb, int *lc);
	int a[2] = { 1,-1 };
	int b[21] = { 3,-1 };
	int c[41];
	int d = 1;
	int e[5][5] = { 0 };
	char *str = "china";
	int *p = a;
	int **s;
	s = &p;
	int i = 0;
	int &j = i;
	test1(d);
	cout << "第一个数组的内容为：" << endl;
	while (*(a + i) != -1)
	{
		cout << *(a + i) << " ";
		i++;
	}
	i = 0;
	cout << endl << "第二个数组的内容为：" << endl;
	while (*(b + i) != -1)
	{
		cout << *(b + i) << " ";
		i++;
	}

	merge(a,b, c);
	i = 0;
	cout << endl << "合并后的数组：" << endl;
	while (*(c + i) != -1)
	{
		cout << *(c + i) << " ";
		i++;
	}
	cout << endl;
	return 0;
}
