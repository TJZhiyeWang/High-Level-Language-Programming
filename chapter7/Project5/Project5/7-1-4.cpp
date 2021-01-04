/*1553449 3班 王志业*/
#include <iostream>
using namespace std;
struct date
{
	int year;
	int month;
	int day;
};
void days(date &d)
{
	int mon[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 }, mon1[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 }, i = 0, num = 0;
	if (d.month > 12 || d.month < 1)
	{
		cout << "输入有误" << endl;
		return;
	}
	else
	{
		if ((d.year % 100 == 0 && d.year % 400 != 0) || d.year % 4 != 0)
		{
			if (mon[d.month - 1] < d.day || d.day < 1)
			{
				cout << "输入有误" << endl;
				return;
			}
			else
			{
				while (i < d.month - 1)
				{
					num += mon[i];
					i++;
				}
				num = num + d.day;
				cout << num;
			}
		}
		else
		{
			if (mon1[d.month - 1] < d.day || d.day < 1)
			{
				cout << "输入有误" << endl;
				return;
			}
			else
			{
				while (i < d.month - 1)
				{
					num += mon1[i];
					i++;
				}
				num = num + d.day;
				cout << num;
			}
		}
	}

}
int main()
{
	date d;
	cin >> d.year >>d.month >>d.day;
	days(d);
	return 0;
}
