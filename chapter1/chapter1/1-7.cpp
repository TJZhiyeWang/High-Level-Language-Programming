/*王志业 1553449 3班*/
#include <iostream>
using namespace std;
int main()
{
	int a, b, c;
	int f(int x, int y, int z);
	cin >> a >> b >> c;
	c = f(a, b, c);
	cout << c << endl;
	return 0;
}
int f(int x, int y, int z)
{
	int m;
	if (x < y)
		m = x;
	else
		m = y;
	if (z < m)
		m = z;
	return m;
}
/*功能：输入三个数，选择最小的一个数输出*/