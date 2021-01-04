/*1553449 3班 王志业*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int year, month, week, mday, i, j;
	cout << "请输入年份(2000-2030)和月份(1-12) ：";
	cin >> year >> month;
	cout << "请输入" << year << "年" << month << "月1日的星期(0-6表示星期日-星期六) ：";
	cin >> week;
	cout << endl;
	cout << year << "年" << month << "月的月历为：" << endl;
	cout << setw(8) << setiosflags(ios::left) << "星期日" << setw(8) << "星期一" << setw(8) << "星期二" << setw(8) << "星期三" << setw(8) << "星期四" << setw(8) << "星期五" << setw(8) << "星期六" << endl;
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		mday = 31;
	else if (month == 4 || month == 6 || month == 9 || month == 11)
		mday = 30;
	else if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		mday = 29;
	else
		mday = 28;
	i = 1;
	cout << setw(3) << " ";
	if (week == 0)
		cout << i;
	else
		cout << " ";
	for (j = 1; j <= week; j++)
	{
		if (j == week)
			cout << setiosflags(ios::right) << setw(8) << i;
		else
			cout << setiosflags(ios::right) << setw(8) << " ";
	}
	for (i = 2; i <= mday; i++)
	{
		if ((i + week) % 7 != 1)
		{
			cout << setiosflags(ios::right) << setw(8) << i;
			continue;
		}
		cout << endl;
		cout << setiosflags(ios::right) << setw(4) << i;
	}
	cout << endl;
	return 0;


}