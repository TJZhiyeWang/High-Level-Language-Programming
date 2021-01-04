/*王志业 1553449 3班*/
#include <iostream>
using namespace std;
int zeller(int year, int month, int day)
{
	int w, c, y, m, d;
	if (month < 3)
	{
		year--;
		m = month + 12;
	}
	else
		m = month;
	d = day;
	c = year / 100;
	y = year - 100 * c;
	w = (y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1);
	while (w < 0)
		w += 7;
	w %= 7;
	return w;
}

int main()
{
	int y, m, d;
	while (1)
	{
		cout << "请输入年(1900-2100)、月、日: " << endl;
		cin >> y >> m >> d;
		if (y < 1900 || y>2100)
		{
			cout << "年份超出范围" << endl;
			continue;
		}
		if (m > 12 || m < 1 || d < 1)
		{
			cout << "输入错误-月份不正确" << endl;
			continue;
		}
		if (m != 2)
		{
			switch (m)
			{
				case 1:
					if (d > 31)
					{
						cout << "输入错误-日与月的关系非法" << '\n';
						continue;
					}
					break;
				case 3:
					if (d > 31)
					{
						cout << "输入错误-日与月的关系非法" << '\n';
						continue;
					}
					break;
				case 4:
					if (d > 30)
					{
						cout << "输入错误-日与月的关系非法" << '\n';
						continue;
					}
					break;
				case 5:
					if (d > 31)
					{
						cout << "输入错误-日与月的关系非法" << '\n';
						continue;
					}
					break;
				case 6:
					if (d > 30)
					{
						cout << "输入错误-日与月的关系非法" << '\n';
						continue;
					}
					break;
				case 7:
					if (d > 31)
					{
						cout << "输入错误-日与月的关系非法" << '\n';
						continue;
					}
					break;
				case 8:
					if (d > 31)
					{
						cout << "输入错误-日与月的关系非法" << '\n';
						continue;
					}
					break;
				case 9:
					if (d > 30)
					{
						cout << "输入错误-日与月的关系非法" << '\n';
						continue;
					}
					break;
				case 10:
					if (d > 31)
					{
						cout << "输入错误-日与月的关系非法" << '\n';
						continue;
					}
					break;
				case 11:
					if (d > 30)
					{
						cout << "输入错误-日与月的关系非法" << '\n';
						continue;
					}
					break;
				case 12:
					if (d > 31)
					{
						cout << "输入错误-日与月的关系非法" << '\n';
						continue;
					}
					break;
			}
		}
		else
		{
			if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
			{
				if (d > 29)
				{
					cout << "输入错误-日与月的关系非法" << '\n';
					continue;
				}
			}
			else
			{
				if (d > 28)
				{
					cout << "输入错误-日与月的关系非法" << '\n';
					continue;
				}
			}
		}
		switch (zeller(y, m, d))
		{
			case 0: cout << "星期日" << endl; break;
			case 1: cout << "星期一" << endl; break;
			case 2: cout << "星期二" << endl; break;
			case 3: cout << "星期三" << endl; break;
			case 4: cout << "星期四" << endl; break;
			case 5: cout << "星期五" << endl; break;
			case 6: cout << "星期六" << endl; break;
		}
		break;
	}
	return 0;
}
