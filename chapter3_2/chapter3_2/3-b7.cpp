/*1553449 王志业 3班*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double x1, x2, x3, y1, y2, y3, a,b,c,p;
	cout << "请输入三点坐标:" << endl;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	a = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
	b = sqrt((x1 - x3)*(x1 - x3) + (y1 - y3)*(y1 - y3));
	c = sqrt((x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2));
	if (a + b > c)
		if (a + c > b)
			if (b + c > a)
			{
				p = (a + b + c) / 2;
				cout << "三角形面积：" << sqrt(p*(p - a)*(p - b)*(p - c));
			}
			else
				cout << "不构成三角形";
		else
			cout << "不构成三角形";
	else
		cout << "不构成三角形";
	return 0;
}