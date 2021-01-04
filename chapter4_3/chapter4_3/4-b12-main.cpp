/*王志业 3班 1553449*/
#include "4-b12.h"
int main()
{
	double a, b, c, delta;
	cout << "请输入一元二次方程的三个系数：" << endl;
	cin >> a >> b >> c;
	delta = b*b - 4 * a*c;
	if (a == 0)
		aequal0();
	else if (delta > 0)
		dgreater0(a, b, c);
	else if (delta == 0)
		dequal0(a, b, c);
	else
		dless0(a, b, c);
	return 0;
}
