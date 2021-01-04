/*王志业 1553449 3班*/
#include <iostream>
using namespace std;
int is_leap_year(int year)
{
	int leap;
	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	//leap为0代表不是闰年，为1代表是闰年
	return leap;
}

int date(int year, int mon, int day, int a[])
{
	int k = 0;      //这是第几天
	for (int i = 1; i < mon; i++)
	{
		k += a[i];
	}
	k += day;
	return k;
}
int main()
{
	int year, mon, day;
	int month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	while (1)
	{
		month[2] = 28;
		cout << "请输入年,月,日：" << endl;
		cin >> year >> mon >> day;
		if (!cin.good())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			cout << "输入格式错误" << endl;
		}
		else if (year < 2000 || year>2030)
			cout << "输入错误-年份不正确" << endl;
		else if (mon > 12 || mon < 1 || day < 1)
		{
			cout << "输入错误-月份不正确" << endl;
		}
		else
		{
			month[2] = month[2] + is_leap_year(year);
			if (day > 0 && day <= month[mon])
				break;
			else
				cout << "输入错误-日与月关系非法" << endl;
		}
	}
	cout << year << "-" << mon << "-" << day << "是" << year << "年的第" << date(year, mon, day, month) << "天" << endl;

	return 0;
}

