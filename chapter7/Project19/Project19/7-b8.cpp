/*1553449 3班 王志业*/
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
int main()
{
	const char *name[] = { "zhang","li","wang","qian","sun","zhou","wu","zheng",NULL };
	short room[] = { 0x0092,0x0092,0x0092,0x0082,0x0000 };
	int N = 0, M = 0, i, max = 0, count = 0, j, na = 0, flag = 0, num;
	char choice;
	while (name[N] != NULL)
		N++;
	while (room[count] != 0)
	{
		for (i = 0; i < 16; i++)
		{
			if ((room[count] & (0x0001 << i))>0)
			{
				M++;
				if (i > max)
					max = i;
			}
		}
		count++;
	}
	cout << count << N << M;
	if (N > M)
	{
		cout << "无法分配座位";
		return 0;
	}
	cout << "请选择排列方式，1代表先行后列顺序分配，2代表随机位置分配";
	cin >> choice;
	switch (choice)
	{
		case '1':
		{
			for (i = 0; i < count; i++)
			{
				cout << "|    /   ";
				for (j = max; j >= 0; j--)
				{
					if ((room[i] & (0x0001 << j))>0 && flag == 0)
					{
						cout << "|" << setw(8) << name[na];
						na++;
						if (na == N)

							flag = 1;
					}
					else
						cout << "|    /   ";
				}
				cout << "|" << endl;
			}
		};
		break;
		case '2':
		{
			na = N;
			num = M;
			srand((unsigned int)time(0));
			for (i = 0; i < count; i++)
			{
				cout << "|    /   ";
				for (j = max; j >= 0; j--)
				{
					if ((room[i] & (0x0001 << j))>0 && na > 0)
					{

						if ((rand() % num + 1) <= na)
						{
							cout << "|" << setw(8) << name[na - 1];
							na--;
						}
						else
							cout << "|    /   ";
						num--;

					}
					else
						cout << "|    /   ";
				}
				cout << "|" << endl;
			}

		}
		break;

	}

	return(0);


}