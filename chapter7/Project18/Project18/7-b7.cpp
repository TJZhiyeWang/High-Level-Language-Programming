/*1553449 3班 王志业*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
int main()
{
	short on_off_switch = 0x0000;
	char ch[4] = "\0\0\0", ch1;
	int i;
	while (1)
	{
		char choice[4] = "\0\0\0";
		cout << "请输入灯的开关情况" << endl;
		cin >> ch;
		for (i = 0; i < 3; i++)
		{
			if (ch[i] >= 'a'&&ch[i] <= 'z')
				ch[i] = ch[i] - 'a' + 'A';
		}
		if (strcmp(ch, "END") == 0)
			break;
		else if (strlen(ch) != 1)
		{
			cout << "输入有误，请重新输入" << endl;
			continue;
		}
		else if (ch[0] > 'J' || ch[0] < 'A')
		{
			cout << "输入有误，请重新输入" << endl;
			continue;
		}
		cin >> choice;
		for (i = 0; i < 3; i++)
		{
			if (choice[i] >= 'a'&&choice[i] <= 'z')
				choice[i] = choice[i] - 'a' + 'A';
		}

		if (strcmp(choice, "ON") == 0)
			on_off_switch |= 0x0001 << int(ch[0] - 'A');
		else if (strcmp(choice, "OFF") == 0)
			on_off_switch &= ~(0x0001 << int(ch[0] - 'A'));
		else
		{
			cout << "输入有误，请重新输入1" << endl;
			continue;
		}
		for (i = 0; i < 10; i++)
			cout << setw(4) << char(i + 'A');
		cout << endl;
		for (i = 0; i < 10; i++)
		{
			if ((on_off_switch&(0x0001 << i))>0)
				cout << setw(4) << "ON";
			else
				cout << setw(4) << "OFF";
		}
		cout << endl;
	}
	return 0;
}