/*1553449 王志业 3班*/
#include <iostream>
#include <iomanip>
using namespace std;
int zeller(int year, int month = 1)
{
	int w, c, y, m, d, day = 1;
	if (month < 3)
	{
		year--;
		m = month + 12;
	}
	else
		m = month;
	d = day;
	c = year / 100;
	y = year - 100 * c;
	w = (y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1);
	while (w < 0)
		w += 7;
	w %= 7;
	return w;
}
bool is_leap_year(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400)
		return 1;
	else
		return 0;
}
int main()
{
	system("mode con cols=100 lines=40");
	int year;
	int day365[12][32] =
	{ { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 },
	{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28 },
	{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 },
	{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30 },
	{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 },
	{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30 },
	{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 },
	{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 },
	{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30 },
	{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 },
	{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30 },
	{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31 }
	};
	int top[12] = { 0 };
	int firstline[3] = { 1,1,1 };
	while (1)
	{
		cout << "请输入年份(1900-2100)：";
		cin >> year;
		if (!cin)
		{
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else if (year >= 1900 && year <= 2100)
			break;
	}
	if (is_leap_year(year))
		day365[1][28] = 29;
	int i, j, k;
	cout << year << "年的日历：" << endl << endl;
	int month_fir;
	for (k = 0; k <= 3; k++)
	{
		for (j = 1; j <= 3; j++)
		{
			cout << resetiosflags(ios::left) << setiosflags(ios::right) << setw(13) << j + 3 * k << "月" << setw(17) << ' ';
		}
		cout << endl;
		cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     " << endl;

		int complete[3] = { 0 };
		int mod7 = 0;
		for (j = 1; j <= 3; )
		{

			month_fir = zeller(year, 3 * k + j);
			if (firstline[j - 1])
			{
				for (i = 0; i < month_fir; i++)
					cout << setw(4) << ' ';
				firstline[j - 1] = 0;
				mod7 = month_fir;
			}
			if (complete[j - 1] == 0)
				cout << resetiosflags(ios::right) << setiosflags(ios::left) << setw(4) << day365[3 * k + j - 1][top[3 * k + j - 1]];
			else
				cout << resetiosflags(ios::right) << setiosflags(ios::left) << setw(4) << ' ';
			top[3 * k + j - 1]++;
			mod7++;
			if (day365[3 * k + j - 1][top[3 * k + j - 1]] == 0)
			{
				for (; mod7 < 7; mod7++)
					cout << setw(4) << ' ';
				complete[j - 1] = 1;
			}
			if (mod7 == 7)
			{
				cout << "    ";
				j++;
				mod7 = 0;
			}

			if (j == 4)
			{
				cout << endl;
				if (complete[0] + complete[1] + complete[2] == 3)
				{
					cout << endl;
					for (int i = 0; i < 3; i++)
						firstline[i] = 1;
					break;

				}
				else if (mod7 == 0)
				{
					j = 1;
				}
			}
		}
	}
	cout << endl;
	return 0;
}
