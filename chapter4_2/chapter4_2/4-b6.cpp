/*王志业 3班 1553449*/
#include <iostream>
using namespace std;
int Fibonacii(int n)
{
	if (n == 1 || n == 2)
		return 1;
	return Fibonacii(n - 1) + Fibonacii(n - 2);
}

int main()
{
	int n;
	while (1)
	{
		cout << "请输入Fibonacci的项数：" << endl;
		cin >> n;
		if (!cin)
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (n <= 0)
			continue;
		break;
	}
	cout << "Fibonacci数列第"<<n<<"项的值："<<Fibonacii(n)<<endl;
	return 0;
}
