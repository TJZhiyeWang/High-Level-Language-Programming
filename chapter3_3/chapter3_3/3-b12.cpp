/*1553449 王志业 3班*/
#include <iostream>
using namespace std;
int main()
{
	int x;
	while (1)
	{
		cout << "请输入x的值（0-100）：" << endl;
		cin >> x;
		if (x >= 0 && x <= 100)
			break;
		else 
		{
			cin.clear();
			cin.ignore();
		}
	}
	cout << "x=" << x << endl;
	return 0;
}