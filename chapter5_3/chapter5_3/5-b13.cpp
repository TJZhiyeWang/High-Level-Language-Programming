/*1553449 Õı÷æ“µ 3∞‡*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#define num_max 50
using namespace std;
void input_data(char name[][10], char num[][10], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "input name and NO. of student" << i + 1 << ":";
		cin >> name[i] >> num[i];
	}
}
void search(char name[][10], char num[][10], char target[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (strcmp(target, name[i]) == 0)
		{
			cout << name[i]<<"has been found,his number is "<<num[i]<< endl;
			break;
		}
	}
	if (i == n)
		cout << "can't find this name" << endl;
}
int main()
{
	char name[num_max][10];
	char num[num_max][10];
	char target[30];
	int n;
	cout << "Please input number of this class:";
	cin >> n;
	input_data(name, num, n);
	cout << "please input name you want to find£∫";
	cin >> target;
	search(name, num, target, n);
	return 0;
}
