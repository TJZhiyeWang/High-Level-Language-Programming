/*王志业 1553449 3班*/
#include <iostream>
using namespace std;
int main()
{
	int a, b,c;
	int add(int x, int y);
	cin >> a >> b;
	c = add(a, b);
	cout << "a+b=" << c << endl;
	return 0;
}
int add(int x, int y)
{
	int z;
	z = x + y;
	return z;
}
/*a,b未赋初值，c、z没有定义；函数没有提前声明；第九行句末少分号；*/