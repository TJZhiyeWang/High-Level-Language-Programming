/*1553449 3班 王志业*/
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
#define N 3
#define _CRT_SECURE_NO_WARNINGS
struct student
{
	int no;
	char name[9];
	float score[3];
};
void input(student stu[])
{
	int i = 0;
	char str[9];
	for (i = 0; i < N; i++)
	{
		cin >> stu[i].no;
		cin >> str;
		int len = strlen(str);
		str[len] = '\0';
		strcpy_s(stu[i].name, str);
		cin >> stu[i].score[0] >> stu[i].score[1] >> stu[i].score[2];
	}
}
void average(student stu[])
{
	double ave[N];
	int i;
	for (i = 0; i < N; i++)
	{
		ave[i] = (stu[i].score[0] + stu[i].score[1] + stu[i].score[2]) / 3;
		cout << ave[i] << '\t';
	}
}
void student_max(student stu[])
{
	string sname[N];
	int count = 0, i, max = 0;
	for (i = 0; i < N - 1; i++)
	{
		if (stu[max].score[0] + stu[max].score[1] + stu[max].score[2] < stu[i + 1].score[0] + stu[i + 1].score[1] + stu[i + 1].score[2])
			max = i + 1;
	}
	for (i = 0; i < N; i++)
	{
		if (stu[i].score[0] + stu[i].score[1] + stu[i].score[2] == stu[max].score[0] + stu[max].score[1] + stu[max].score[2])
		{
			sname[count] = stu[i].name;
			count++;
		}
	}
	cout << endl << "最高分数学生是";
	for (i = 0; i < count; i++)
	{
		cout << sname[i] << '\t';
	}
}
int main()
{
	student stu[10];
	input(stu);
	average(stu);
	student_max(stu);
	return 0;

}