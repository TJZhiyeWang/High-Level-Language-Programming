/*王志业 1553449 3班*/
#include <iostream>
#include <string.h>
using namespace std;
bool is_reverse(char *str)
{
	char *p = str;
	char *q;
	int lenth = strlen(str);
	q = str + lenth - 1;
	if (lenth == 1 || lenth == 0)
		return true;
	while (lenth % 2 == 1 && q != p || lenth % 2 == 0 && p + 1 != q)
	{
		if (*q-- != *p++)
			return false;
	}
	return true;
}
int main()
{
	char str[80] = { 0 };
	cout << "请输入一个长度小于80的字符串（回文串）" << endl;
	gets_s(str);
	if (is_reverse(str))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	return 0;
}
