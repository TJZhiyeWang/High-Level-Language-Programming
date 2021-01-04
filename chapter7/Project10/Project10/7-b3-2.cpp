/*1553449 3∞‡ Õı÷æ“µ*/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
struct student
{
	int no;
	char name[9];
	int score;
	struct student *next;
};
int main()
{
	student *head = NULL, *p = NULL, *q = NULL;
	ifstream fin;
	fin.open("list.txt", ios::in);
	if (fin.is_open() == 0)
	{
		cout << "can't open";
		return -1;
	}
	while (1)
	{
		q = p;
		p = new(nothrow) student;
		if (p == NULL)
		{
			cout << "no memory";
			return -1;
		}
		if (head == NULL)
			head = p;
		else
			q->next = p;
		fin >> p->no >> p->name >> p->score;
		if (p->no == 9999999)
		{
			q->next = NULL;
			break;
		}
		p->next = NULL;
	}
	fin.close();
	p = head;
	while (p)
	{
		cout << setw(8) << p->no << setw(8) << p->name << setw(8) << p->score << endl;
		p = p->next;
	}
	p = head;
	while (p)
	{
		q = p->next;
		delete p;
		p = q;
	}
	return 0;

}