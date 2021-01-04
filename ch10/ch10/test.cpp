#include <iostream>
using namespace std;
class Complex
{
public:
	double imag;
	double real;

	Complex(double x=0, double y=0)
	{
		real = x;
		imag = y;
	}
	friend Complex operator+(Complex &a, double &b);
	friend Complex operator+(double &a, Complex &b);
	void display()
	{
		cout << real << "+" << imag << "i"<<endl;
	}
};
Complex operator+(Complex &a, const double &b)
{
	Complex c;
	c.real = a.real + b;
	c.imag = a.imag;
	return c;
}
Complex operator+(const double &a, Complex &b)
{
	Complex c;
	c.real = a + b.real;
	c.imag = b.imag;
	return c;
}
int main()
{
	Complex c1(3,4);
	Complex c2, c3;
	c2 = c1 + 4;
	c2.display();
	c3 = 5 + c1;
	c3.display();
	return 0;
}