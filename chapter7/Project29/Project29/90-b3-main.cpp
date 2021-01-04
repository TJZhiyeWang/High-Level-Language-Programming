/*1553449 王志业 3班*/
#define _CRT_SECURE_NO_WARNINGS		
#include "90-b3.h"
#include "cmd_console_tools.h"
void menu()
{
	system("cls");
	cout << "***********************************\n"
		<< "1.圆盘钟、数字钟（按Tab键切换、Tab+ESC键退出）\n"
		<< "2.闹钟\n"
		<< "0.退出（将会自动保存已设定的闹钟）\n"
		<< "***********************************";
}
int main()
{


	while (1)
	{
		menu();
		switch (_getch())
		{
			case '1':
				while (1)
				{
					digit_clock();

					if (_kbhit() == 0)

					{
						if (_getch() == 27)
							break;

					}
					hand_clock();
					if (_kbhit() == 0)

					{
						if (_getch() == 27)
							break;

					}
				}
				continue;
			case '2':
				alarm_clock();
				continue;
			case '0':
				break;


		}

	}

	return 0;
}