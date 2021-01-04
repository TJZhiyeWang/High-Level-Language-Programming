/*王志业 3班 1553449*/
#include <iostream>
#include <cmath>
using namespace std;
void dless0(double a, double b, double c)
{
	double delta;
	delta = b*b - 4 * a*c;
	cout << "有两个虚根：" << endl;
	if ((-b) / (2 * a) == 0)
	{
		if (sqrt(abs(-delta)) / abs(2 * a) == 1)
		{
			cout << "x1=" << "i" << endl;
			cout << "x2=" << "-" << "i" << endl;
		}
		else
		{
			cout << "x1=" << sqrt(abs(-delta)) / abs(2 * a) << "i" << endl;
			cout << "x2=" << "-" << sqrt(abs(-delta)) / abs(2 * a) << "i" << endl;
		}
	}
	else
	{
		if (sqrt(abs(-delta)) / abs(2 * a) == 1)
		{
			cout << "x1=" << "i" << endl;
			cout << "x2=" << "-" << "i" << endl;
		}
		else
		{
			cout << "x1=" << (-b) / (2 * a) << "+" << "i" << endl;
			cout << "x2=" << (-b) / (2 * a) << "-" << "i" << endl;
		}
	}
}

