/*1553449 Õı÷æ“µ 3∞‡*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double a = 0, b = 1;
	while (abs(2 * pow((a + b) / 2, 3) - 9 * pow((a + b) / 2, 2) + 6 * (a + b) - 3) >= 10e-6)
	{
		if ((2 * pow((a + b) / 2, 3) - 9 * pow((a + b) / 2, 2) + 6 * (a + b) - 3)*(2 * pow(a, 3) - 9 * pow(a, 2) + 12 * a - 3) < 0)
			b = (a + b) / 2;
		else if ((2 * pow((a + b) / 2, 3) - 9 * pow((a + b) / 2, 2) + 6 * (a + b) - 3)*(2 * pow(b, 3) - 9 * pow(b, 2) + 12 * b - 3) < 0)
			a = (a + b) / 2;
	}
	cout << "x=" << (a + b)/2;
	return 0;
}