/*1553449 王志业 3班*/
#include <iostream>
#define max_length 80
using namespace std;

int main()
{
	char password[max_length];
	char keyword[max_length];
	
	int i = 0, temp;
	cout << "请输入密码串" << endl;
	gets_s(password, max_length - 1);
	while (password[i] != '\0')
	{
		if (password[i] >= 'a'&&password[i] < 'z')
		{
			temp = password[i] - int('a') + 1;
			temp = 26 - temp + 1;
			keyword[i] = char('a' + temp - 1);
		}
		else if (password[i] >= 'A'&&password[i] < 'Z')
		{
			temp = password[i] - int('A') + 1;
			temp = 26 - temp + 1;
			keyword[i] = char('A' + temp - 1);
		}
		else
			keyword[i] = password[i];
		i++;
	}
	keyword[i] = '\0';
	cout << "密文：" << password;
	cout << endl << "原文：" << keyword << endl;
	return 0;
}