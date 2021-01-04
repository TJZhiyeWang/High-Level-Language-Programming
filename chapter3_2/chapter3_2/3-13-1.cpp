/*1553449 王志业 3班*/
#include <iostream>
using namespace std;
int main()
{
	int pro,mo=0;
	cout << "请输入当月利润" << endl;
	cin >> pro;
	cout << "应发奖金数" << endl;
	if (pro > 1000000)
	{
		mo += (int)((pro - 1000000)*0.01);
		pro = 1000000;
	}
	if (pro > 600000 && pro <= 1000000)
	{
		mo+= (int)((pro - 600000)*0.015);
		pro = 600000;
	}
	if (pro > 400000 && pro <= 600000)
	{
		mo += (int)((pro - 400000)*0.03);
		pro = 400000;
	}
	if (pro > 200000 && pro <= 400000)
	{
		mo += (int)((pro - 200000)*0.05);
		pro = 200000;
	}
	if (pro > 100000 && pro <= 200000)
	{
		mo += (int)((pro - 100000)*0.075);
		pro = 100000;
	}
	if (pro <= 100000)
		mo += (int)(pro*0.1);
	cout << mo;
	return 0;
}
