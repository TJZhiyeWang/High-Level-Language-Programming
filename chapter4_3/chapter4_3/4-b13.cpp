/*王志业 3班 1553449*/
#include <iostream>
#include <cmath>
using namespace std;
double a, b, c;
void aequal0()
{
	cout << "不是一元二次方程";
}
void dgreater0()
{
	double delta;
	delta = b*b - 4 * a*c;
	cout << "有两个不等实根：" << endl;
	cout << "x1=" << (-b + sqrt(delta)) / (2 * a) << endl;
	cout << "x2=" << (-b - sqrt(delta)) / (2 * a) << endl;
}
void dequal0()
{
	cout << "有两个相等实根：" << endl;
	cout << "x1=x2=" << (-b) / (2 * a) << endl;
}
void dless0()
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
int main()
{
	double delta;
	cout << "请输入一元二次方程的三个系数：" << endl;
	cin >> a >> b >> c;
	delta = b*b - 4 * a*c;
	if (a == 0)
		aequal0();
	else if (delta > 0)
		dgreater0();
	else if (delta == 0)
		dequal0();
	else
		dless0();
	return 0;
}
