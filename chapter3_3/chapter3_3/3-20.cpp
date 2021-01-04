/*ÍõÖ¾Òµ 1553449 3°à*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int i,j,s;
	for (i = 2; i <= 1000; i++)
	{
		s = 0;
		for (j = 1; j <= i/2; j++)
		{
			if (i%j == 0)
				s += j;
		}
		if (i == s)
		{
			cout << i << "," << "its factors are 1";
			for (j = 2; j <= i / 2; j++)
			{
				if (i%j == 0)
					cout << "," << j;
			}
			cout << endl;
		}
	}
	return 0;
}