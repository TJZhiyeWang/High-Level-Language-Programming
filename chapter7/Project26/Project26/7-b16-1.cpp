/* 1553449 王志业 3班 */
#define _CRT_SECURE_NO_WARNINGS
#undef UNICODE 
#define MAX_RESULT 256
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#include <direct.h>
using namespace std;
struct student
{
	char number[8];
	char name[9];
	char class_name[6];
	char class_name1[10];
	student *next;
};
//判断两字符串部分重合,重合返回1，不重合返回0
int is_coinside(char *lstr, char *sstr)
{
	int i, j, slen, llen;
	slen = strlen(sstr);
	llen = strlen(lstr);
	for (i = 0; i < llen; i++)
	{
		if (lstr[i] == sstr[0])
		{
			for (j = 1; j < slen; j++)
			{
				if (lstr[i + j] != sstr[j])
					break;
			}
			if (j == slen)
				return 1;
		}

	}
	return 0;
}
char** sEnumFiles(int *count, char *pattern)
{
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;
	char result[MAX_RESULT][MAX_PATH];
	char **returnresult;

	int i = 0, j;

	// 开始查找

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
int main(int argc, char *argv[])
{

	if (argc < 4)
	{
		cout << "参数不足";
		exit(-1);
	}

	if (strcmp(argv[1], "-checktitle") == 0)
	{



		student *head = NULL, *p = NULL, *q = NULL;
		int count = 0, i, flag, j;
		char **result, namefile[66] = ".\\source\\", pattern[66] = ".\\source\\";
		strcat(namefile, argv[2]);
		strcat(namefile, ".dat");
		strcat(pattern, argv[2]);
		strcat(pattern, "*.*");
		result = sEnumFiles(&count, pattern);

		ifstream fin;
		fin.open(namefile, ios::in);
		if (fin.is_open() == 0)
		{
			cout << "open failed";
			return 0;
		}

		while (!fin.eof())
		{
			p = new(nothrow) student;
			if (p == NULL)
				cout << "no memory";

			if (head == NULL)
				head = p;

			else
				q->next = p;
			q = p;
			fin >> p->number >> p->name >> p->class_name >> p->class_name1;

		}
		fin.close();
		p->next = NULL;
		if (strcmp(argv[3], "all") != 0)
		{


			char test1[20], test2[20], test3[20];
			for (i = 0; i < count; i++)
			{
				char sourcefile[99] = ".\\source\\";
				if (strcmp(result[i], namefile) != 0)
				{
					strcat(sourcefile, result[i]);
					strcat(sourcefile, "\\");
					strcat(sourcefile, argv[3]);
					fin.open(sourcefile, ios::in | ios::binary);
					cout << endl << sourcefile << ":";
					if (fin.is_open() == 0)
					{
						cout << "未提交";
						continue;
					}
					flag = 0;

					while (1)
					{
						if (fin.peek() == 32 || fin.peek() == 9 || fin.peek() == 10 || fin.peek() == 13)
							fin.ignore();
						else
							break;

					}




					if (fin.get() == '/')
					{
						char ch = fin.get();
						if (ch == '*' || ch == '/')
						{
							while (1)
							{
								if (fin.peek() == 32 || fin.peek() == 9)
									fin.ignore();
								else if (fin.peek() == 10)
								{
									flag = 2;
									break;
								}
								else
									break;

							}
							for (j = 0; j < 98; j++)
							{
								if (fin.peek() == '*' || fin.peek() == 10)
								{
									flag = 2;
									break;
								}
								else if (fin.peek() == 32 || fin.peek() == 9)
								{
									fin.ignore();
									break;
								}
								else
								{
									test1[j] = fin.get();

								}
							}

							test1[j] = '\0';

							while (1)
							{
								if (fin.peek() == 32 || fin.peek() == 9)
									fin.ignore();
								else if (fin.peek() == 10)
								{
									flag = 2;
									break;
								}
								else
									break;

							}

							for (j = 0; j < 98; j++)
							{
								if (fin.peek() == '*' || fin.peek() == 10)
								{
									flag = 2;
									break;
								}
								else if (fin.peek() == 32 || fin.peek() == 9)
								{
									fin.ignore();
									break;
								}
								else
									test2[j] = fin.get();
							}
							test2[j] = '\0';

							while (1)
							{
								if (fin.peek() == 32 || fin.peek() == 9)
									fin.ignore();
								else if (fin.peek() == 10 || fin.peek() == '*')
								{
									flag = 2;
									break;
								}
								else
									break;

							}

							for (j = 0; j < 98; j++)
							{
								if (fin.peek() == '*' || fin.peek() == 10 || fin.peek() == 13)

									break;

								else if (fin.peek() == 32 || fin.peek() == 9)
								{
									fin.ignore();
									break;
								}
								else
									test3[j] = fin.get();

							}
							test3[j] = '\0';

						}
						else
							flag = 1;
					}
					else
						flag = 1;
					fin.close();

					if (flag == 1)
					{
						cout << "未取到首行信息";
						continue;
					}
					if (flag == 2)
					{
						cout << "首行信息不全";
						continue;
					}

					p = head;
					while (p)
					{
						if (is_coinside(result[i], p->number) == 1)
							break;
						p = p->next;
					}
					if (!(is_coinside(result[i], test1) || is_coinside(result[i], test2) || is_coinside(result[i], test3)))
					{
						cout << "学号不匹配";

						flag = 1;

					}
					if (strcmp(p->name, test1) != 0 && strcmp(p->name, test2) != 0 && strcmp(p->name, test3) != 0)
					{
						cout << "姓名不匹配";
						flag = 1;

					}
					if (!((is_coinside(test1, p->class_name) || is_coinside(test1, p->class_name1)) || (is_coinside(test2, p->class_name) || is_coinside(test2, p->class_name1)) || (is_coinside(test3, p->class_name) || is_coinside(test3, p->class_name1))))
					{
						cout << "班级不匹配";
						flag = 1;

					}
					if (flag == 0)
						cout << "检验通过";

				}
			}
		}
		else if (strcmp(argv[3], "all") == 0)
		{
			int file_count = 0, m;
			char **file_result;


			file_result = sEnumFiles(&file_count, pattern);

			for (m = 0; m < file_count; m++)
			{
				char sourcefile1[99] = ".\\source\\";
				strcat(sourcefile1, file_result[m]);
				strcat(sourcefile1, "\\*.cpp");
				result = sEnumFiles(&count, sourcefile1);



				char test1[99], test2[99], test3[99];
				for (i = 0; i < count; i++)
				{
					char sourcefile[99] = ".\\source\\";
					if (strcmp(file_result[m], namefile) != 0)
					{
						strcat(sourcefile, file_result[m]);
						strcat(sourcefile, "\\");
						strcat(sourcefile, result[i]);


						fin.open(sourcefile, ios::in | ios::binary);
						cout << endl << sourcefile << ":";
						if (fin.is_open() == 0)
						{
							cout << "未提交";
							continue;
						}
						flag = 0;

						while (1)
						{
							if (fin.peek() == 32 || fin.peek() == 9 || fin.peek() == 10 || fin.peek() == 13)
								fin.ignore();
							else
								break;

						}




						if (fin.get() == '/')
						{
							char ch = fin.get();
							if (ch == '*' || ch == '/')
							{
								while (1)
								{
									if (fin.peek() == 32 || fin.peek() == 9)
										fin.ignore();
									else if (fin.peek() == 10)
									{
										flag = 2;
										break;
									}
									else
										break;

								}
								for (j = 0; j < 98; j++)
								{
									if (fin.peek() == '*' || fin.peek() == 10)
									{
										flag = 2;
										break;
									}
									else if (fin.peek() == 32 || fin.peek() == 9)
									{
										fin.ignore();
										break;
									}
									else
									{
										test1[j] = fin.get();

									}
								}

								test1[j] = '\0';

								while (1)
								{
									if (fin.peek() == 32 || fin.peek() == 9)
										fin.ignore();
									else if (fin.peek() == 10)
									{
										flag = 2;
										break;
									}
									else
										break;

								}

								for (j = 0; j < 98; j++)
								{
									if (fin.peek() == '*' || fin.peek() == 10)
									{
										flag = 2;
										break;
									}
									else if (fin.peek() == 32 || fin.peek() == 9)
									{
										fin.ignore();
										break;
									}
									else
										test2[j] = fin.get();
								}
								test2[j] = '\0';

								while (1)
								{
									if (fin.peek() == 32 || fin.peek() == 9)
										fin.ignore();
									else if (fin.peek() == 10 || fin.peek() == '*')
									{
										flag = 2;
										break;
									}
									else
										break;

								}

								for (j = 0; j < 98; j++)
								{
									if (fin.peek() == '*' || fin.peek() == 10 || fin.peek() == 13)

										break;

									else if (fin.peek() == 32 || fin.peek() == 9)
									{
										fin.ignore();
										break;
									}
									else
										test3[j] = fin.get();

								}
								test3[j] = '\0';

							}
							else
								flag = 1;
						}
						else
							flag = 1;
						fin.close();

						if (flag == 1)
						{
							cout << "未取到首行信息";
							continue;
						}
						if (flag == 2)
						{
							cout << "首行信息不全";
							continue;
						}

						p = head;
						while (p)
						{
							if (is_coinside(file_result[m], p->number) == 1)
								break;
							p = p->next;
						}
						if (!(is_coinside(file_result[m], test1) || is_coinside(file_result[m], test2) || is_coinside(file_result[m], test3)))
						{
							cout << "学号不匹配";

							flag = 1;

						}
						if (strcmp(p->name, test1) != 0 && strcmp(p->name, test2) != 0 && strcmp(p->name, test3) != 0)
						{
							cout << "姓名不匹配";
							flag = 1;

						}
						if (!((is_coinside(test1, p->class_name) || is_coinside(test1, p->class_name1)) || (is_coinside(test2, p->class_name) || is_coinside(test2, p->class_name1)) || (is_coinside(test3, p->class_name) || is_coinside(test3, p->class_name1))))
						{
							cout << "班级不匹配";
							flag = 1;

						}
						if (flag == 0)
							cout << "检验通过";

					}

				}








			}
		}
		p = head;
		while (p)
		{
			q = p->next;
			delete p;
			p = q;
		}
	}
	if (strcmp(argv[1], "-replace") == 0)
	{
		char replace_file[66] = ".//source//", pattern[66] = ".//source//", **result;
		int count = 0, i;
		ifstream fin;
		fstream f_dis;
		strcat(replace_file, argv[4]);
		strcat(pattern, argv[2]);
		strcat(pattern, "*.*");
		result = sEnumFiles(&count, pattern);
		for (i = 0; i < count; i++)
		{
			char aim_file[99] = ".//source//";
			strcat(aim_file, result[i]);
			strcat(aim_file, "//");
			strcat(aim_file, argv[3]);
			if (is_coinside(aim_file, ".dat") == 0)
			{
				cout << endl << aim_file << ":";
				fin.open(replace_file, ios::in | ios::binary);
				if (fin.is_open() == 0)
				{
					cout << "替换文件不存在";
					exit(-1);
				}
				fin.seekg(0, ios::end);
				int len1 = int(fin.tellg());

				char* str = new(nothrow) char[len1];
				if (str == NULL)
				{
					cout << "no memory";
					continue;
				}
				fin.seekg(0, ios::beg);
				fin.read(str, len1);
				fin.close();
				f_dis.open(aim_file, ios::in | ios::binary);
				if (f_dis.is_open() == 0)
				{
					cout << "未提交";
					continue;
				}
				char test[] = "main";
				int len2;
				while (1)
				{
					char ch[99];
					f_dis.getline(ch, 99);
					if (is_coinside(ch, test) == 1)
					{
						len2 = int(f_dis.tellg() - f_dis.gcount());
						break;
					}
				}
				char* dle_str = new(nothrow) char[len2];
				if (dle_str == NULL)
				{
					cout << "no memory";
					continue;
				}
				f_dis.seekg(0, ios::beg);
				f_dis.read(dle_str, len2);

				f_dis.close();
				f_dis.open(aim_file, ios::out);
				if (f_dis.is_open() == 0)
				{

					continue;
				}
				f_dis.write(dle_str, len2);
				f_dis.write(str, len1);
				f_dis.close();
				cout << "已成功替换";
				delete dle_str;
				delete str;

			}
		}

	}
	return 0;
}
//记得删除链表
