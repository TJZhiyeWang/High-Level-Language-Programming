/*王志业 1553449 3班 */
#include <iostream>
using namespace std;
int fac(int n)
{
	if (n == 1)
		return 1;
	return n*fac(n - 1);
}
int main()
{
	int a, b, c;
	while (1)
	{
		cout << "计算a!+b!+c!，请输入a,b,c的值" << endl;
		cin >> a>>b>>c;
		
		if (!cin)
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		break;
	}
	cout << a << "!+" << b << "!+" << c << "!=" << fac(a) + fac(b) + fac(c) << endl;
	return 0;
}
