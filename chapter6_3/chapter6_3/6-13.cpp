/*王志业 1553449 3班*/
#include <iostream>
#include <cmath>
using namespace std;
double mysin(double x,double d)
{
	return sin(x+d)*d;
}
double mycos(double x, double d)
{
	return cos(x + d)*d;
}
double myexp(double x, double d)
{
	return exp(x + d)*d;
}
double definite_integration(double(*p)(double,double), double low, double high,int n)
{
	double x = low;
	double value = 0;
	double d = (high - low) / n;
	while (fabs(high-x)>=1e-5)
	{
		value += p(x,d);
			x += d;
	}
	if (high > low)
		return value;
	else
		return -value;
}
int main()
{
	int n;
	double low, high, value;
	while (1)
	{
		cout << "请输入sinxdx的上下限及区间划分数量" << endl;
		cin >> low >> high>>n; 
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else
			break;
	}
	value = definite_integration(mysin, low, high,n);
	cout << "sinxdx[" << low << '~' << high << "/n="<<n<<"] : "<<value << endl;
	while (1)
	{
		cout << "请输入cosxdx的上下限及区间划分数量" << endl;
		cin >> low >> high>>n; 
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else
			break;
	}
	value = definite_integration(mycos, low, high,n);
	cout << "cosxdx[" << low << '~' << high << "/n=" << n << "] : " << value << endl;
	while (1)
	{
		cout << "请输入e^xdx的上下限及区间划分数量" << endl;
		cin >> low >> high>>n; //输入上下限
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else
			break;
	}
	value = definite_integration(myexp, low, high,n);
	cout << "e^xdx[" << low << '~' << high << "/n=" << n << "] : " << value << endl;
	return 0;
}