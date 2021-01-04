/*1553449 3班 王志业*/
#include <iostream>
using namespace std;
int main(int av, char *ag[])
{
	int count = 1, nc = 128, lc = 100, tc = 0, i;
	while (ag[count] != NULL)
		count++;
	count--;
	for (i = 1; i <= count; i++)
	{
		if (strcmp(ag[i], "-t") == 0)
			tc = 1;
		if (strcmp(ag[i], "-l") == 0)
		{
			if (i == count - 1)
			{
				cout << "-l缺少参数";
				return 0;
			}
			else
			{
				lc = atoi(ag[i + 1]);
				if (lc < 64 || lc>64000)
				{
					lc = 100;
				}
			}
		}
		if (strcmp(ag[i], "-n") == 0)
		{
			if (i == count - 1)
			{
				cout << "-n缺少参数";
				return 0;
			}
			else
			{
				nc = atoi(ag[i + 1]);
				if (nc < 1 || nc>10000)
				{
					nc = 128;
				}
			}
		}
		if (i == count)
		{
			int len, num = 0, m, dot = -1, n, j, address;
			len = strlen(ag[i]);
			for (m = 0; m < len; m++)
				if (ag[i][m] == '.')
					num++;
			if (num != 3)
			{
				cout << "IP地址错误";
				return 0;
			}
			else
			{
				num = 0;
				for (m = 0; m < len; m++)
				{
					if (ag[i][m] == '.'&&num < 3)
					{
						address = 0;
						num++;
						n = m - dot - 2;
						for (j = dot + 1; j < m; j++, n--)
						{
							address += int(ag[i][j] - '0')*int(pow(10, n));

						}
						dot = m;
						cout << address << ".";
						if (address > 255 || address < 0)
						{
							cout << "IP地址错误" << endl;
							return 0;
						}

					}
					else if (num == 3)
					{
						address = 0;
						n = len - dot - 2;
						for (j = dot + 1; j < len; j++, n--)
						{
							address += int(ag[i][j] - '0')* int(pow(10, n));

						}
						cout << address;
						if (address > 255 || address < 0)
						{
							cout << "IP地址错误";
							return 0;
						}
						break;
					}

				}
			}

			cout << "正确" << "l的值" << lc << "n的值" << nc << "t的值" << tc;

		}
	}
	return 0;

}