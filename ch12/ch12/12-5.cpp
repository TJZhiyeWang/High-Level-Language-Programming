/*Õı÷æ“µ 3∞‡ 1553449*/
#include <iostream>
#define pi 3.14
using namespace std;
class Shape
{
public:
	virtual double area() = 0;
};
class Square :public Shape
{
protected:
	double l;
public:
	Square(double t)
	{
		l = t;
	}
	virtual double area()
	{
		return l*l;
	}
};
class Circle : public Shape
{
protected:
	double r;
public:
	Circle(double t)
	{
		r = t;
	}
	virtual double area()
	{
		return pi*r*r;
	}
};
class Triangle : public Shape
{
protected:
	double a;
	double b;
	double c;
public:
	Triangle(double t1, double t2, double t3)
	{
		a = t1;
		b = t2;
		c = t3;
	}
	virtual double area()
	{
		double p = (a + b + c) / 2;
		return sqrt(p*(p - a)*(p - b)*(p - c));
	}
};
class Trapezoid :public Shape
{
protected:
	double a;
	double b;
	double h;
public:
	Trapezoid(double t1, double t2, double t3)
	{
		a = t1;
		b = t2;
		h = t3;
	}
	virtual double area()
	{
		return (a + b)*h / 2;
	}
};
class Rectangle :public Shape
{
protected:
	double a;
	double b;
public:
	Rectangle(double t1, double t2)
	{
		a = t1;
		b = t2;
	}
	virtual double area()
	{
		return a*b;
	}
};
int main()
{
	Circle c1(10);
	Square s1(10);
	Rectangle r1(4, 6);
	Trapezoid t1(4, 6, 8);
	Triangle t2(3, 4, 5);
	Shape *s[5] = { &c1,&s1,&r1,&t1,&t2 };
	int i;
	for (i = 0; i < 5; i++)
		cout << s[i]->area() << endl;
	return 0;
}