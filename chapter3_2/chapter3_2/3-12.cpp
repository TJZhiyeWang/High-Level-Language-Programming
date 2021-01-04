/*王志业 3班 1553449*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int x, temp,i=1;
	cout << "请输入一个【0。。。99999】间的整数" << endl;
	cin >> x;
	temp = x;
	if ((temp /= 10) >= 1)
		i++;
	if ((temp /= 10) >= 1)
		i++;
	if ((temp /= 10) >= 1)
		i++;
	if ((temp /= 10) >= 1)
		i++;
	cout << i << "位数"<<endl;
	temp = x;
	cout << "正序输出" << endl;
	if (i >= 5)
	{
		cout << temp / 10000<<" ";
		temp -= temp / 10000 * 10000;
	}
	if (i >= 4)
	{
		cout << temp / 1000 << " ";
		temp -= temp / 1000 * 1000;
	}
	if (i >= 3)
	{
		cout << temp / 100 << " ";
		temp -= temp / 100 * 100;
	}
	if (i >= 2)
	{
		cout << temp / 10 << " ";
		temp -= temp / 10 * 10;
	}
	cout << temp<<endl;
	cout << "逆序输出" << endl;
	temp = x;
	if (temp >= 1)
	{
		cout << temp % 10 ;
		temp /= 10;
	}
	if (temp >= 1)
	{
		cout << " ";
		cout << temp % 10 ;
		temp /= 10;
	}
	if (temp >= 1)
	{
		cout << " ";
		cout << temp % 10 ;
		temp /= 10;
	}
	if (temp >= 1)
	{
		cout << " ";
		cout << temp % 10 ;
		temp /= 10;
	}
	if (temp >= 1)
	{
		cout << " ";
		cout << temp % 10 ;
		temp /= 10;
	}
	cout << endl;
	return 0;
}