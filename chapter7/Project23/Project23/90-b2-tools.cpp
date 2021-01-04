/*1553449 3班 王志业*/
#define _CRT_SECURE_NO_WARNINGS
#include "90-b2.h"
#include "cmd_console_tools.h"
//参数：输出位置，读取的文件名称。读取一个文件
void read_file(sdk sdkarray[][9], char *s)
{
	ifstream fin;
	int i, j;
	fin.open(s, ios::in | ios::binary);
	if (fin.is_open() == 0)
	{
		cout << "open failed";
		exit(-1);
	}
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			fin >> sdkarray[i][j].num;
			sdkarray[i][j].x = i;
			sdkarray[i][j].y = j;
			if (sdkarray[i][j].num < 0 || sdkarray[i][j].num>9 || fin.fail() == 1)
			{
				cout << "文件内容不合法";
				fin.close();
				exit(-1);
			}
			if (sdkarray[i][j].num>0)
				sdkarray[i][j].p = '1';
		}

	}
	fin.close();
}
//获取当前文件下所有sudoku开头文件的名称信息并返回二维字符串指针
char** EnumFiles(int *count)
{
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;
	char result[MAX_RESULT][MAX_PATH];
	char **returnresult;
	char pattern[MAX_PATH];
	int i = 0, j;

	// 开始查找
	_getcwd(pattern, MAX_RESULT);

	strcat(pattern, "\\sudoku*.*");
	hFind = FindFirstFile(pattern, &FindFileData);

	if (hFind == INVALID_HANDLE_VALUE)
	{
		*count = 0;
		return NULL;
	}
	else
	{
		do
		{
			strcpy(result[i++], FindFileData.cFileName);
		} while (FindNextFile(hFind, &FindFileData) != 0);
	}

	// 查找结束
	FindClose(hFind);

	// 复制到结果中
	returnresult = (char **)calloc(i, sizeof(char *));

	for (j = 0; j < i; j++)
	{
		returnresult[j] = (char *)calloc(MAX_PATH, sizeof(char));
		strcpy(returnresult[j], result[j]);
	}

	*count = i;
	return returnresult;
}
//解析输入的数据，返回行，列及数字，改变该位置上的值
void plot(sdk sdkarray[][9], char *s, int *row, int *line, int *num)
{

	*row = s[0] - '1';
	*line = s[1] - 'a';
	*num = s[2] - '0';
	if (*row < 0 || *row>8 || *line < 0 || *line>8 || *num < 1 || *num>9)
	{
		cout << "输入有误,按回车返回" << endl;
		while (_getch() != 13);
		return;
	}
	else if (sdkarray[*row][*line].p == '1')
	{
		cout << "该位置数字不可更改,回车返回" << endl;
		while (_getch() != 13);
		return;
	}
	else
		sdkarray[*row][*line].num = *num;
}