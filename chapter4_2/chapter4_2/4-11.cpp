/*1553449 王志业 3班*/
#include <iostream>
using namespace std;
int f(int num)
{
	if (num == 1)
		return 1;
	return num*num + f(num - 1);
}

int main()
{
	int num;
	while (1)
	{
		cout << "求1^2+...+n^2，请输入n值" << endl;
		cin >> num;
		if (!cin)
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (num <= 0)
			continue;
		break;
	}
	cout << "1^2+...+" << num << "^2=" << f(num) << endl;
	return 0;
}
