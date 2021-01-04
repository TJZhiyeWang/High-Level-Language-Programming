/*王志业 1553449 3班*/
#include <iostream>
using namespace std;
int main()
{
	int n;
	const char *Mon[13] = { "invalid","January","Februray","March","April","May","June",
		"July","August","September","October","November","December" };
	cout << "请输入月份<1-12>" << endl;
	cin >> n;
	if (n > 0 && n < 13 && cin)
		cout << *(Mon + n) << endl;
	else
		cout << *Mon << endl;
	return 0;
}
