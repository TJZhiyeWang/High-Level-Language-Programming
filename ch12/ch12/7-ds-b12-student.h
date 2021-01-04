/*ÍõÖ¾Òµ 3°à 1553449*/
#include <iostream>
#include <iomanip>
using namespace std;

class student
{
protected:
	int   num;
	char  name[10];
	char  sex;
	float score;
	char  addr[30];
public:
	friend istream& operator >>(istream&, student&);
	friend ostream& operator <<(ostream&, student&);
	bool operator ==(student&);
	bool operator !=(student&);
};
istream& operator >>(istream&, student&);
ostream& operator <<(ostream&, student&);