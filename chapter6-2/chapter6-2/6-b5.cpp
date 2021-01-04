/*王志业 1553449 3班*/
#include <iostream>
#include <string.h>
using namespace std;
unsigned int binary(char *str)
{
	unsigned int result = 0;
	char *p = str;
	while (*p != '\0')
	{
		result = result * 2 + *p - '0';
		p++;
	}
	return result;
}
int main()
{
	char str[33];
	int flag = 1;
	cout << "请输入一个0/1组成的字符串，长度不超过32" << endl;
	cin >> str;
	cout << binary(str) << endl;
	return 0;
}
