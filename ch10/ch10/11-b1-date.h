/* 1553449 王志业 3班 */
#include <iostream>
using namespace std;

class Date {
protected:
	int year;
	int month;
	int day;
public:
	/* 根据需要定义所需的成员函数、友元函数等 */
	Date();
	Date(int y, int m, int d);
	void set(int y, int m, int d);
	int is_leap(int y);
	void show();
	void get(int &y, int &m, int &d);
	Date(int num);
	operator int();
	Date operator +(const int& d);
	friend Date operator +(int &d, Date &date);
	Date operator -(const int& d);
	int operator -(Date date);
	Date& operator ++(int);//front
	Date operator ++();
	Date& operator --(int);//front
	Date operator --();
	friend istream& operator >> (istream &, Date &date);
	friend ostream& operator << (ostream &, Date &date);
	bool operator >(Date &date);
	bool operator <(Date &date);
	bool operator >=(Date &date);
	bool operator <=(Date &date);
	bool operator ==(Date &date);
	bool operator !=(Date &date);
};

/* 如果有其它全局函数需要声明，写于此处 */
Date operator +(int &d, Date &date);
int is_leap(int y);