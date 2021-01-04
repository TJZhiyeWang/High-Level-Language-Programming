/*1553449 Õı÷æ“µ 3∞‡*/
#include <iostream>
#include <cmath>
#define N 1000
using namespace std;
class integral
{
public:
	virtual double value() = 0;
};
class integral_sin :public integral
{
protected:
	double x;
	double y;
public:
	virtual double value()
	{
		double s = 0, p = (x - y) / N;
		for (int i = 0; i < N; i++)
			s += p*sin(x + i*p);
		return s;
	}
	friend istream& operator >>(istream& in, integral_sin&);
};
istream& operator >>(istream& in, integral_sin& t)
{
	in >> t.y >> t.x;
	return in;
}
class integral_cos :public integral
{
protected:
	double x;
	double y;
public:
	virtual double value()
	{
		double s = 0, p = (x - y) / N;
		for (int i = 0; i < N; i++)
			s += p*cos(x + i*p);
		return s;
	}
	friend istream& operator >>(istream& in, integral_cos&);
};
istream& operator >>(istream& in, integral_cos& t)
{
	in >> t.y >> t.x;
	return in;
}
class integral_exp :public integral
{
protected:
	double x;
	double y;
public:
	virtual double value()
	{
		double s = 0, p = (x - y) / N;
		for (int i = 0; i < N; i++)
			s += p*exp(y + i*p);
		return s;
	}
	friend istream& operator >>(istream& in, integral_exp&);
};
istream& operator >>(istream& in, integral_exp& t)
{
	in >> t.y >> t.x;
	return in;
}
int main()
{
	integral_sin s1;
	integral_cos s2;
	integral_exp s3;
	integral *p;
	cin >> s1;
	p = &s1;
	cout << p->value() << endl;

	cin >> s2;
	p = &s2;
	cout << p->value() << endl;

	cin >> s3;
	p = &s3;
	cout << p->value() << endl;

	return 0;
}