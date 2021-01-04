/* 1553449 王志业 3班 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

/* 补全TString类的定义，所有成员函数均体外实现，不要在此处体内实现 */
class TString {
private:
	char *content;
	int   len;
	/* 根据需要定义所需的成员函数、友元函数等 */
public:
	TString();
	~TString();
	TString(char *s);
	TString(TString&);
	TString& operator =(const char *s);
	TString& operator =(TString& str);
	friend istream& operator >>(istream &in, TString &str);
	friend ostream& operator <<(ostream &out, TString &str);
	friend TString operator +(TString &str1, TString &str2);
	friend TString operator +(const char *s, TString &str1);
	friend TString operator +(TString &str1, const char *s);
	friend TString operator +(TString &str1, int);
	friend TString operator +(int, TString &str1);
	operator char*();
	bool operator >(char *str);
	bool operator <(char *str);
	bool operator >=(char *str);
	bool operator <=(char *str);
	bool operator ==(char *str);
	bool operator !=(char *str);
	int length();
	friend int TStringLen(TString &);

};

/* 如果有其它全局函数需要声明，写于此处 */
istream& operator >>(istream &in, TString &str);
ostream& operator <<(ostream &out, TString &str);
TString operator +(TString &str1, TString &str2);
TString operator +(const char *s, TString &str1);
TString operator +(TString &str1, const char *s);
int TStringLen(TString &);
TString operator +(TString &str1, int);
TString operator +(int, TString &str1);
/* 如果有需要的宏定义、只读全局变量等，写于此处 */
