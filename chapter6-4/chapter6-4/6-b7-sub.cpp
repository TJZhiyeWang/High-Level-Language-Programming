/* 1553449 王志业 3班 */

#include <iostream>
using namespace std;

/* ----- 不允许定义任何形式的全局数组!!!!! ----- */

/* 函数实现部分，{ }内的东西可以任意调整，目前的return只是一个示例，可改变 */
int tj_strlen(const char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int lenth = 0;
	if (str == NULL)
		return 0;
	const char *p = str;
	while (*p != '\0')
	{
		lenth++;
		p++;
	}
    return lenth;
}

char *tj_strcat(char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (s1 == NULL || s2 == NULL)
		return s1;
	const char *p2 = s2;
	int len = tj_strlen(s1);
	char *p1 = s1 + len;
	while (*p2 != '\0')
	{
		*p1 = *p2;
		p1++;
		p2++;
	}
	*p1 = '\0';
    return s1;
}

char *tj_strcpy(char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (s1 == NULL)
		return s1;
	else if (s2 == NULL)
	{
		*s1 = '\0';
		return s1;
	}
	const char *p2 = s2;
	char *p1 = s1;

	while (*p2 != '\0')
	{
		*p1 = *p2;
		p1++;
		p2++;
	}
	*p1 = '\0';
    return s1;
}

char *tj_strncpy(char *s1, const char *s2, const int len)
{
	if (s1 == NULL || s2 == NULL)
		return s1;

	char *p1 = s1;
	const char *p2 = s2;
	while (*p2 != '\0')
	{
		*p1 = *p2;
		p1++;
		p2++;
		if (p2 - s2 == len)
			break;
	}
    return s1;
}

int tj_strcmp(const char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (s1 == NULL&&s2 == NULL)
		return 0;
	else if (s1 == NULL)
		return -1;
	else if (s2 == NULL)
		return 1;

	int r = 0;
	const char *p1 = s1;
	const char *p2 = s2;
	while (*p1 != '\0'&&*p2 != '\0')
	{
		r = *p1 - *p2;
		if (r != 0)
			break;
		else
		{
			p1++;
			p2++;
		}
	}
	if ((*p1 != '\0' || *p2 != '\0') && r == 0)
		r = *p1 - *p2;
	return r;
}

int tj_strcasecmp(const char *s1, const char *s2)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (s1 == NULL&&s2 == NULL)
		return 0;
	else if (s1 == NULL)
		return -1;
	else if (s2 == NULL)
		return 1;
	int r = 0;
	const char *p1 = s1;
	const char *p2 = s2;
	while (*p1 != '\0'&&*p2 != '\0')
	{
		int temp1 = *p1;
		int temp2 = *p2;
		if (*p1 >= 'a'&&*p1 <= 'z')
			temp1 -= 32;
		if (*p2 >= 'a'&&*p2 <= 'z')
			temp2 -= 32;

		r = temp1 - temp2;

		if (r != 0)
			break;
		else
		{
			p1++;
			p2++;
		}
	}
	if ((*p1 != '\0' || *p2 != '\0') && r == 0)
		r = *p1 - *p2;
	return r;
}

int tj_strncmp(const char *s1, const char *s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (s1 == NULL&&s2 == NULL)
		return 0;
	else if (s1 == NULL)
		return -1;
	else if (s2 == NULL)
		return 1;

	int r = 0;
	const char*p1 = s1;
	const char *p2 = s2;
	while (*p1 != '\0'&&*p2 != '\0')
	{
		r = *p1 - *p2;
		if (r != 0)
			break;
		else
		{
			{
				p1++;
				p2++;
			}
			if (len == (p1 - s1))
			{
				p1--;
				p2--;
				break;
			}
		}
	}
	if((*p1!='\0'||*p2!='\0')&&r==0)
		r = *p1 - *p2;
	return r;
}

int tj_strcasencmp(const char *s1, const char *s2, const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (s1 == NULL&&s2 == NULL)
		return 0;
	else if (s1 == NULL)
		return -1;
	else if (s2 == NULL)
		return 1;
	int r = 0;
	const char*p1 = s1;
	const char *p2 = s2;
	int temp1, temp2;
	while (*p1 != '\0'&&*p2 != '\0')
	{
		temp1 = *p1;
		temp2 = *p2;
		if (*p1 >= 'a'&&*p1 <= 'z')
			temp1 -= 32;
		if (*p2 >= 'a'&&*p2 <= 'z')
			temp2 -= 32;

		r = temp1 - temp2;
		if (r != 0)
			break;
		else
		{
			p1++;
			p2++;
			if (len == (p1 - s1))
			{
				p1--;
				p2--;
				break;
			}
		}
	}
	if ((*p1 != '\0' || *p2 != '\0') && r == 0)
	{
		temp1 = *p1;
		temp2 = *p2;
		if (*p1 >= 'a'&&*p1 <= 'z')
			temp1 -= 32;
		if (*p2 >= 'a'&&*p2 <= 'z')
			temp2 -= 32;
		if (temp1 == 0 || temp2 == 0)
			r = *p1 - *p2;
		else
			r = temp1 - temp2;
	}
	return r;
}

char *tj_strupr(char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (str == NULL)
		return str;
	char *p1 = str;
	while (*p1 != '\0')
	{
		if (*p1 >= 'a'&&*p1 <= 'z')
			*p1 = char(*p1 - 32);
		p1++;

	}
	return str;
}

char *tj_strlwr(char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (str == NULL)
		return str;
	char *p1 = str;
	while (*p1 != '\0')
	{
		if (*p1 >= 'A'&&*p1 <= 'Z')
			*p1 = char(*p1 + 32);
		p1++;

	}
    return str;
}

int tj_strchr(const char *str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (str == NULL)
		return 0;
	int r = 0;
	const char *p = str;
	while (*p != '\0')
	{
		if (*p == ch)
		{
			r = (p - str) + 1;
			break;
		}
		p++;
	}
	return r; //return值可根据需要修改
}

int tj_strstr(const char *str, const char *substr)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (str == NULL || substr == NULL)
		return 0;
	int r = 0;
	const char *p1 = str;
	const char *p2 = substr;
	int pos;
	int temp;
	while (*p1 != '\0'&&*p2 != '\0')
	{
		temp = (p1 - str);
		if (*p1 == *p2)
		{
			pos = p1 - str + 1;
			while (*p2 != '\0')
			{
				if (*p1 != *p2)
					break;
				else
				{
					p1++;
					p2++;
				}
			}
		}
		if (*p2 == '\0')
		{
			r = pos;
		}
		else
		{
			p1 = str + temp + 1;
			p2 = substr;
		}
	}
	return r;
}

int tj_strrchr(const char *str, const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (str == NULL)
		return 0;
	const char *p = str;
	int pos = 0;
	while (*p != '\0')
	{
		if (*p == ch)
		{
			pos = p - str + 1;
		}
		p++;
	}
	return pos;
}

int tj_strrstr(const char *str, const char *substr)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (str == NULL || substr == NULL)
		return 0;
	int r = 0;
	const char *p1 = str;
	const char *p2 = substr;
	int start = 0;
	int temp;
	while (*p1 != '\0')
	{
		if (*p1 == *substr)
		{
			temp = p1 - str;
			p2 = substr;
			while (*p2 != '\0'&&*p1 != '\0')
			{
				if (*p1 != *p2)
					break;
				else
				{
					p1++;
					p2++;
				}
			}

			if (*p2 == '\0')
				start = temp + 1;

			r = start;
			if (*p1 == '\0')
				break;
			else
				p1 = str + temp + 1;
		}
		else
			p1++;
	}
	return r;
}

char *tj_strrev(char *str)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	if (str == NULL)
		return str;
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int len = tj_strlen(str);
	char temp;
	char *p1;
	char *p2;
	if (*str != '\0')
	{
		for (p1 = str; (p1 - str) <= (len - 1) / 2; p1++)
		{
			int chg1 = p1 - str;
			p2 = str + len - 1 - chg1;
			temp = *p1;
			*p1 = *p2;
			*p2 = temp;
		}
	}
    return str;
}
