/* 1553449 王志业 3班 */
#include <iostream>
using namespace std;

#define  N  10	/* 假设最多转换10个数字 */

int main()
{
	char str[80], *p;
	int  a[N] = { 0 }, *pnum, *pa;
	bool is_num, is_minus;

	/* 上面的定义不准动，下面为程序的具体实现，要求不得再定义任何变量、常量、常变量 */
	cout << "请输入间隔含有若干数字的字符串" << endl;
	gets_s(str);
	p = str;
	pnum = a;
	is_num = 0;
	is_minus = 0;
	while (*p != '\0')
	{
		if ((pnum - a) / sizeof(int) == 10)
			is_minus = 1;
		if (is_minus)
			break;
		if (*p >= '0'&&*p <= '9')
		{
			if (!is_num)
			{

				*pnum = (*p) - '0';
				is_num = 1;
			}
			else
				*pnum = (*pnum) * 10 + (*p - '0');
		}
		else if (is_num)
		{
			pnum++;
			is_num = 0;
		}
		p++;
	}
	cout << "共有" << pnum - a + 1 << "个整数" << endl;
	pa = a;
	while (pa <= pnum)
	{
		cout << *pa << " ";
		pa++;
	}
	cout << endl;
	return 0;
}