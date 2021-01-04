/*1553449 王志业 3班*/
#include <iostream>
using namespace std;
int main()
{
	double x;
	cout << "请输入x的值" << endl;
	cin >> x;
	cout << "y=";
	if (x < 1)
		cout << x;
	else if (x >= 1 && x < 10)
		cout << 2 * x - 1;
	else
		cout << 3 * x - 11;
	return 0;
}