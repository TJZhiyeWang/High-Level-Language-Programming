/*王志业 计科3班 1553449*/
#include <iostream>
using namespace std;
int main()
{
	char c1 = 'a', c2 = 'b', c3 = 'c', c4 = '\101', c5 = '\116';
	cout << c1 << c2 << c3 << '\n';
	cout << "\t\b" << c4 << '\t' << c5 << '\n';
	return 0;
}
/*输出abc换行后输出制表符再输出退格键输出A再输出制表符再输出N，最后输出一个换行符*/