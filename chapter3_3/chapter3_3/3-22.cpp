/*王志业 3班 1553449*/
#include <iostream>
using namespace std;
int main()
{
	int sum=1, i,day;
	cout << "请输入第几天桃子数为1" << endl;
	cin >> day;
	for (i = 0; i < day - 1; i++)
		sum = (sum + 1) * 2;
	cout << "第一天的桃子数=" << sum;
	return 0;
}