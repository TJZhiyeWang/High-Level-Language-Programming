/*1553449 3∞‡ Õı÷æ“µ*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
struct student
{
	int *no;
	char *name;
	int *score;
	struct student *next;
};
int main()
{
	student *p = NULL, *q = NULL, *head = NULL;
	ifstream fin;
	int len;
	fin.open("list.txt", ios::in);
	if (fin.is_open() == 0)
	{
		cout << "can't open";
		return -1;
	}
	while (1)
	{
		char nm[9] = { "\0\0\0\0\0\0\0\0" };
		q = p;
		p = new(nothrow) student;
		if (p == NULL)
			return -1;
		p->no = new(nothrow) int;
		if (p->no == NULL)
			return -1;
		p->score = new(nothrow) int;
		if (p->score == NULL)
			return -1;
		if (head == NULL)
			head = p;
		else
			q->next = p;
		fin >> *p->no >> nm >> *p->score;
		p->name = new(nothrow) char[strlen(nm) + 1];
		if (p->name == NULL)
			return -1;
		strcpy(p->name, nm);
		if (*p->no == 9999999)
		{
			q->next = NULL;
			break;
		}
		p->next = NULL;
	}
	p = head;
	while (p)
	{
		cout << setw(8) << *p->no << setw(8) << p->name << setw(8) << *p->score << endl;
		p = p->next;
	}
	p = head;
	while (p)
	{
		q = p->next;
		delete p->no;
		delete p->score;
		delete p->name;
		delete p;
		p = q;
	}
	return 0;
}