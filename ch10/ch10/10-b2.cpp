/*1553449 王志业 3班 */
#include <iostream>
#include "10-b2.h"
using namespace std;
int mon[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 }, mon1[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
/* 给出 Date 类的所有成员函数的体外实现 */
Date::Date()
{
	year = 2000;
	month = 1;
	day = 1;
}
Date::Date(int y, int m, int d)
{
	if (y < 1900 || y>2099)
		y = 2000;
	if (m < 1 || m>12)
		m = 1;
	if ((y % 100 == 0 && y % 400 != 0) || y % 4 != 0)
	{
		if (d > mon[m - 1] || d < 1)
			d = 1;
	}
	else
	{
		if (d > mon1[m - 1] || d < 1)
			d = 1;
	}
	year = y;
	month = m;
	day = d;
}
void Date::set(int y, int m, int d)
{
	if (!y)
		y = year;
	if (!m)
		m = month;
	if (!d)
		d = day;
	if (y < 1900 || y>2099)
		y = 2000;
	if (m < 1 || m>12)
		m = 1;
	if ((y % 100 == 0 && y % 400 != 0) || y % 4 != 0)
	{
		if (d > mon[m - 1] || d < 1)
			d = 1;
	}
	else
	{
		if (d > mon1[m - 1] || d < 1)
			d = 1;
	}
	year = y;
	month = m;
	day = d;
}
void Date::get(int &y, int &m, int &d)
{
	y = year;
	m = month;
	d = day;
}
void Date::show()
{
	cout << year << "年" << month << "月" << day << "日" << endl;
}
Date::Date(int num)
{
	if (num <= 1)
	{
		year = 1900;
		month = 1;
		day = 1;
	}
	else if (num >= 73049)
	{
		year = 2099;
		month = 12;
		day = 31;
	}
	else
	{
		int toyear = 365;//1900年365天
		set(1900, 1, 1);

		while (num > toyear)
		{
			num -= toyear;
			year++;
			if ((year % 100 == 0 && year % 400 != 0) || year % 4 != 0)//平年
				toyear = 365;
			else
				toyear = 366;
		}
		int tomonth = 1;
		if (toyear == 365)
			while (num > mon[tomonth - 1])
			{
				num -= mon[tomonth - 1];
				tomonth++;
				month++;
			}
		else
			while (num > mon[tomonth - 1])
			{
				num -= mon[tomonth - 1];
				tomonth++;
				month++;
			}
		day = num;
	}
}
Date::operator int()
{
	int num = 0, temp_y = 1900;
	while (temp_y <= year)
	{
		int max_m, i = 0;
		if (temp_y == year)
			max_m = month - 1;
		else
			max_m = 12;
		if ((temp_y % 100 == 0 && temp_y % 400 != 0) || temp_y % 4 != 0)
		{
			while (i <= max_m - 1)
			{
				num += mon[i];
				i++;
			}
		}
		else
		{
			while (i <= max_m - 1)
			{
				num += mon1[i];
				i++;
			}
		}
		temp_y++;
	}
	num += day;
	return num;

}
Date Date:: operator +(int num)
{
	Date d1(*this);
	int toyear;
	num += d1.day;
	d1.day = 1;
	if (d1.month < 3)
	{
		if ((d1.year % 100 == 0 && d1.year % 400 != 0) || d1.year % 4 != 0)//平年
			toyear = 365;
		else
			toyear = 366;
	}
	else
	{
		if (((d1.year + 1) % 100 == 0 && (d1.year + 1) % 400 != 0) || (d1.year + 1) % 4 != 0)//平年
			toyear = 365;
		else
			toyear = 366;
	}
	while (num > toyear)
	{
		num -= toyear;
		d1.year++;
		if (d1.month < 3)
		{
			if ((d1.year % 100 == 0 && d1.year % 400 != 0) || d1.year % 4 != 0)//平年
				toyear = 365;
			else
				toyear = 366;
		}
		else
		{
			if (((d1.year + 1) % 100 == 0 && (d1.year + 1) % 400 != 0) || (d1.year + 1) % 4 != 0)//平年
				toyear = 365;
			else
				toyear = 366;
		}
	}
	int tomonth = d1.month;
	if (toyear == 365)
		while (num > mon[tomonth - 1])
		{
			num -= mon[tomonth - 1];
			if (tomonth == 12)
				d1.year++;
			tomonth = (tomonth % 12) + 1;
			d1.month = (d1.month % 12) + 1;
		}
	else
		while (num > mon1[tomonth - 1])
		{
			num -= mon1[tomonth - 1];
			if (tomonth == 12)
				d1.year++;
			tomonth = (tomonth % 12) + 1;
			d1.month = (d1.month % 12) + 1;
		}
	d1.day = num;
	if (d1.year < 1900)
	{
		d1.year = 1900;
		d1.month = 1;
		d1.day = 1;
	}
	if (d1.year > 2099)
	{
		d1.year = 2099;
		d1.month = 12;
		d1.day = 31;
	}
	return d1;
}
Date Date ::operator -(int num)
{
	Date d1(*this);
	int k;
	if ((d1.year % 100 == 0 && d1.year % 400 != 0) || d1.year % 4 != 0)
		k = 0;
	else
		k = 1;
	while (num > 0)
	{
		d1.day--;
		if (d1.day == 0)
		{
			if (d1.month == 1)
			{
				d1.year--;
				d1.month = 13;
				if ((d1.year % 100 == 0 && d1.year % 400 != 0) || d1.year % 4 != 0)
					k = 0;
				else
					k = 1;
			}
			if (k == 0)
				d1.day = mon[d1.month - 2];
			else
				d1.day = mon1[d1.month - 2];
			d1.month--;
		}
		num--;
	}
	if (d1.year < 1900)
	{
		d1.year = 1900;
		d1.month = 1;
		d1.day = 1;
	}
	if (d1.year > 2099)
	{
		d1.year = 2099;
		d1.month = 12;
		d1.day = 31;
	}
	return d1;
}
int Date:: operator -(Date date)
{
	int num = int(*this);
	int num1 = int(date);
	return num - num1;
}
Date& Date:: operator ++(int)//front
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
Date& Date:: operator --(int)//front
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
/* 如果有需要的其它全局函数的实现，可以写于此处 */
Date operator +(int num, Date d1)
{
	Date date(d1);
	int toyear;
	num += date.day;
	date.day = 1;
	if (date.month < 3)
	{
		if ((date.year % 100 == 0 && date.year % 400 != 0) || date.year % 4 != 0)//平年
			toyear = 365;
		else
			toyear = 366;
	}
	else
	{
		if (((date.year + 1) % 100 == 0 && (date.year + 1) % 400 != 0) || (date.year + 1) % 4 != 0)//平年
			toyear = 365;
		else
			toyear = 366;
	}
	while (num > toyear)
	{
		num -= toyear;
		date.year++;
		if (date.month < 3)
		{
			if ((date.year % 100 == 0 && date.year % 400 != 0) || date.year % 4 != 0)//平年
				toyear = 365;
			else
				toyear = 366;
		}
		else
		{
			if (((date.year + 1) % 100 == 0 && (date.year + 1) % 400 != 0) || (date.year + 1) % 4 != 0)//平年
				toyear = 365;
			else
				toyear = 366;
		}
	}
	int tomonth = date.month;
	if (toyear == 365)
		while (num > mon[tomonth - 1])
		{
			num -= mon[tomonth - 1];
			if (tomonth == 12)
				date.year++;
			tomonth = (tomonth % 12) + 1;
			date.month = (date.month % 12) + 1;
		}
	else
		while (num > mon[tomonth - 1])
		{
			num -= mon[tomonth - 1];
			if (tomonth == 12)
				date.year++;
			tomonth = (tomonth % 12) + 1;
			date.month = (date.month % 12) + 1;
		}
	date.day = num;
	return date;
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