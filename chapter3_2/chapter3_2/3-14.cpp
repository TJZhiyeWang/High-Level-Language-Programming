/*王志业 3班 1553449*/
#include <iostream>
using namespace std;
int main()
{
	int a, b, c, d,temp;
	cout << "请输入四个整数" << endl;
	cin >> a >> b >> c >> d;
	cout << "输出" << endl;
	if (b < a)
	{
		temp = b;
		b = a;
		a = temp;
	}
	if (c < a)
	{
		temp = c;
		c = a;
		a = temp;
	}
	if (d < a)
	{
		temp = d;
		d = a;
		a = temp;
	}
	if (c < b)
	{
		temp = c;
		c = b;
		b = temp;
	}
	if (d < b)
	{
		temp = d;
		d = b;
		b = temp;
	}
	if (d < c)
	{
		temp = d;
		d = c;
		c = temp;
	}
	cout << a << " " << b << " " << c << " " << d;
	return 0;
}