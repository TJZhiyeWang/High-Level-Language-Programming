/*1553449 ÍõÖ¾Òµ °à*/
#include <iostream>
#include "11-b1-date.h"
#include "11-b1-time.h"
using namespace std;
class DateTime :public Date, public Time
{
public:
	DateTime();
	DateTime(int y, int mo, int d, int h, int m, int s);
	void set(int y, int mo, int d, int h, int m, int s);
	void show();
	DateTime(_int64);
	operator _int64();
	DateTime operator +(const _int64& d);
	friend DateTime operator +(int &d, DateTime &date);
	DateTime operator -(const _int64& d);
	_int64 operator -(DateTime date);
	DateTime& operator ++(int);//front
	DateTime operator ++();
	DateTime& operator --(int);//front
	DateTime operator --();
	bool operator >(DateTime &date);
	bool operator <(DateTime &date);
	bool operator >=(DateTime &date);
	bool operator <=(DateTime &date);
	bool operator ==(DateTime &date);
	bool operator !=(DateTime &date);

	friend istream& operator >> (istream &, DateTime &date);
	friend ostream& operator << (ostream &, DateTime &date);
};
DateTime operator +(_int64 &d, DateTime &date);
istream& operator >> (istream &, DateTime &date);
ostream& operator << (ostream &, DateTime &date);