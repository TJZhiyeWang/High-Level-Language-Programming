/*1553449 3班 王志业*/
#include <iostream>
using namespace std;
void Hanoi(int num, char initial, char target)
{
	char target1, temp;
	if (num == 0)
		return;
	if (initial == 'a' || initial == 'A')
	{
		if (target == 'b' || target == 'B')
			target1 = 'C';
		else if (target == 'c' || target == 'C')
			target1 = 'B';
	}
	else if (initial == 'b' || initial == 'B')
	{
		if (target == 'c' || target == 'C')
			target1 = 'A';
		else if (target == 'a' || target == 'A')
			target1 = 'C';
	}
	else if (initial == 'c' || initial == 'C')
	{
		if (target == 'a' || target == 'A')
			target1 = 'B';
		else if (target == 'b' || target == 'B')
			target1 = 'A';
	}
	temp = target;
	target = target1;
	target1 = temp;
	Hanoi(num - 1, initial, target);
	cout << num << "# " << initial << "-->" << target1 << endl;
	Hanoi(num - 1, target, target1);
}
int main()
{
	char initial, target;
	int num;
	while (1)
	{
		cout << "请输入汉诺塔的层数<1-64>:" << endl;
		cin >> num;

		if (!cin)
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (num <= 0)
			continue;
		break;
	}
	while (1)
	{
		cout << "请输入起始柱<A-C>:" << endl;
		cin >> initial;
		if ((initial >= 'A'&&initial <= 'C') || (initial >= 'a'&&initial <= 'c'))
		{
			if (initial >= 'a')
				initial -= 'a' - 'A';
			break;
		}
		else
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
	}
	while (1)
	{
		cout << "请输入目标柱<A-C>:" << endl;
		cin >> target;
		if ((target >= 'A'&&target <= 'C'&&target != initial) || (target >= 'a'&&target <= 'c'&&target != initial + 32))
		{
			if (target >= 'a')
				target -= 'a' - 'A';
			break;
		}
		else
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
	}
	cout << "移动步骤为:" << endl;
	Hanoi(num, initial, target);
	return 0;
}
