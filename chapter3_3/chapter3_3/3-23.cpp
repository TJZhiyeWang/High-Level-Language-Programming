/*1553449 3班 王志业*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int a;
	double x=1,xn;
	cout << "请输入a值（整数）" << endl;
	cin >> a;
	xn = 0.5*(x + a / x);
	while (abs(xn - x) >= 1e-5)
	{
		x = xn;
		xn = 0.5*(x + a / x);
	}
	cout << a << "的平方根=" << xn<<endl;
}