/*ÍõÖ¾Òµ 3°à 1553449*/
#include "7-ds-b12-student.h"
istream& operator >>(istream& in, student& stu)
{
	in >> stu.num >> stu.name >> stu.sex >> stu.addr >> stu.score;
	return in;
}

ostream& operator <<(ostream& out, student& stu)
{
	out << stu.num << " " << stu.name << " " << stu.sex << " " << stu.addr << " " << stu.score << endl;
	return out;
}

bool student::operator ==(student& stu)
{
	if (num != stu.num)
		return 0;
	if (sex != stu.sex)
		return 0;
	if (score != stu.score)
		return 0;
	if (strcmp(name, stu.name) != 0)
		return 0;
	if (strcmp(addr, stu.addr) != 0)
		return 0;
	return 1;
}
bool student::operator !=(student& stu)
{
	if (num != stu.num)
		return 1;
	if (sex != stu.sex)
		return 1;
	if (score != stu.score)
		return 1;
	if (strcmp(name, stu.name) != 0)
		return 1;
	if (strcmp(addr, stu.addr) != 0)
		return 1;
	return 0;
}