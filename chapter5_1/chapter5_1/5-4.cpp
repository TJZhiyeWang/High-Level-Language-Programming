/*王志业 1553449 3班*/
#include <iostream>
using namespace std;
int main()
{
	int numarray[22],i=0,insert;
	cout << "请输入任意个正整数（升序，最多20个），以-1结束）" << endl;
	while (cin >> numarray[i])
	{
		if (numarray[i] == -1)
			break;
		i++;
	}
	cout << "原数组为：" << endl;
	i = 0;
	while (numarray[i] != -1)
	{
		cout << numarray[i] << " ";
		i++;
	}
	cout << endl;
	cout << "请输入要插入的正整数" << endl;
	cin >> insert;
	i = 0;
	while (insert > numarray[i])
		i++;
	int j = i;
	while (numarray[j] != -1)
		j++;
	while (j >= i)
	{
		numarray[j + 1] = numarray[j];
			j--;
	}
	numarray[i] = insert;
	cout << "插入后的数组为：" << endl;
	i = 0;
	while (numarray[i] != -1)
	{
		cout << numarray[i] << " ";
		i++;
	}
	cout << endl;
	return 0;

}