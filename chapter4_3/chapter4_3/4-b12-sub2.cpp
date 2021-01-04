/*王志业 3班 1553449*/
#include <iostream>
#include <cmath>
using namespace std;
void dgreater0(double a, double b, double c)
{
	double delta;
	delta = b*b - 4 * a*c;
	cout << "有两个不等实根：" << endl;
	cout << "x1=" << (-b + sqrt(delta)) / (2 * a) << endl;
	cout << "x2=" << (-b - sqrt(delta)) / (2 * a) << endl;
}

