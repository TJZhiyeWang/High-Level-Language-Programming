/*1553449 ÍõÖ¾Òµ 3°à*/
#include <iostream>
#include <iomanip>
using namespace std;

class double1
{
protected:
	double num;
public:
	friend istream& operator >>(istream&, double1&);
	friend ostream& operator <<(ostream&, double1&);
	bool operator ==(double1&);
	bool operator !=(double1&);
};
istream& operator >>(istream&, double1&);
ostream& operator <<(ostream&, double1&);
