/* 班级 学号 姓名 */
#include <iostream>
#include <stdlib.h>	//srand/rand函数
#include <time.h>	//time函数
using namespace std;
int main()
{
	int i, peo;
	float money, t;
	/* 正确方法：用当前系统时间做种子，这样在不同时间运行则种子不同，
	从而使多次运行的伪随机数序列不同 */
	cin >> peo >> money;
	if (money < peo*0.01)
		cout << "no";
	srand((unsigned int)time(0));
	cout << endl << "伪随机数序列：" << endl;
	for (i = 0; i < peo; i++)
	{
	
	t = (rand() % 100) / 100 * (money - peo*0.01) + 0.01;
	money -= t;
	peo--;
	cout << t << endl;
}	//rand()函数用于生成0-32767间的整数

	return 0;
}