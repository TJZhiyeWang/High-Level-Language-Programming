/*ÍõÖ¾Òµ 1553449 3°à*/
#include <iostream>
#include <cmath>
using namespace std;
double rootsol(double a, double b, double c, double d)
{
	double x = 1, x0, f, f1;
	x0 = x;
	f = ((a*x0 + b)*x0 + c)*x0 + d;
	f1 = (3 * a*x0 + 2 * b)*x0 + c;
	x = x0 - f / f1;
	while (fabs(x - x0) >= 1e-3)
	{
		x0 = x;
		f = ((a*x0 + b)*x0 + c)*x0 + d;
		f1 = (3 * a*x0 + 2 * b)*x0 + c;
		x = x0 - f / f1;
	}
	return x;
}
int main()
{
	double a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << "x=" << rootsol(a, b, c, d);
	return 0;
}