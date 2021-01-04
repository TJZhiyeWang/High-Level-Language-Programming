/*1553449 王志业 3班*/
#include <iostream>
using namespace std;
int main()
{
	int m, n,a,b,temp;
	cout << "请输入两个正整数："<<endl;
	cin >> m >> n;
	a = m;
	b = n;
	temp = a%b;
	while (temp != 0)
	{
		a = b;
		b = temp;
		temp = a%b;
	}
	cout << "最大公约数：" << b << endl;
	cout << "最小公倍数:" << m*n / b;
	return 0;
}