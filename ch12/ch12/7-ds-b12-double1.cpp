/*ÍõÖ¾Òµ 3°à 1553449*/
#include "7-ds-b12-double1.h"

istream& operator >>(istream& in, double1& dou)
{
	in >> dou.num;
	return in;
}
ostream& operator <<(ostream& out, double1& dou)
{
	out << dou.num << endl;
	return out;
}
bool double1::operator ==(double1& dou)
{
	if (fabs(num - dou.num) <= 0.00001)
		return 1;
	return 0;
}
bool double1::operator !=(double1& dou)
{
	if (fabs(num - dou.num) <= 0.00001)
		return 0;
	return 1;
}