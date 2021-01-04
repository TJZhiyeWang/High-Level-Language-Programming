/*王志业 3班 1553449*/
#include <iostream>
#include <stdio.h> 
#include <>
using namespace std;

int main()
{
	int  shiyi, yi, qianwan, baiwan, shiwan, wan, qian, bai, shi, ge, jiao, fen,s,flag=0;
	double num;
	cout << "请输入一个[0-100亿)的浮点数："<<endl;
	cin >> num;
	shiyi = (int)floor(num*10e-10);
	yi = (int)floor(num*10e-9) - shiyi * 10;
	qianwan = (int)floor(num*10e-8) - (int)floor(num*10e-9) * 10;
	baiwan = (int)floor(num*10e-7) - (int)floor(num*10e-8) * 10;
	shiwan = (int)floor(num*10e-6) - (int)floor(num*10e-7) * 10;
	wan = (int)floor(num*10e-5) - (int)floor(num*10e-6) * 10;
	qian = (int)floor(num*10e-4) - (int)floor(num*10e-5) * 10;
	bai = (int)floor(num*10e-3) - (int)floor(num*10e-4) * 10;
	shi = (int)floor(num*10e-2) - (int)floor(num*10e-3) * 10;
	ge = (int)(floor(num*10e-1) - floor(num*10e-2) * 10);
	num += 1e-6;
	jiao = (int)(floor(num * 10) - floor(num) * 10);
	fen = (int)(floor(num * 100) - floor(num * 10) * 10);
	
	return 0;
}
