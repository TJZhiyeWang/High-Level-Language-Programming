/*1553449 Õı÷æ“µ 3∞‡ */
#include <iostream>
#include <math.h>
#include "limits.h"
#include "11-b1-time.h"
using namespace std;

void Time::get(int &y, int &m, int &d)
{
	y = hour;
	m = min;
	d = sec;
}
Time::Time()
{
	hour = 0;
	min = 0;
	sec = 0;
}
Time::Time(int h, int m, int s)
{
	if (h < 0 || h>23 || m < 0 || m>59 || s < 0 || s>59)
	{
		h = 0;
		min = 0;
		s = 0;
	}
	hour = h;
	min = m;
	sec = s;
}
void Time::set(int h, int m, int s)
{
	if (h < 0 || h>23 || m < 0 || m>59 || s < 0 || s>59)
	{
		h = 0;
		m = 0;
		s = 0;
	}
	hour = h;
	min = m;
	sec = s;
}
void Time::show()
{
	printf(" %02d:%02d:%02d\n", hour, min, sec);
}
Time::Time(_int64 num)
{
	num--;
	num %= 60 * 60 * 24;
	if (num < 0)
	{
		num++;
		num += 60 * 60 * 24;
	}
	set(0, 0, 0);
	sec = (int)num % 60;
	min = (int)num / 60 % 60;
	hour = (int)num / 60 / 60;

}
Time::operator _int64()
{
	return hour * 3600 + min * 60 + sec;
}
Time Time::operator +(const _int64& d)
{
	return _int64(*this) + d;
}
Time operator +(int &d, Time &time)
{
	return _int64(time) + d;
}
Time Time::operator -(const _int64& d)
{
	return _int64(*this) - d;
}
_int64 Time::operator -(Time date)
{
	return _int64(*this) - _int64(date);
}
Time& Time::operator ++(int)//back
{
	Time t1(*this);
	_int64 num = 1;
	(*this) = (*this) + num;
	return t1;
}
Time Time::operator ++()
{
	_int64 num = 1;
	(*this) = (*this) + num;
	return (*this);
}
Time& Time::operator --(int)//front
{
	Time t1(*this);
	_int64 num = 1;
	(*this) = (*this) - num;
	return t1;
}
Time Time::operator --()
{
	_int64 num = 1;
	(*this) = (*this) - num;
	return (*this);
}
bool Time::operator >(Time &time)
{
	return _int64(*this) > _int64(time);
}
bool Time::operator <(Time &time)
{
	return _int64(*this) < _int64(time);
}
bool Time::operator >=(Time &time)
{
	return _int64(*this) >= _int64(time);
}
bool Time::operator <=(Time &time)
{
	return _int64(*this) <= _int64(time);
}
bool Time::operator ==(Time &time)
{
	return _int64(*this) == _int64(time);
}
bool Time::operator !=(Time &time)
{
	return _int64(*this) != _int64(time);
}