/*1553449 王志业 3班*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int x, i=1,n=1,m;
	double sum = 1;
	cout << "请输入x的值（整数）" << endl;
	cin >> x;
	m = n;
	while (pow(x, n) / m>=10e-6)
	{
		sum += pow(x, n) / (double)m;
		n++;
		m = 1;
		for (i=1; i <= n; i++)
			m *= i;
	}
	cout << "e^" << x << "=" << sum;
	return 0;
}