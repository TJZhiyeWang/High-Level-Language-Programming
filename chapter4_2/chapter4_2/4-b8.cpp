/*王志业 1553449 3班*/
#include <iostream>
using namespace std;
int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}
int max(int a, int b, int c)
{
	if (max(a, b) > c)
		return max(a, b);
	else
		return c;
}
int max(int a, int b, int c, int d)
{
	if (max(a, b, c) > d)
		return max(a, b, c);
	else
		return d;
}


int main()
{
	int num, a, b, c, d, flag = 0;

	while (1)
	{
		cout << "请输入个数num及num个整数：" << endl;
		cin >> num;
		switch (num)
		{
			case 2:
			{
				cin >> a >> b;
				if (!cin)
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}
				else
				{
					cout << "max=" << max(a, b) << endl;
					flag = 1;
					break;
				}
			}
			case 3:
			{
				cin >> a >> b >> c;
				if (!cin)
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}
				else
				{
					cout << "max=" << max(a, b, c) << endl;
					flag = 1;
					break;
				}
			}
			case 4:
			{
				cin >> a >> b >> c >> d;
				if (!cin)
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}
				else
				{
					cout << "max=" << max(a, b, c, d) << endl;
					flag = 1;
					break;
				}
			}
			default:
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
	}
	return 0;
}
