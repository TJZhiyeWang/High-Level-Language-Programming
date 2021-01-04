/*1553449 王志业 3班*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int a, n, i, j,s=0,b;
	cout << "请输入a和n的值：" << endl;
	cin >> a >> n;
	for (i = 0; i < n; i++)
	{
		b = 0;
		for (j = 0; j <= i; j++)
			b += a * pow(10, j);
		s += b;
	}
	cout << "S=" << s;
	return 0;
}