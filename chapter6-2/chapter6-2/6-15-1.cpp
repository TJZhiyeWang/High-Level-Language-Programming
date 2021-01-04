/* 1553449 王志业 3班 */
#include <iostream>
#include <iomanip>
using namespace std;

/* 求第一门课的平均分 */
void average(int(*a)[5])
{
	double sum = 0;
	for (int i = 0; i < 4; i++)
		sum = sum + **a++;
	cout << "第一门课平均分：";
	cout << sum / 4 << endl;
}

/* 找出有两门以上课程不及格的学生 */
void fail(int(*a)[5])
{
	int num = 0;
	int i, j;
	cout << "两门以上不及格的学生：" << endl;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (*(*(a + i) + j) < 60)
				num++;
		}
		if (num >= 2)
		{
			double sum = 0;
			cout << "No：" << i + 1 << "  ";
			for (j = 0; j < 5; j++)
			{
				cout << *(*(a + i) + j) << " ";
				sum += *(*(a + i) + j);
			}
			cout << "平均：" << sum / 5.0 << endl;
		}
		num = 0;
	}
}

/* 找出平均成绩在90分以上或全部成绩在85分以上的学生 */
void good(int(*a)[5])
{
	int num = 0;
	int sum = 0;
	int i, j, k;
	cout << "平均90以上或全部85以上的学生：" << endl;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 5; j++)
		{
			sum += *(*(a + i) + j);
			if (*(*(a + i) + j) >= 85)
				num++;
		}
		if (num == 5 || sum / 5.0 >= 90)
		{
			cout << "No：" << i + 1 << "  ";
			for (k = 0; k < 5; k++)
				cout << *(*(a + i) + k) << " ";
			cout << "平均：" << sum / 5.0 << endl;
		}
		num = 0;
		sum = 0;
	}
	cout << endl;
}
void print(int(*a)[5])
{
	int i, j;
	cout << "初始信息：" << endl;
	for (i = 0; i < 4; i++)
	{
		cout << "No." << i + 1 << "的1-5门课成绩：";
		for (j = 0; j < 5; j++)
		{
			cout << *(*(a + i) + j) << " ";
		}
		cout << endl;
	}
	cout << endl;
}
int main()
{
	int a[4][5] = { {91, 81, 71, 61, 51},	//第1个学生的1-5门课的成绩
					{92, 82, 72, 32, 52},   //第2个学生的1-5门课的成绩
					{93, 83, 99, 80, 95},   //第3个学生的1-5门课的成绩
					{97, 85, 87, 91, 88} }; //第4个学生的1-5门课的成绩
	print(a);
	average(a);
	cout << endl;
	fail(a);
	cout << endl;
	good(a);
	return 0;
}
