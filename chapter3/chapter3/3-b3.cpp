/*王志业 1553449 3班*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double num;
	int s;
	cin >> num;
	s = (int)floor(num*10e-10);
	cout << "十亿位" << s << endl;
	s = (int)floor(num*10e-9) - s*10;
	cout << "亿位" << s << endl;
	s = (int)floor(num*10e-8) - (int)floor(num*10e-9) * 10;
	cout << "千万位" << s << endl;
	s = (int)floor(num*10e-7) - (int)floor(num*10e-8) * 10;
	cout << "百万位" << s << endl;
	s = (int)floor(num*10e-6) - (int)floor(num*10e-7) * 10;
	cout << "十万位" << s << endl;
	s = (int)floor(num*10e-5) - (int)floor(num*10e-6) * 10;
	cout << "万位" << s << endl;
	s = (int)floor(num*10e-4) - (int)floor(num*10e-5) * 10;
	cout << "千位" << s << endl;
	s = (int)floor(num*10e-3) - (int)floor(num*10e-4) * 10;
	cout << "百位" << s << endl;
	s = (int)floor(num*10e-2) - (int)floor(num*10e-3) * 10;
	cout << "十位" << s << endl;
	s =(int)(floor(num*10e-1) - floor(num*10e-2) * 10);
	cout << "个位" << s << endl;
	num += 1e-6;
	s = (int)(floor(num*10) - floor(num) * 10);
	cout << "十分位" << s << endl;
	s = (int)(floor(num*100) - floor(num*10) * 10);
	cout << "百分位" << s << endl;
	return 0;

}