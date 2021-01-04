/*1553449 Õı÷æ“µ 3∞‡*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <io.h>
#include <experimental/filesystem>
using namespace std;
enum ITEM_TYPE
{
	TYPE_INT,TYPE_DOUBLE,TYPE_STRING,TYPE_CHARACTER,TYPE_NULL
};
int group_add(fstream &fp, const char *group_name)
{
    while (fp.peek()!=EOF)
	{
		char c = fp.get();
		
		if (c == '[')
		{
			char ch[99];
			fp.get(ch, 99, ']');
			fp.ignore();
			if (strcmp(ch, group_name) == 0)
				return 0;
		}
		
    }
	fp.clear();
	fp.seekg(0, ios::end);
	fp << "\r"<<"\n";
	fp.put('[');
	fp.write(group_name, strlen(group_name));
	fp.put(']');
	return 1;
	
}
int group_del(fstream &fp, const char *group_name)
{
	 long int len1, len2,flag=0,file_length;
	fp.seekg(0, ios::end);
	file_length = fp.tellp();
	fp.seekg(0, ios::beg);
	while (fp.peek() != EOF)
	{
		char c = fp.get();
		
		if (c == '[')
		{
			if (flag == 1)
			{
				len2= fp.tellg();
				flag =2;
			}
			char ch[99];
			fp.get(ch, 99, ']');
			fp.ignore();
			if (strcmp(ch, group_name) == 0)
			{
				len1= long int(fp.tellg())-2-strlen(group_name);
				flag = 1;
				
			}
		}

	}
	cout << len1 << endl<<len2<<endl<<file_length;
	fp.clear();
	if (flag > 0)
	{
		if (flag == 2)
		{
			char *p1, *p2;
			fp.seekg(0, ios::beg);
			p1 = new(nothrow) char[len1];
			p2 = new(nothrow) char[file_length - len2];
			fp.read(p1, len1);
			
			fp.seekg(len2-1, ios::beg);
			fp.read(p2, file_length - len2);
			cout << p2;
			fp.close();
			fp.open("UEdit32.ini", ios::out | ios::binary);
			if (fp.is_open() == 0)
				exit(-1);
			fp.write(p1, len1);
			fp.write(p2, file_length- len2);
		}
		if (flag == 1)
		{
			char *p1, *p2 = {0};
			fp.seekg(0, ios::beg);
			p1 = new(nothrow) char[len1];
			fp.read(p1, len1);
			fp.close();
			fp.open("UEdit32.ini", ios::out | ios::binary);
			if (fp.is_open() == 0)
				exit(-1);
			fp.write(p1, len1);
		}
		fp.close();
		fp.open("UEdit32.ini", ios::out|ios::in | ios::binary);
		return 1;
	}

	
	else
	return 0;
}
/*int item_add(fstream &fp, const char *group_name, const char *item_name, const void *item_value, const enum ITEM_TYPE item_type)
{

}*/
int item_del(fstream &fp, const char *group_name, const char *item_name)
{
	while (fp.peek() != EOF)
	{
		char c = fp.get();

		if (c == '[')
		{
			char ch[99];
			fp.get(ch, 99, ']');
			fp.ignore();
			if (strcmp(ch, group_name) == 0)
			{
				fp.seekg(2, ios::cur);
				while (fp.peek() != '[')
				{
					char ch1[99];
					fp.seekg(1, ios::cur);
					fp.getline(ch1, 99, '=');
					if (strcmp(ch1, item_name) == 0)
					{
						fp.seekg(-fp.gcount(), ios::cur);
						fp.getline(ch, 999);
						char *p;
						p = new(nothrow) char[fp.gcount()-2];
						for (int i = 0; i < fp.gcount()-2; i++)
						{
							p[i] = ' ';
						}
						fp.seekg(-fp.gcount(), ios::cur);
						fp.write(p, fp.gcount());
						return 1;
					}
					fp.ignore(999, 13);
				}
			}
				
		}

	}
	return 0;
}
/*int item_update(fstream &fp, const char *group_name, const char *item_name, const void *item_value, const enum ITEM_TYPE item_type)
{

}
int item_get_value(fstream &fp, const char *group_name, const char *item_name, void *item_value, const enum ITEM_TYPE item_type)
{

}*/
int main()
{
	fstream fp;
	fp.open("UEdit32.ini", ios::out|ios::in|ios::binary);
	if (fp.is_open() == 0)
		cout << "open failed";
	
	cout<<item_del(fp, "Print Settings","Paper");
	fp.close();
	return 0;
}