/*1553449 3班 王志业*/
#include <iostream>
#include <iomanip>
using namespace std;
int zeller(int year, int month)
{
	int w, c, y, m, d,day=1;
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
void calender(int year, int month,int week)
{
	int mday,i,j;
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
}
int main()
{
	int y,m;
	while (1)
	{
		cout << "请输入年(1900-2100)、月: " << endl;
		cin >> y >> m;
		if (y < 1900 || y>2100)
		{
			cout << "年份超出范围" << endl;
			continue;
		}
		if (m > 12 || m < 1)
		{
			cout << "输入错误-月份不正确" << endl;
			continue;
		}
		calender(y, m, zeller(y, m));
		break;
	}
	return 0;


}