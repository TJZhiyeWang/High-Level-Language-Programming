/*ÍõÖ¾Òµ 1553449 3°à*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int i, j;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= i; j++)
			cout << i  << "*"  << j  << "="  << setw(3) <<setiosflags(ios::left)<<i*j;
		cout << endl;
	}
	return 0;
}