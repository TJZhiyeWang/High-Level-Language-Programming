/*王志业 1553449 3班*/
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	double a;
	int j5=0, j1=0, f5=0, f2=0, f1=0;
	int y50=0, y20=0, y10=0, y5=0, y1=0, n=0;
	cout << "请输入找零值：";
	cin >> a;
	y50 = (int)a / 50;
	if (y50 == 0)
		n += 0;
	else
	{
		n += 1;
		a -= 50;
	}

	y20 = (int)a / 20;
	if (y20 == 0)
		n += 0;
	else
	{
		n += y20;
		a = a - y20 * 20;
	}

	y10 = (int)a / 10;
	if (y10 == 0)
		n += 0;
	else
	{
		n += y10;
		a = a - y10 * 10;
	}

	y5 = (int)a / 5;
	if (y5 == 0)
		n += 0;
	else
	{
		n += y5;
		a = a - y5 * 5;
	}

	y1 = (int)a / 1;
	if (y1 == 0)
		n += 0;
	else
	{
		n += y1;
		a = a - y1;
	}

	j5 = (int)(a / 0.5);
	if (j5 == 0)
		n += 0;
	else
	{
		n += j5;
		a = a - j5 * 0.5;
	}

	j1 = (int)(a / 0.1);
	if (j5 == 0)
		n += 0;
	else
	{
		n += j1;
		a = a - j1 * 0.1;
	}

	f5 = (int)(a / 0.05);
	if (f5 == 0)
		n += 0;
	else
	{
		n += f5;
		a = a - f5 * 0.05;
	}

	f2 = (int)(a / 0.02);
	if (f2 == 0)
		n += 0;
	else
	{
		n += f2;
		a = a - f2 * 0.02;
	}

	f1 = (int)(a / 0.01);
	if (f1 == 0)
		n += 0;
	else
	{
		n += f1;
	}
	cout << "共" << n << "张找零，具体如下:"<<endl;
	if (y50 != 0)
		cout << " 50元:" << y50 << "张" << endl;
	if (y20 != 0)
		cout << " 20元:" << y20 << "张" << endl;
	if (y10 != 0)
		cout << " 10元:" << y10 << "张" << endl;
	if (y5 != 0)
		cout << " 5元:" << y5 << "张" << endl;
	if (y1 != 0)
		cout << " 1元:" << y1 << "张" << endl;
	if (j5 != 0)
		cout << " 5角:" << j5 << "张" << endl;
	if (j1 != 0)
		cout << " 1角:" << j1 << "张" << endl;
	if (f5 != 0)
		cout << " 5分:" << f5 << "张" << endl;
	if (f2 != 0)
		cout << " 2分:" << f2 << "张" << endl;
	if (y1 != 0)
		cout << " 1分:" << f1 << "张" << endl;

	return 0;
}