/* 1553449 3班 王志业*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "10-b3.h"
using namespace std;

/* 给出 TString 类的所有成员函数的体外实现 */
TString::TString()
{
	content = NULL;
	len = 0;
}
TString::~TString()
{
	delete content;
}

//复制构造
TString::TString(TString& str)
{
	if (str.content)
	{
		content = new(nothrow) char[str.len + 1];
		strcpy(content, str.content);
	}
	else
		content = NULL;
	len = str.len;
}
//初始化
TString::TString(char *s)
{
	if (s && (*s))
	{
		content = new(nothrow) char[strlen(s) + 1];
		strcpy(content, s);
		len = strlen(s);
	}
	else
	{
		content = NULL;
		len = 0;
	}
}
TString& TString::operator =(const char *s)
{
	if (content)
		delete content;
	content = NULL;
	len = 0;
	if (s&&*s)
	{
		content = new(nothrow) char[strlen(s) + 1];
		strcpy(content, s);
		len = strlen(s);
	}

	return (*this);
}
TString& TString::operator =(TString& str)
{
	if (content)
		delete content;
	content = NULL;
	if (str.content)
	{
		content = new(nothrow) char[str.len + 1];
		strcpy(content, str.content);
	}
	len = str.len;
	return *this;
}//无复制构造函数，如果传入一个形参，就会导致content指针的地址被~掉
TString::operator char*()
{
	return content;
}
bool TString::operator >(char *str)
{
	char *p1 = content, *p2 = str;
	if (p1 == NULL || p2 == NULL)
	{
		if (p1 == p2)
			return 0;
		return p1 == NULL ? 0 : 1;
	}
	while (*p1 != '\0'&&*p2 != '\0')
	{
		if (*p1 != *p2)
			return *p1 > *p2 ? 1 : 0;
		p1++;
		p2++;
	}
	if (*p1 == *p2)
		return 0;
	return *p1 == '/0' ? 0 : 1;
}
bool TString::operator <(char *str)
{
	char *p1 = content, *p2 = str;
	if (p1 == NULL || p2 == NULL)
	{
		if (p1 == p2)
			return 0;
		return p1 == NULL ? 1 : 0;
	}
	while (*p1 != '\0'&&*p2 != '\0')
	{
		if (*p1 != *p2)
			return *p1 > *p2 ? 0 : 1;
		p1++;
		p2++;
	}
	if (*p1 == *p2)
		return 0;
	return *p1 == '/0' ? 1 : 0;
}
bool TString::operator >=(char *str)
{
	char *p1 = content, *p2 = str;
	if (p1 == NULL || p2 == NULL)
	{
		if (p1 == p2)
			return 1;
		return p1 == NULL ? 0 : 1;
	}
	while (*p1 != '\0'&&*p2 != '\0')
	{
		if (*p1 != *p2)
			return *p1 > *p2 ? 1 : 0;
		p1++;
		p2++;
	}
	if (*p1 == *p2)
		return 1;
	return *p1 == '/0' ? 0 : 1;
}
bool TString::operator <=(char *str)
{
	char *p1 = content, *p2 = str;
	if (p1 == NULL || p2 == NULL)
	{
		if (p1 == p2)
			return 1;
		return p1 == NULL ? 1 : 0;
	}
	while (*p1 != '\0'&&*p2 != '\0')
	{
		if (*p1 != *p2)
			return *p1 > *p2 ? 0 : 1;
		p1++;
		p2++;
	}
	if (*p1 == *p2)
		return 1;
	return *p1 == '/0' ? 1 : 0;
}
bool TString::operator ==(char *str)
{
	char *p1 = content, *p2 = str;
	if (p1 == NULL || p2 == NULL)
	{
		if (p1 == p2)
			return 1;
		else
			return 0;
	}
	while (*p1 != '\0'&&*p2 != '\0')
	{
		if (*p1 != *p2)
			return 0;
		p1++;
		p2++;
	}
	if (*p1 == *p2)
		return 1;
	else
		return 0;
}
bool TString::operator !=(char *str)
{
	char *p1 = content, *p2 = str;
	if (p1 == NULL || p2 == NULL)
	{
		if (p1 == p2)
			return 0;
		else
			return 1;
	}
	while (*p1 != '\0'&&*p2 != '\0')
	{
		if (*p1 != *p2)
			return 1;
		p1++;
		p2++;
	}
	if (*p1 == *p2)
		return 0;
	else
		return 1;
}
int TString::length()
{
	return len;
}

/* 如果有需要的其它全局函数的实现，可以写于此处 */
istream& operator >>(istream &in, TString &str)
{
	if (str.content)
	{
		delete str.content;
		str.content = NULL;
		str.len = 0;
	}
	while (1)
	{
		char ch;
		in.get(ch);
		if (ch == 10 || ch == 13 || ch == 32)
			break;
		char *temp;
		temp = new char[str.len + 1];
		if (str.content)
			strcpy(temp, str.content);
		str.len++;
		if (str.content)
			delete str.content;
		str.content = new char[str.len + 1];
		memcpy(str.content, temp, str.len);
		str.content[str.len - 1] = ch;
		str.content[str.len] = '\0';
		delete temp;
	}
	return in;
}
ostream& operator <<(ostream &out, TString &str)
{
	if (str.content)
		cout << str.content;
	else
		cout << "NULL";
	return out;
}
TString operator +(TString &str1, TString &str2)
{
	TString str;
	if (str1.len == 0 || str2.len == 0)
	{
		str = str1.content ? str1 : str2;
		return str;
	}
	str.content = new(nothrow) char[str1.len + str2.len + 1];
	strcpy(str.content, str1.content);
	memcpy(str.content + str1.len, str2.content, str2.len);
	str.content[str1.len + str2.len] = '\0';
	/*strcat(str.content, str2.content);*/
	str.len = str1.len + str2.len;
	return str;
}
TString operator +(const char *s, TString &str1)
{
	TString str;
	if (str1.len == 0 || !s || !(*s))
	{
		if ((str1.len == 0 && !s) || (str1.len == 0 && !(*s)))
			return str;
		else if (!s || !(*s))
			str = str1;
		else
		{
			str.content = new(nothrow) char[strlen(s) + 1];
			strcpy(str.content, s);
			str.len = strlen(s);
		}
		return str;
	}
	int len = strlen(s);
	str.content = new(nothrow) char[str1.len + len + 1];
	strcpy(str.content, s);
	memcpy(str.content + len, str1.content, str1.len);
	str.content[len + str1.len] = '\0';
	str.len = str1.len + len;
	return str;
}
TString operator +(TString &str1, const char *s)
{
	TString str;
	if (str1.len == 0 || !s || !(*s))
	{
		if ((str1.len == 0 && !s) || (str1.len == 0 && !(*s)))
			return str;
		else if (!s || !(*s))
			str = str1;
		else
		{
			str.content = new(nothrow) char[strlen(s) + 1];
			strcpy(str.content, s);
			str.len = strlen(s);
		}
		return str;
	}
	int len = strlen(s);
	str.content = new(nothrow) char[str1.len + len + 1];
	strcpy(str.content, str1.content);
	memcpy(str.content + str1.len, s, len);
	str.content[len + str1.len] = '\0';
	str.len = str1.len + len;
	return str;
}
int TStringLen(TString &str)
{
	return str.len;
}
TString operator +(TString &str1, int x)
{
	return str1;
}
TString operator +(int x, TString &str1)
{
	return str1;
}
