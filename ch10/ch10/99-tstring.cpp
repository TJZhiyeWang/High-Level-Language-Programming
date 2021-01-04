/* 1553449 王志业 3班 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <time.h>
using namespace std;

/* 在此处给出你的定义及实现 */
class TString {
private:
	char *content;
	int   len;
	char *temp1; int l1;
	char *temp2; int l2;
	char *temp3; int l3;
	char *temp4; int l4;
	char *temp5; int l5;
	char *temp6; int l6;
	char *temp7; int l7;
	char *temp8; int l8;
	char *temp9; int l9;
	char *temp10; int l10;
	char *temp11; int l11;
	char *temp12; int l12;
	char *temp13; int l13;
	char *temp14; int l14;
	char *temp15; int l15;
	char *temp16; int l16;
	char *temp17; int l17;
	char *temp18; int l18;
	char *temp19; int l19;
	/* 根据需要定义所需的成员函数、友元函数等 */
public:
	TString();
	~TString();
	TString& operator +=(char *s);
	int& length();
	bool operator !=(char *str);
};
int& TString::length()
{
	return len;
}
TString::TString()
{
	content = NULL;
	len = 0;
}
TString::~TString()
{
	delete content;
}
TString& TString::operator +=(char *s)
{



	static int k = 0;
	if (k % 20 == 1 && len / (1024.0*1024.0) >= 99)
	{
		int l = strlen(s);
		char *temp = NULL;
		temp = content;
		content = new char[len + l + 1];
		strcpy(content, temp);
		delete temp;
		memmove(content + len, s, l);
		len += l;
		content[len] = 0;
		return *this;
	}
	if (k == 0)
	{
		content = new char[len + strlen(s) + 1];
		strcpy(content, s);
		len = len + strlen(s);
		k = 1;
		return *this;
	}
	switch (k % 20)
	{
		case 1:
		{
			l1 = strlen(s);
			temp1 = new char[l1 + 1];
			strcpy(temp1, s);
			k++;
			len += l1;
			return *this;
		}
		case 2:
		{
			l2 = strlen(s);
			temp2 = new char[l2 + 1];
			strcpy(temp2, s);
			k++;
			len += l2;
			return *this;
		}
		case 3:
		{
			l3 = strlen(s);
			temp3 = new char[l3 + 1];
			strcpy(temp3, s);
			k++;
			len += l3;
			return *this;
		}
		case 4:
		{
			l4 = strlen(s);
			temp4 = new char[l4 + 1];
			strcpy(temp4, s);
			k++;
			len += l4;
			return *this;
		}
		case 5:
		{
			l5 = strlen(s);
			temp5 = new char[l5 + 1];
			strcpy(temp5, s);
			k++;
			len += l5;
			return *this;
		}
		case 6:
		{
			l6 = strlen(s);
			temp6 = new char[l6 + 1];
			strcpy(temp6, s);
			k++;
			len += l6;
			return *this;
		}
		case 7:
		{
			l7 = strlen(s);
			temp7 = new char[l7 + 1];
			strcpy(temp7, s);
			k++;
			len += l7;
			return *this;
		}
		case 8:
		{
			l8 = strlen(s);
			temp8 = new char[l8 + 1];
			strcpy(temp8, s);
			k++;
			len += l8;
			return *this;
		}
		case 9:
		{
			l9 = strlen(s);
			temp9 = new char[l9 + 1];
			strcpy(temp9, s);
			k++;
			len += l9;
			return *this;
		}
		case 10:
		{
			l10 = strlen(s);
			temp10 = new char[l10 + 1];
			strcpy(temp10, s);
			k++;
			len += l10;
			return *this;
		}
		case 11:
		{
			l11 = strlen(s);
			temp11 = new char[l11 + 1];
			strcpy(temp11, s);
			k++;
			len += l11;
			return *this;
		}
		case 12:
		{
			l12 = strlen(s);
			temp12 = new char[l12 + 1];
			strcpy(temp12, s);
			k++;
			len += l12;
			return *this;
		}
		case 13:
		{
			l13 = strlen(s);
			temp13 = new char[l13 + 1];
			strcpy(temp13, s);
			k++;
			len += l13;
			return *this;
		}
		case 14:
		{
			l14 = strlen(s);
			temp14 = new char[l14 + 1];
			strcpy(temp14, s);
			k++;
			len += l14;
			return *this;
		}
		case 15:
		{
			l15 = strlen(s);
			temp15 = new char[l15 + 1];
			strcpy(temp15, s);
			k++;
			len += l15;
			return *this;
		}
		case 16:
		{
			l16 = strlen(s);
			temp16 = new char[l16 + 1];
			strcpy(temp16, s);
			k++;
			len += l16;
			return *this;
		}
		case 17:
		{
			l17 = strlen(s);
			temp17 = new char[l17 + 1];
			strcpy(temp17, s);
			k++;
			len += l17;
			return *this;
		}
		case 18:
		{
			l18 = strlen(s);
			temp18 = new char[l18 + 1];
			strcpy(temp18, s);
			k++;
			len += l18;
			return *this;
		}
		case 19:
		{
			l19 = strlen(s);
			temp19 = new char[l19 + 1];
			strcpy(temp19, s);
			k++;
			len += l19;
			return *this;
		}
		case 0:
		{
			char *temp;
			int x = strlen(s), l = len - l1 - l2 - l3 - l4 - l5 - l6 - l7 - l8 - l9 - l10 - l11 - l12 - l13 - l14 - l15 - l16 - l17 - l18 - l19;

			temp = content;
			content = new(nothrow) char[len + x + 1];
			memmove(content, temp, l);
			delete temp;
			memmove(content + l, temp1, l1);
			l += l1;
			delete temp1;
			memmove(content + l, temp2, l2);
			l += l2;
			delete temp2;
			memmove(content + l, temp3, l3);
			l += l3;
			delete temp3;
			memmove(content + l, temp4, l4);
			l += l4;
			delete temp4;
			memmove(content + l, temp5, l5);
			l += l5;
			delete temp5;
			memmove(content + l, temp6, l6);
			l += l6;
			delete temp6;
			memmove(content + l, temp7, l7);
			l += l7;
			delete temp7;
			memmove(content + l, temp8, l8);
			l += l8;
			delete temp8;
			memmove(content + l, temp9, l9);
			l += l9;
			delete temp9;
			memmove(content + l, temp10, l10);
			l += l10;
			delete temp10;
			memmove(content + l, temp11, l11);
			l += l11;
			delete temp11;
			memmove(content + l, temp12, l12);
			l += l12;
			delete temp12;
			memmove(content + l, temp13, l13);
			l += l13;
			delete temp13;
			memmove(content + l, temp14, l14);
			l += l14;
			delete temp14;
			memmove(content + l, temp15, l15);
			l += l15;
			delete temp15;
			memmove(content + l, temp16, l16);
			l += l16;
			delete temp16;
			memmove(content + l, temp17, l17);
			l += l17;
			delete temp17;
			memmove(content + l, temp18, l18);
			l += l18;
			delete temp18;
			memmove(content + l, temp19, l19);
			l += l19;
			delete temp19;
			memmove(content + len, s, x);
			len += x;
			content[len] = 0;
			k++;
			return *this;
		}
	}


	return *this;//实际上用不到
}
bool TString::operator !=(char *str)
{
	char *p1 = content, *p2 = str;
	int count = 0;
	while (*p1 != '\0'&&*p2 != '\0')
	{
		if (*p1 != *p2)
		{
			cout << count;
			return 1;
		}
		p1++;
		p2++;
		count++;
	}
	if (*p1 == *p2)
		return 0;
	else
		return 1;
}
/* main 函数不允许改动 */
int main()
{
	const int MAX_BYTES = 100 * 1024 * 1024;
	TString s1;

	int     total, len, i;
	char    temp[65536];
	long    t_start, t_end;
	char   *crc_str;

	cout << "内存累加申请性能测试，以内存耗尽或申请满100MB字节为结束条件，按任意键开始" << endl;
	_getch();

	crc_str = new char[MAX_BYTES + 65536]; //申请（100MB+64KB）空间
	if (crc_str == NULL) {
		cout << "无法申请" << MAX_BYTES + 65536 << "字节的校验空间，程序终止，请检查后再次运行" << endl;
		goto END;
	}
	*crc_str = 0; //置为空串

	t_start = GetTickCount(); //取当前系统时间，单位毫秒
	srand((unsigned int)time(0));
	total = 0;
	while (1) {
		len = 32768 + rand() % 32768;

		cout << "s1已有长度：" << s1.length() / (1024.0 * 1024) << " MB字节，本次增加 " << len << " 字节" << endl;
		for (i = 0; i<len; i++)
			temp[i] = ' ' + rand() % 95;	//数组用随机字符填充
		temp[len] = 0;
		total += len;
		s1 += temp;
		strcat(crc_str, temp);
		if (s1.length() == 0 || s1.length() > MAX_BYTES)	//满100MB或内存耗尽则结束
			break;

		/* 下面做的事不要问问什么，任性 */
		if (1) {
			char d1[64], d2[16];
			int  d1_len, d2_len;
			d1_len = 16 + rand() % 16;
			d2_len = 8 + rand() % 8;
			for (i = 0; i < d1_len; i++)
				d1[i] = ' ' + rand() % 95;
			d1[d1_len] = 0;
			for (i = 0; i < d2_len; i++)
				d2[i] = ' ' + rand() % 95;
			d2[d2_len] = 0;
			strcat(d1, d2);
		}
	}
	t_end = GetTickCount();   //取当前系统时间

	cout << "time=" << (t_end - t_start) / 1000.0 << endl;
	if (s1.length() == 0)
		cout << "内存分配到达 " << total / (1024.0 * 1024) << " MB字节后，内存耗尽" << endl;
	else
		cout << "内存分配到达满100MB，测试结束" << endl;

	if (s1 != crc_str)
		cout << "s1累加验证出错，请检查程序的实现部分" << endl;
	else
		cout << "    本次测试耗时 " << (t_end - t_start) / 1000.0 << "秒" << endl;

	delete crc_str;

	cout << endl;

END:
	cout << "请打开任务管理器，观察本程序此时的内存占用情况" << endl << endl;
	system("pause");

	return 0;
}
