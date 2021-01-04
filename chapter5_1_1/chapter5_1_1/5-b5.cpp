/*1553449 3班 王志业*/
#include <iostream>
#include <iomanip>
using namespace std;
int a[10],b[10],c[10];
int num_a,num_b,num_c;
void move(char source,char target)
{
	int temp;
	if (source == 'A')
	{
		num_a--;
		temp = a[num_a];
		a[num_a] = 0;
	}
	else if (source == 'B')
	{
		num_b--;
		temp = b[num_b];
		b[num_b] = 0;
	}
	else
	{
		num_c--;
		temp = c[num_c];
		c[num_c] = 0;
	}
	if (target == 'A')
	{
		a[num_a] = temp;
		num_a++;
	}
	else if (target == 'B')
	{
		b[num_b] = temp;
		num_b++;
	}
	else
	{
		c[num_c] = temp;
		num_c++;
	}

}
void print(char stack)
{
	int i = 0;
	if (stack == 'A')
	{
		cout << "A:";
		for (; i < 10; i++)
		{
			if (a[i] != 0)
				cout << setw(2) << a[i];
			else
				cout << "  ";
		}
		cout << " ";
	}
	else if (stack == 'B')
	{
		cout << "B:";
		for (; i < 10; i++)
		{
			if (b[i] != 0)
				cout << setw(2) << b[i];
			else
				cout << "  ";
		}
		cout << " ";
	}
	else
	{
		cout << "C:";
		for (; i < 10; i++)
		{
			if (c[i] != 0)
				cout << setw(2) << c[i];
			else
				cout << "  ";
		}
		cout << " ";
	}

}
void Hanoi(int num, char initial, char target)
{
	static int step = 1;
	char target1, temp;
	if (num == 0)
		return;
	if (initial == 'A')
	{
		if (target == 'B')
			target1 = 'C';
		else
			target1 = 'B';
	}
	else if (initial == 'B')
	{
		if (target == 'C')
			target1 = 'A';
		else
			target1 = 'C';
	}
	else if (initial == 'C')
	{
		if (target == 'A')
			target1 = 'B';
		else
			target1 = 'A';
	}
	temp = target;
	target = target1;
	target1 = temp;
	Hanoi(num - 1, initial, target);
	move(initial, target1);
	cout<<"第"<<setw(4)<<step<<"步(" << setw(2)<<num<<"): "  << initial << "-->" << target1<<" ";
	print('A');
	print('B');
	print('C');
	cout << endl;
	step++;
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
	if (initial == 'A')
	{
		num_a = num;
		for (int i = 0; i < num; i++)
		{
			a[i] = num - i;
		}
	}
	if (initial == 'B')
	{
		num_b = num;
		for (int i = 0; i < num; i++)
		{
			b[i] = num - i;
		}
	}
	if (initial == 'C')
	{
		num_c = num;
		for (int i = 0; i < num; i++)
		{
			c[i] = num - i;
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
	cout << "初始:"<<"               ";
	print('A');
	print('B');
	print('C');
	cout << endl;
	Hanoi(num, initial, target);
	return 0;
}
