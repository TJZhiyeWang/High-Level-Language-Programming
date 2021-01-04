/*王志业 3班 1553449*/
#include <iostream>
using namespace std;
int is_power(int num, int base)
{
	if ((num == base &&num%base == 0) || num == 1)
		return 1;
	else if (num < base || num%base != 0)
		return 0;
	return is_power(num / base, base);
}


int main()
{
	int num, base;
	while (1)
	{
		cout << "请输入整数num及基数base：" << endl;
		cin >> num >> base;
		if (!cin)
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (num <= 0||base<=0)
			continue;
		break;
	}
	if (is_power(num, base))
		cout << "十进制整数" << num << "是" << base << "的幂" << endl;
	else
		cout << "十进制整数" << num << "不是" << base << "的幂" << endl;
	return 0;
}
