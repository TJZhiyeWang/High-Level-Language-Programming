/* 1553449 王志业 3班 */
#include <iostream>
using namespace std;

/* 补全Date类的定义，所有成员函数均体外实现，不要在此处体内实现 */
class Date {
private:
	int year;
	int month;
	int day;
public:
	/* 根据需要定义所需的成员函数、友元函数等 */
	
	Date();
	Date(int y, int m, int d);
	void set(int y, int m = 1, int d = 1);
	void get(int &y, int &m, int &d);
	void show();
	Date(int num);
	operator int();
	Date operator +(int d);
	friend Date operator +(int d, Date date);
	Date operator -(int d);
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
Date operator +(int d, Date date);

/* 如果有需要的宏定义、只读全局变量等，写于此处 */
extern int mon[12], mon1[12];