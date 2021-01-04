/*王志业 1553449 3班*/
#include <iostream>
using namespace std;
char symbol(int a)
{
	if (a == 0)
		return '+';
	else if (a == 1)
		return '-';
	else if (a == 2)
		return '*';
	else if (a == 3)
		return '/';
	else
		return 0;
}
double operation(double a, double b, int way)
{
	if (way == 0)
		return a + b;
	else if (way == 1)
		return a - b;
	else if (way == 2)
		return a*b;
	else
		return a / b;
}
//0-》plus 1->minus 2->multi 3->dev
void t24point(double a, double b, double c, double d)
{
	int i, j, k, m, flag = 0;
	for (i = 0; i < 4; i++)//控制符号位
	{
		for (j = 0; j < 4; j++)//控制第一个符号
		{
			for (k = 0; k < 4; k++)
			{
				for (m = 0; m < 4; m++)
				{
					if (i == 0)
					{
						if (operation(operation(operation(a, b, j), c, k), d, m) == 24)
						{
							cout << "((" << a << symbol(j) << b << ")" << symbol(k) << c << ")" << symbol(m) << d << "=24" << endl;
							flag = 1;
						}
					}
					else if (i == 1)
					{
						if (operation(operation(a, b, j), operation(c, d, m), k) == 24)
						{
							cout << "(" << a << symbol(j) << b << ")" << symbol(k) << "(" << c << symbol(m) << d << ")" << "=24" << endl;
							flag = 1;
						}
					}
					else if (i == 2)
					{
						if (operation(operation(a, operation(b, c, k), j), d, m) == 24)
						{
							cout << "(" << a << symbol(j) << "(" << b << symbol(k) << c << "))" << symbol(m) << d << "=24" << endl;
							flag = 1;
						}
					}
					else if (i == 3)
					{
						if (operation(a, operation(operation(b, c, k), d, m), j) == 24)
						{
							cout << a << symbol(j) << "((" << b << symbol(k) << c << ")" << symbol(m) << d << ")" << "=24" << endl;
						}
					}
				}
			}
		}
	}
	if (flag == 0)
		cout << "无解" << endl;
}
int judge(int a)
{
	if (a > 10)
		return 0;
	else if (a < 1)
		return 0;
	else
		return 1;
}
int main()
{
	int a, b, c, d;
	while (1)
	{
		cout << "请输入四个（1-10）之间的整数：" << endl;
		cin >> a >> b >> c >> d;
		if (!cin)
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (judge(a) && judge(b) && judge(c) && judge(d))
			break;
	}
	t24point(a, b, c, d);
	return 0;

}
