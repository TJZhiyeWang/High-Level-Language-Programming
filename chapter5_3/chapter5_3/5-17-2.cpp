/*1553449 王志业 3班*/
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include <stdio.h>
#define num 10
using namespace std;
int main()
{
	string name[num];
	int stunum[num];
	int grade[num];
	int i;
	for (i = 0; i<num; i++)
	{
		cout << "请输入第"<<i+1<<"个人的姓名、学号、成绩" << endl;
		cin >> name[i] >> stunum[i] >> grade[i];
	}
	cout << endl << "不及格名单：" << endl;
	for (int i = 0; i < num; i++)
	{
		if (grade[i] < 60)
			cout << name[i] <<" "<< stunum[i] <<" "<< grade[i];
	}
	return 0;
}