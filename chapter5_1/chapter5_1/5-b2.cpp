/*Õı÷æ“µ 1553449 3∞‡*/
#include <iostream>
using namespace std;
int main()
{
	int bulb[100], peo = 1, temp, i;
	for (i = 0; i < 100; i++)
		bulb[i] = 0;
	for (i = 0; i < 100; i++)
	{
		temp = peo;
		while (temp <= 100)
		{
			bulb[temp - 1] += 1;
			temp += peo;
		}
		peo++;
	}
	for (i = 0; i < 100; i++)
	{
		bulb[i] %= 2;
		if (bulb[i] == 1)
			cout << i + 1 << " ";
	}
	return 0;
}