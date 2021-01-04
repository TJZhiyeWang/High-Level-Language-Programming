/*王志业 1553449 3班*/
#include <iostream>
#include<iomanip>
#include<cstdio>
#define max_length 80
using namespace std;
int main()
{
	int Caps = 0, lower = 0, number = 0, space = 0, other = 0, i, j=0;
	char text[3][max_length];

	cout << "请输入第1行" << endl;
	gets_s(text[0], max_length - 1);
	cout << "请输入第2行" << endl;
	gets_s(text[1], max_length - 1);
	cout << "请输入第3行" << endl;
	gets_s(text[2], max_length - 1);
	for (i = 0; i < 3; i++)
	{
		j = 0;
		while (text[i][j] != '\0')
		{
			if (text[i][j] >= 'A'&&text[i][j] <= 'Z')
				Caps++;
			else if (text[i][j] >= 'a'&&text[i][j] <= 'z')
				lower++;
			else if (text[i][j] >= '0'&&text[i][j] <= '9')
				number++;
			else if (text[i][j] == ' ')
				space++;
			else
				other++;
			j++;
		}
	}
	cout << "大写:" << Caps << endl << "小写：" << lower << endl << "数字：" << number << endl << "空格：" << space << endl << "其他：" << other << endl;
	return 0;
}