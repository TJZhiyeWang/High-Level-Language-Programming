/*王志业 3班 1553449*/
#include <iostream>
using namespace std;
void int2str(int num)
{
	if (num < 0)
	{
		cout << "- ";
		num = -num;
	}
	if (num < 1)
		return;
	int2str(num / 10);
	cout << num % 10<<" ";
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
	int2str(num);
	return 0;
}
