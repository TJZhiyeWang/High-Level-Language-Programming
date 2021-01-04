/*王志业 3班 1553449*/
#include <iostream>
using namespace std;
int main()
{
	double x, y;
	int h;
	cout << "坐标" << endl;
	cin >> x >> y;
	cout << "该点高度为" << endl;
	if (x == 0) 
		h = 0;
	else if(y == 0)
		h = 0;
	else if (x > 0)
	{
		if (y > 0)
			h = 1;
		else
			h = 4;
	}
	else
	{
		if (y > 0)
			h = 2;
		else
			h = 3;
	}
	cout << h;
	return 0;
}