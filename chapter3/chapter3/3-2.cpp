/*1553449 王志业 3班*/
#include <iostream>
#include <iomanip>
using namespace std;
#define pi 3.14
int main()
{
	double r = 1.5, h = 3, c, sc, sb, vb, vc;
	c = 2 * pi*r;
	sc = pi*r*r;
	sb = 4 * pi*r*r;
	vb = 4.0 / 3 * pi*r*r*r;
	vc = sc*h;
	cout << "圆的周长为" << setiosflags(ios::fixed) << setprecision(2) << c << "面积为" << sc << "球体表面积为" << sb << "球体体积为" << vb << "圆柱体体积为" << vc;
	return 0;
}