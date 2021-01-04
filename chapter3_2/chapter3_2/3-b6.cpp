/*王志业 3班 1553449*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double a, b, c,p;
	cout << "请输入三边的长度" << endl;
	cin >> a >> b >> c;
	if (a + b > c)
		if (a + c > b)
			if (b + c > a)
			{
				p = (a + b + c) / 2;
				cout <<"三角形面积："<< sqrt(p*(p - a)*(p - b)*(p - c));
			}
			else
				cout << "不构成三角形";
		else
			cout << "不构成三角形";
	else
		cout << "不构成三角形";
	return 0;
}