/*1553449 王志业 3班*/
#include <iostream>
#include "limits.h"
#include "11-b1-datetime.h"

DateTime::DateTime() :Date(), Time()
{}
DateTime::DateTime(int y, int mo, int d, int h, int m, int s)
{
	int mon[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (is_leap(y))
		mon[1] += 1;
	if (y < 1900 || y>2099 || mo < 1 || mo>12 || d > mon[mo - 1] || d < 1 || h < 0 || h>23 || m < 0 || m>59 || s < 0 || s>59)
	{
		y = 1900;
		mo = 1;
		d = 1;
		h = 0;
		m = 0;
		s = 0;
	}
	Date::set(y, mo, d);
	Time::set(h, m, s);
}
void DateTime::set(int y, int mo, int d, int h, int m, int s)
{
	int mon[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (is_leap(y))
		mon[1] += 1;
	if (y < 1900 || y>2099 || mo < 1 || mo>12 || d > mon[mo - 1] || d < 1 || h < 0 || h>23 || m < 0 || m>59 || s < 0 || s>59)
	{
		y = 1900;
		mo = 1;
		d = 1;
		h = 0;
		m = 0;
		s = 0;
	}
	Date::set(y, mo, d);
	Time::set(h, m, s);
}
DateTime::DateTime(_int64 num1)
{

	int num = (int)(num1 / (_int64)(60 * 60 * 24 + 1) + 1 * num1 / abs(num1));
	num1--;
	num1 %= 60 * 60 * 24;
	if (num1 < 0)
	{
		num1++;
		num1 += 60 * 60 * 24;
	}
	Time::set(0, 0, 0);
	sec = (int)num1 % 60;
	min = (int)num1 / 60 % 60;
	hour = ((int)num1 / 60 / 60) % 24;

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
		Date::set(1900, 1, 1);
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
		Date::set(2099, 12, 31);
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
DateTime::operator _int64()
{
	return hour * 3600 + min * 60 + sec + 60 * 60 * 24 * (_int64)int(*this);
}
DateTime DateTime::operator +(const _int64& d)
{
	DateTime date;
	_int64 num1 = d + 3600 * hour + 60 * min + sec;
	if (num1 < 0)
		num1 -= (60 * 60 * 24);
	Date dd = Date(int(*this) + num1 / (60 * 60 * 24));
	int y, m, da;
	dd.Date::get(y, m, da);
	date.Date::set(y, m, da);

	if (num1 > 60 * 60 * 24)
		num1--;
	num1 %= 60 * 60 * 24;
	if (num1 < 0)
	{
		num1 += (60 * 60 * 24);
	}
	date.Time::set(0, 0, 0);
	date.sec = (int)num1 % 60;
	date.min = (int)num1 / 60 % 60;
	date.hour = ((int)num1 / 60 / 60) % 24;


	return date;
}
DateTime DateTime::operator -(const _int64& d)
{
	DateTime date;
	_int64 num1 = -d + 3600 * hour + 60 * min + sec;
	if (num1 < 0)
		num1 -= (60 * 60 * 24);
	Date dd = Date(int(*this) + num1 / (60 * 60 * 24));
	int y, m, da;
	dd.Date::get(y, m, da);
	date.Date::set(y, m, da);


	num1 %= 60 * 60 * 24;
	if (num1 < 0)
	{
		num1 += (60 * 60 * 24);
	}

	date.Time::set(0, 0, 0);
	date.sec = (int)num1 % 60;
	date.min = (int)num1 / 60 % 60;
	date.hour = ((int)num1 / 60 / 60) % 24;


	return date;
}
_int64 DateTime::operator -(DateTime date)
{
	return (int(*this) - int(date)) * 3600 * 24 + 3600 * hour + 60 * min + sec - 3600 * date.hour - 60 * date.min - date.sec;
}
DateTime& DateTime::operator ++(int)
{
	DateTime t1(*this);
	_int64 num = 1;
	(*this) = (*this) + num;
	return t1;
}
DateTime DateTime::operator ++()
{
	_int64 num = 1;
	(*this) = (*this) + num;
	return (*this);
}
DateTime& DateTime::operator --(int)
{
	DateTime t1(*this);
	_int64 num = 1;
	(*this) = (*this) - num;
	return t1;
}
DateTime DateTime::operator --()
{
	_int64 num = 1;
	(*this) = (*this) - num;
	return (*this);
}
bool DateTime::operator >(DateTime &date)
{
	return (*this) - date > 0;
}
bool DateTime::operator <(DateTime &date)
{
	return (*this) - date < 0;
}
bool DateTime::operator >=(DateTime &date)
{
	return (*this) - date >= 0;
}
bool DateTime::operator <=(DateTime &date)
{
	return (*this) - date <= 0;
}
bool DateTime::operator ==(DateTime &date)
{
	return (*this) - date == 0;
}
bool DateTime::operator !=(DateTime &date)
{
	return (*this) - date != 0;
}
void DateTime::show()
{
	Date::show();
	Time::show();
}

DateTime operator +(_int64 &d, DateTime &da)
{
	DateTime date;
	int h, min, s;
	da.Time::get(h, min, s);
	_int64 num1 = d + 3600 * h + 60 * min + s;
	if (num1 < 0)
		num1 -= (60 * 60 * 24);
	Date dd = Date(int(da) + num1 / (60 * 60 * 24));
	int y, m, day;
	dd.Date::get(y, m, day);
	date.Date::set(y, m, day);

	if (num1 > 60 * 60 * 24)
		num1--;
	num1 %= 60 * 60 * 24;
	if (num1 < 0)
	{
		num1 += (60 * 60 * 24);
	}
	date.Time::set(((int)num1 / 60 / 60) % 24, (int)num1 / 60 % 60, (int)num1 % 60);
	return date;
}
istream& operator >> (istream &in, DateTime &date)
{
	int mon[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int y, mo, d, h, m, s;
	in >> y >> mo >> d >> h >> m >> s;
	date.set(y, mo, d, h, m, s);
	return in;
}
ostream& operator << (ostream &out, DateTime &date)
{
	out << date.year << "-" << date.month << "-" << date.day << " ";
	if (date.hour < 10)
		cout << '0';
	cout << date.hour << ":";
	if (date.min < 10)
		cout << '0';
	cout << date.min << ":";
	if (date.sec < 10)
		cout << '0';
	cout << date.sec << endl;
	return out;
}