/* 1553449 3班 王志业 */
#include <iostream>
#include <iomanip>
using namespace std;

/* 求第一门课的平均分 */
void average(int(*a)[4])
{
	int i;
	double sum = 0;
	for (i = 0; i < 4; i++)
		sum = sum + *(*a + i);

	cout << "第一门课平均分：";
	cout << sum / 4 << endl;
}

/* 找出有两门以上课程不及格的学生 */
void fail(int(*a)[4])
{
	int num = 0;
	int i, j;
	cout << "两门以上不及格的学生：" << endl;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (*(*(a + j) + i) < 60)
				num++;
		}
		if (num >= 2)
		{
			double sum = 0;
			cout << "No：" << i + 1 << "  ";
			for (j = 0; j < 5; j++)
			{
				cout << *(*(a + j) + i) << " ";
				sum += *(*(a + j) + i);
			}
			cout << "平均：" << sum / 5.0 << endl;
		}
		num = 0;
	}
}

/* 找出平均成绩在90分以上或全部成绩在85分以上的学生 */
void good(int(*a)[4])
{
	int num = 0;
	int sum = 0;
	int i, j, k;
	cout << "平均90以上或全部85以上的学生：" << endl;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 5; j++)
		{
			sum += *(*(a + j) + i);
			if (*(*(a + j) + i) >= 85)
				num++;
		}
		if (num == 5 || sum / 5.0 >= 90)
		{
			cout << "No：" << i + 1 << "  ";
			for (k = 0; k < 5; k++)
				cout << *(*(a + k) + i) << " ";
			cout << "平均：" << sum / 5.0 << endl;
		}
		num = 0;
		sum = 0;
	}
	cout << endl;
}
void print(int(*a)[4])
{
	int i, j;
	cout << "初始信息：" << endl;
	for (i = 0; i < 5; i++)
	{
		cout << "No.1-4学生的第" << i + 1 << "门课的成绩：";
		for (j = 0; j < 4; j++)
		{
			cout << *(*(a + i) + j) << " ";
		}
		cout << endl;
	}
	cout << endl;
}
int main()
{
	int a[5][4] = { {91,92,93,97},  //第1-4个学生的第1门课成绩
					{81,82,83,85},  //第1-4个学生的第2门课成绩
					{71,72,99,87},  //第1-4个学生的第3门课成绩
					{61,32,80,91},  //第1-4个学生的第4门课成绩
					{51,52,95,88} };//第1-4个学生的第5门课成绩

	print(a);
	average(a);
	cout << endl;
	fail(a);
	cout << endl;
	good(a);
	return 0;
}


