/*王志业 3班 1553449*/
#include <iostream>
#include <iomanip>
#include <time.h>
#include <stdlib.h> 
#define num 10
using namespace std;
void password(int length, int C, int L, int N, int O,char pass[])
{
	int i;
	
	for (i = 0; i < length; i++)
	{
		
		pass[i] = rand() % (127 - 33) + 33;
		if (C + L + N + O == 0)
		{
			continue;
		}
		else if (pass[i] >= 65 && pass[i] <= 90)
		{
			if (C == 0)
			{
				i--;
				continue;
			}
			else
				C--;
		}
		else if (pass[i] >= 97 && pass[i] <= 122)
		{
			if (L == 0)
			{
				i--;
				continue;
			}
			else
				L--;
		}
		else if (pass[i] >= 48 && pass[i] <= 57)
		{
			if (N == 0)
			{
				i--;
				continue;
			}
			else
				N--;
		}
		else
		{
			if (O == 0)
			{
				i--;
				continue;
			}
			else
				O--;
		}
	}
	pass[length] = '\0';
}
int main()
{
	int length, Caps, Low, Num, Other;
	while (1)
	{
		cout << "请输入密码长度<12-16>" << endl;
		cin >> length;
		if (!cin)
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (length >= 12 && length <= 16)
			break;
	}
	while (1)
	{
		cout << "请输入大写字母个数（至少两个）" << endl;
		cin >> Caps;
		if (!cin)
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (Caps>=2)
			break;
	}
	while (1)
	{
		cout << "请输入小写字母个数（至少两个）" << endl;
		cin >> Low;
		if (!cin)
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (Low>= 2)
			break;
	}
	while (1)
	{
		cout << "请输入数字个数（至少两个）" << endl;
		cin >> Num;
		if (!cin)
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (Num >= 2)
			break;
	}
	while (1)
	{
		cout << "请输入大写字母个数（至少两个）" << endl;
		cin >> Other;
		if (!cin)
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (Other >= 2)
			break;
	}
	char word[num][17];
	srand((unsigned)time(0));
	int i;
	for (i = 0; i < num; i++)
	{
		
		password(length, Caps, Low, Num, Other, word[i]);
	}
	cout << length << " " << Caps << " " << Low << " " << Num << " " << Other << endl;
	for (i = 0; i < num; i++)
		cout << word[i] << endl;
	return 0;
}
