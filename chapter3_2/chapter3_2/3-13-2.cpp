/*1553449 王志业 3班*/
#include <iostream>
using namespace std;
int main()
{
	int pro, mo = 0;
	cout << "请输入当月利润" << endl;
	cin >> pro;
	cout << "应发奖金数" << endl;
	switch (pro / 100000)
	{
		case 0:mo = (int)pro*0.1; break;
		case 1:mo = (int)((pro - 100000)*0.075) + 10000; break;
		case 2:
		case 3:mo = (int)((pro - 200000)*0.05) + 17500; break;
		case 4:
		case 5:mo = (int)((pro - 400000)*0.03) + 27500; break;
		case 6:
		case 7:
		case 8:
		case 9:mo = (int)((pro - 60000)*0.015) + 33500; break;
		default:mo = (int)((pro - 1000000)*0.01) + 39500;
	}
	cout << mo;
	return 0;
}
