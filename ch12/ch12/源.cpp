#include <iostream>
using namespace std;
class A
{
public:
	virtual void f1()
	{
		cout << "af1" << endl;
	}
	virtual void f2()
	{
		cout << "af2" << endl;
	}
	virtual void f3()
	{
		cout << "af3" << endl;
	}
	virtual void f4()
	{
		cout << "af4" << endl;
	}
	void f5()
	{
		cout << "af5" << endl;
	}

};
class B :public A {
public:
	void f1() { cout << "bf1" << endl; }
	void f3(float f) { cout << "bf3" << endl; }
	//int f4() { cout << "bf4" << endl; }
	void f5(float f) { cout << "bf5" << endl; }

};
int main()
{
	B b;
	A *pa = &b;
	pa->f1();
	pa->f2();
	pa->f3();
	//pa->f3(10);
	pa->f4();
	pa->f5();
	//pa->f5(10);
	b.f1();
	b.f2();
	b.A::f3();
	b.f3(10);
	b.f4();
	b.A:: f5();
	b.f5(10);
	return 0;
}