/*王志业 3班 1553449*/
#include <iostream>
using namespace std;
int main()
{
	int inte;
	cin >> inte;
	cout << "万位：" << inte / 10000<<endl;
	inte -= inte / 10000 * 10000;
	cout << "千位：" << inte / 1000<<endl;
	inte -= inte / 1000 * 1000;
	cout << "百位：" << inte / 100<<endl;
	inte -= inte / 100 * 100;
	cout << "十位：" << inte / 10<<endl;
	inte -= inte / 10 * 10;
	cout << "个位：" << inte;
	return 0;
}