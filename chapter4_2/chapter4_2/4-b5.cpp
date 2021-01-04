/*王志业 1553449 3班*/
#include <iostream>
using namespace std;
void int2str_inverse(int num)
{
	int flag = 0;
	if (num < 0)
	{
		flag = 1;
		num = -num;
	}
	if (num < 1)
		return;
	cout << num % 10 << " ";
	int2str_inverse(num / 10);
	if (flag == 1)
		cout << "-";
}
int main()
{
	int num;
	while (1)
	{
		cout << "请输入一个整数" << endl;
		cin >> num;
		if (!cin)
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		break;
	}
	int2str_inverse(num);
	return 0;
}
