#include <iostream>
#include <fstream>
#include <time.h>
#include <iomanip>
using namespace std;
struct student
{
	long int num;
	char name[16];
	char schname[14];
	student *next;
};
int main()
{
	student *p = NULL, *q = NULL, *head = NULL;
	ifstream fin;
	int count, i, M, N, j;
	srand(unsigned int(time(0)));
	fin.open("stulist.txt", ios::in);
	if (fin.is_open() == 0)
	{
		cout << "can't open";
		return -1;
	}
	fin >> N >> M;
	for (i = 0; i < M; i++)
	{
		q = p;
		p = new(nothrow) student;
		if (i == 0)
			head = p;
		else
			q->next = p;
		fin >> p->num >> p->name >> p->schname;
		p->next = NULL;
	}
	fin.close();
	ofstream fout;
	fout.open("result.txt", ios::out);
	if (fout.is_open() == 0)
	{
		cout << "can't open";
		return -1;
	}
	int m = 1;
	for (i = 0; i < N; i++)
	{
		p = head;
		count = rand() % (M - i);

		if (count == 0)
		{
			head = p->next;
			delete p;
		}
		else
		{
			for (j = 0; j < count - 1; j++)
				p = p->next;
			q = p->next;
			fout << m++ << "." << setw(8) << q->num << setw(8) << q->name << setw(8) << q->schname << endl;
			p->next = q->next;
			delete q;
		}
	}
	fout.close();
	p = head;
	while (p)
	{
		q = p->next;
		delete p;
		p = q;
	}
	cout << "the rand student list has been done";
	return 0;
}