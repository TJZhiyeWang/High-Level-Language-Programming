/*Õı÷æ“µ 1553449 3∞‡*/
#include <iostream>
#include <cmath>
#include <iomanip>
#define pi 3.1415926
using namespace std;
int main()
{
	int a, b, t;
	double s;
	cin >> a >> b >> t;
	s = 0.5*a*b*sin(t/180.0*pi);
	cout << setiosflags(ios::fixed) << setprecision(3) << s;
	return 0;
}