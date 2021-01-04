/*王志业 1553449 3班*/
#include <iostream>
using namespace std;
double legendre(double x, unsigned int n)
{
	if (n == 0)
		return 1;
	if (n == 1)
		return x;
	return ((2 * n - 1)*x*legendre(x, n - 1) - (n - 1)*legendre(x, n - 2)) / n;
}
int main()
{
	double x;
	unsigned int n;
	while (1)
	{
		cout << "计算legendre，请输入x和n的值" << endl;
		cin >> x>>n;
		if (!cin)
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		} 
		if (n < 0)
			continue;
		break;
	}
	cout << "legendre[" << n << "]<" << x << ">=" << legendre(x, n) << endl;
	return 0;
}
