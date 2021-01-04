/*王志业 1553449 计科3班*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double c, f;
	cin >> f;
	c = 5.0 / 9 * (f - 32);
	cout << setiosflags(ios::fixed) << setprecision(2)<<"华氏温度"<<f<<"对应下的摄氏温度为" << c;
	return 0;
}