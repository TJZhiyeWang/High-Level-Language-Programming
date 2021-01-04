/*1553449 王志业 3班*/
#include <iostream>
#include <cstdio>
#define max_length 80
using namespace std;
int main()
{
	char sentence[max_length];
	bool Caps = 1;
	cout << "请输入字符串" << endl;
	gets_s(sentence);
	int i = 0;
	while (sentence[i] != '\0')
	{
		if (sentence[i] == ' ')
			Caps = true;
		else
		{
			if (Caps && sentence[i] >= 'a'&&sentence[i] <= 'z')
				sentence[i] = char(sentence[i] - 32);
			else if (!Caps&&sentence[i] >= 'A'&&sentence[i] <= 'Z')
				sentence[i] = char(sentence[i] + 32);
			Caps = false;
		}
		i++;
	}
	cout << sentence;
	return 0;
}