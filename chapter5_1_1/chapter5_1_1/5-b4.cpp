/*王志业 1553449 3班*/
#include <iostream>
#include<time.h>
#include<iomanip>
using namespace std;
int main()
{
	int grade[1001];
	int rank = 1, rank_plus = 1, i = 0, n = 0, j;
	cout << "请输入成绩（最多1000个），以-1结束" << endl;
	while (cin >> grade[i])
	{
		if (grade[i] == -1)
			break;
		i++;
	}
	n = i;//表示个数
	cout << "输入的数组为：";
	for (int i = 0; i < n; i++)
	{
		if (i % 10 == 0)
			cout << endl;
		cout << setw(3) << setiosflags(ios::left) << grade[i];

	}

	for (i = 0; i < n; i++)
		for (j = n; j > i; j--)
		{
			if (grade[j] > grade[j - 1])
			{
				int temp = grade[j];
				grade[j] = grade[j - 1];
				grade[j - 1] = temp;
			}
		}
	cout << endl << "分数与名词的对应关系为：" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << grade[i] << " " << rank << endl;
		while (grade[i] == grade[i + 1])
		{
			cout << setw(3) << setiosflags(ios::left)<<grade[i] <<   rank << endl;
			i++;
			rank_plus++;
		}
		rank += rank_plus;
		rank_plus = 1;
	}
	return 0;
}