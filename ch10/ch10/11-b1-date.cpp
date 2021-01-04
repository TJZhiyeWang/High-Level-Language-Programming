/*1553449 王志业 3班 */
#include <iostream>
#include <math.h>
#include "11-b1-date.h"
using namespace std;


int Date::is_leap(int y)
{
	if ((y % 100 == 0 && y % 400 != 0) || y % 4 != 0)
		return 0;
	else
		return 1;
}
Date::Date()
{
	year = 1900;
	month = 1;
	day = 1;
}
void Date::get(int &y, int &m, int &d)
{
	y = year;
	m = month;
	d = day;
}
Date::Date(int y, int m, int d)
{
	int mon[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (is_leap(y))
		mon[1] += 1;
	if (y < 1900 || y>2099 || m < 1 || m>12 || d > mon[m - 1] || d < 1)
	{
		y = 1900;
		m = 1;
		d = 1;
	}
	year = y;
	month = m;
	day = d;
}
void Date::set(int y, int m, int d)
{
	int mon[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (is_leap(y))
		mon[1] += 1;
	if (y < 1900 || y>2099 || m < 1 || m>12 || d > mon[m - 1] || d < 1)
	{
		y = 1900;
		m = 1;
		d = 1;
	}
	year = y;
	month = m;
	day = d;
}
Date::Date(int num)
{
	num--;
	int mon[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (abs(num) >= 73049)
	{
		num = (num % 73049)*num / abs(num);
	}
	if (num >= 0)
	{
		num++;
		int toyear = 365;//1900年365天
		set(1900, 1, 1);
		while (num > toyear + is_leap(year))
		{
			num -= toyear + is_leap(year);
			year++;
		}
		int tomonth = 1;
		if (is_leap(year))
			mon[1] += 1;
		while (num > mon[tomonth - 1])
		{
			num -= mon[tomonth - 1];
			tomonth++;
			month++;
		}
		day = num;
	}
	else
	{
		set(2099, 12, 31);
		num = abs(num);
		num--;
		while (num > 0)
		{
			day--;
			if (day == 0)
			{
				if (month == 1)
				{
					if (is_leap(year))
						mon[1] -= 1;
					year--;
					if (is_leap(year))
						mon[1] += 1;
					month = 13;
				}

				day = mon[month - 2];
				month--;
			}
			num--;
		}
	}
}
Date::operator int()
{
	int mon[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int num = 0, temp_y = 1900;
	while (temp_y <= year)
	{
		int max_m, i = 0;
		if (temp_y == year)
			max_m = month - 1;
		else
			max_m = 12;
		if (is_leap(temp_y))
			mon[1] = 29;
		else
			mon[1] = 28;
		while (i <= max_m - 1)
		{
			num += mon[i];
			i++;
		}
		temp_y++;
	}
	num += day;
	return num;
}
Date Date:: operator +(const int &num)
{
	Date d1(*this);
	return num + int(d1);
}
Date Date ::operator -(const int &num)
{
	Date d1(*this);
	return int(d1) - num;
}
int Date:: operator -(Date date)
{
	int num = int(*this);
	int num1 = int(date);
	return num - num1;
}
Date& Date:: operator ++(int)//back
{
	Date d1(*this);
	int num = 1;
	(*this) = (*this) + num;
	return d1;
}
Date Date:: operator ++()
{
	int num = 1;
	(*this) = (*this) + num;
	return *this;
}
Date& Date:: operator --(int)//back
{
	Date d1(*this);
	int num = 1;
	(*this) = (*this) - num;
	return d1;
}
Date Date:: operator --()
{
	int num = 1;
	(*this) = (*this) - num;
	return *this;
}
bool Date:: operator >(Date &date)
{
	return int(*this) > int(date);
}
bool Date:: operator <(Date &date)
{
	return int(*this) < int(date);
}
bool Date:: operator >=(Date &date)
{
	return int(*this) >= int(date);
}
bool Date:: operator <=(Date &date)
{
	return int(*this) <= int(date);
}
bool Date:: operator ==(Date &date)
{
	return int(*this) == int(date);
}
bool Date:: operator !=(Date &date)
{
	return int(*this) != int(date);
}
istream& operator >> (istream &in, Date &date)
{
	int y, m, d;
	in >> y >> m >> d;
	date.set(y, m, d);
	return in;
}
ostream& operator << (ostream &out, Date &date)
{
	out << date.year << "年" << date.month << "月" << date.day << "日";
	return out;
}
Date operator +(const int &num, Date &d1)
{
	return int(d1) + num;
}



void Date::show()
{
	cout << year << "年" << month << "月" << day << "日";
}
int is_leap(int y)
{
	if ((y % 100 == 0 && y % 400 != 0) || y % 4 != 0)
		return 0;
	else
		return 1;
}