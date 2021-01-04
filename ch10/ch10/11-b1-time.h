/* 1553449 王志业 3班 */
#include <iostream>
using namespace std;


class Time {
protected:
	int hour;
	int min;
	int sec;
public:
	/* 根据需要定义所需的成员函数、友元函数等 */
	Time();
	void get(int &y, int &m, int &d);
	Time(int y, int m, int d);
	void set(int y, int m, int d);
	void show();
	Time(_int64 num);
	operator _int64();
	Time operator +(const _int64& d);
	friend Time operator +(int &d, Time &date);
	Time operator -(const _int64& d);
	_int64 operator -(Time date);
	Time& operator ++(int);//front
	Time operator ++();
	Time& operator --(int);//front
	Time operator --();
	bool operator >(Time &date);
	bool operator <(Time &date);
	bool operator >=(Time &date);
	bool operator <=(Time &date);
	bool operator ==(Time &date);
	bool operator !=(Time &date);
};

/* 如果有其它全局函数需要声明，写于此处 */
Time operator +(int &d, Time &date);
