/*1553449 3∞‡ Õı÷æ“µ*/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
struct student
{
	int num;
	char name[9];
	int score;
	int rank;
};
int main()
{
	student *p = NULL, *head = NULL, temp;
	int count, i, j;
	ifstream fin;
	fin.open("student.txt", ios::in);
	if (fin.is_open() == 0)
	{
		cout << "can't open" << endl;
		return -1;
	}
	fin >> count;
	p = new(nothrow) student[count];
	if (p == NULL)
	{
		cout << "no memory" << endl;
		return -1;
	}
	head = p;
	for (i = 0; i < count; i++)
	{
		fin >> p->num >> p->name >> p->score;
		p++;
	}
	p = head;
	for (i = 0; i < count; i++)
	{
		for (j = count - 1; j > i; j--)
		{
			if (p[j].score>p[j - 1].score)
			{
				temp = p[j];
				p[j] = p[j - 1];
				p[j - 1] = temp;
			}
		}
	}
	for (i = 0; i < count; i++)
	{
		p[i].rank = i + 1;
		for (j = 0; j < i; j++)
		{
			if (p[i].score == p[j].score)
				p[i].rank = p[j].rank;
		}
	}
	p = head;
	for (i = 0; i < count; i++)
	{
		for (j = 0; j < count - i - 1; j++)
		{
			if (p[j].num>p[j + 1].num)
			{
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < count; i++)
	{
		cout << setw(8) << p[i].num << setw(8) << p[i].name << setw(8) << p[i].score << setw(4) << p[i].rank << endl;

	}
	fin.close();
	delete head;
	return 0;
}