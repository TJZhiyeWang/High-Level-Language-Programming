/*3班 王志业 1553449*/
#include "90-b4.h"
//将编码转换成UTF8模式
void GBKToUTF8(const char* strGBK, char* utf8)
{
	int len = MultiByteToWideChar(CP_ACP, 0, strGBK, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len + 1];
	memset(wstr, 0, len + 1);
	MultiByteToWideChar(CP_ACP, 0, strGBK, -1, wstr, len);
	len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* str = new char[len + 1];
	memset(str, 0, len + 1);
	WideCharToMultiByte(CP_UTF8, 0, wstr, -1, str, len, NULL, NULL);
	strcpy(utf8, str);
	if (wstr) delete[] wstr;
	if (str) delete[] str;
}