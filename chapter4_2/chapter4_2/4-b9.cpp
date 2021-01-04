/*王志业 1553449 3班*/
#include <iostream>
using namespace std;
int min2(int a, int b)
{
	if (a > b)
		return b;
	else
		return a;
}
int min(int a, int b, int c = 0, int d = 0)
{
	if (d)
	{
		if (min2(a, b) > min2(c, d))
			return min2(c, d);
		else
			return min2(a, b);
	}
	else if (c)
	{
		if (min2(a, b) > c)
			return c;
		else
			return min2(a, b);
	}
	else
		return min2(a, b);
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
					cout << "min=" << min(a, b) << endl;
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
					cout << "min=" << min(a, b, c) << endl;
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
					cout << "min=" << min(a, b, c, d) << endl;
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
