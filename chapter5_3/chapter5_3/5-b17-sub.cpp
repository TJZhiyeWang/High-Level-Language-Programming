/* 3班 1553449 王志业 */

/* 函数实现部分，{ }内的东西可以任意调整，目前的return 0只是一个示例，可改变 */

int tj_strlen(const char str[])
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int lenth = 0;
	int i = 0;
	while (str[i] != '\0')
	{
		lenth++;
		i++;
	}
	return lenth; //return值可根据需要修改
}

int tj_strcat(char s1[], const char s2[])
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int i = 0;
	int lenth = tj_strlen(s1);
	while (s2[i] != '\0')
	{
		s1[lenth] = s2[i];
		lenth++;
		i++;
	}
	s1[lenth] = '\0';

	return 0; //return值可根据需要修改
}

int tj_strcpy(char s1[], const char s2[])
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */

	int i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return 0; //return值可根据需要修改
}

int tj_strncpy(char s1[], const char s2[], const int len)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
		if (i == len)
			break;
	}

	return 0; //return值可根据需要修改
}

int tj_strcmp(const char s1[], const char s2[])
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */

	int flag = 0;
	int i = 0;
	while (s1[i] != '\0'&&s2[i] != '\0')
	{
		flag = s1[i] - s2[i];
		if (flag != 0)
			break;
		else
			i++;
	}
	/*if (flag != 0)
		;
	else if (s1[i] == '\0'&&s2[i] == '\0')
		;
	else*/
	if(flag==0&& (s1[i] != '\0'||s2[i] != '\0'))
		flag = s1[i] - s2[i];

	return flag; //return值可根据需要修改
}

int tj_strcasecmp(const char s1[], const char s2[])
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */

	int flag = 0;
	int i = 0;
	while (s1[i] != '\0'&&s2[i] != '\0')
	{
		int temp1 = s1[i];
		int temp2 = s2[i];
		if (s1[i] >= 'a'&&s1[i] <= 'z')
			temp1 -= 32;
		if (s2[i] >= 'a'&&s2[i] <= 'z')
			temp2 -= 32;

		flag = temp1 - temp2;

		if (flag != 0)
			break;
		else
			i++;
	}
	if (flag != 0)
		;
	else if (s1[i] == '\0'&&s2[i] == '\0')
		;
	else
		flag = s1[i] - s2[i];
	return flag; //return值可根据需要修改
}

int tj_strncmp(const char s1[], const char s2[], const int len)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int flag = 0;
	int i = 0;
	while (s1[i] != '\0'&&s2[i] != '\0')
	{
		flag = s1[i] - s2[i];
		if (flag != 0)
			break;
		else
		{
			i++;
			if (len == i)
			{
				i--;
				break;
			}
		}
	}
	if (flag != 0)
		;
	else if (s1[i] == '\0'&&s2[i] == '\0')
		;
	else
		flag = s1[i] - s2[i];
	return flag; //return值可根据需要修改
}

int tj_strcasencmp(const char s1[], const char s2[], const int len)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int flag = 0;
	int i = 0;
	int temp1, temp2;
	while (s1[i] != '\0'&&s2[i] != '\0')
	{
		temp1 = s1[i];
		temp2 = s2[i];
		if (s1[i] >= 'a'&&s1[i] <= 'z')
			temp1 -= 32;
		if (s2[i] >= 'a'&&s2[i] <= 'z')
			temp2 -= 32;

		flag = temp1 - temp2;
		if (flag != 0)
			break;
		else
		{
			i++;
			if (len == i)
			{
				i--;
				break;
			}
		}
	}
	if (flag != 0)
		;
	else if (s1[i] == '\0'&&s2[i] == '\0')  
		;
	else   
	{
		temp1 = s1[i];
		temp2 = s2[i];
		if (s1[i] >= 'a'&&s1[i] <= 'z')
			temp1 -= 32;
		if (s2[i] >= 'a'&&s2[i] <= 'z')
			temp2 -= 32;
		if (temp1 == 0 || temp2 == 0)
			flag = s1[i] - s2[i];
		else
			flag = temp1 - temp2;
	}


	return flag; //return值可根据需要修改
}

int tj_strupr(char str[])
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a'&&str[i] <= 'z')
			str[i] = char(str[i] - 32);
		i++;

	}
	return 0; //return值可根据需要修改
}

int tj_strlwr(char str[])
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A'&&str[i] <= 'Z')
			str[i] = char(str[i] + 32);
		i++;

	}
	return 0; //return值可根据需要修改
}

int tj_strchr(const char str[], char ch)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int flag = 0;
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ch)
		{
			flag = i + 1;
			break;
		}
		i++;
	}

	return flag; //return值可根据需要修改
}

int tj_strstr(const char str[], const char substr[])
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int flag = 0;
	int i = 0;
	int j = 0;
	int start;
	int temp;
	while (str[i] != '\0'&&substr[j] != '\0')
	{
		temp = i;
		if (str[i] == substr[j])
		{
			start = i + 1;
			while (substr[j] != '\0')
			{
				if (str[i] != substr[j])
					break;
				else
				{
					i++;
					j++;
				}
			}
		}


		if (substr[j] == '\0')
		{
			flag = start;
		}
		else
		{
			i = temp + 1;
			j = 0;
		}
	}

	return flag; //return值可根据需要修改
}

int tj_strrchr(const char str[], const char ch)
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int i = 0;
	int pos = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ch)
		{
			pos = i + 1;
		}
		i++;
	}



	return pos; //return值可根据需要修改
}

int tj_strrstr(const char str[], const char substr[])
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int flag = 0;
	int i = 0;
	int j;
	int start = 0;
	int temp;
	while (str[i] != '\0')
	{
		if (str[i] == substr[0])
		{
			temp = i;
			j = 0;
			while (substr[j] != '\0'&&str[i] != '\0')
			{
				if (str[i] != substr[j])
					break;
				else
				{
					i++;
					j++;
				}
			}

			if (substr[j] == '\0')
				start = temp + 1;

			flag = start;
			if (str[i] == '\0')
				break;
			else
				i = temp + 1;
		}
		else
			i++;
	}
	return flag; //return值可根据需要修改

}

int tj_strrev(char str[])
{
	/* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
	int len = tj_strlen(str);
	char temp;
	int pos1, pos2;
	if (str[0] != '\0')
	{
		for (pos1 = 0; pos1 <= (len - 1) / 2; pos1++)
		{
			pos2 = len - 1 - pos1;  //
			temp = str[pos1];
			str[pos1] = str[pos2];
			str[pos2] = temp;
		}
	}
	return 0; //return值可根据需要修改
}