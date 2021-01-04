/*Õı÷æ“µ 1553449 3∞‡*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double num;
	int shiyi, yi, qianwan, baiwan, shiwan, wan, qian, bai, shi, ge, jiao, fen, s, sq;
	cout << "«Î ‰»Î°æ0-100“⁄°ø÷Æº‰µƒ ˝◊÷£∫" << endl;
	cin >> num;
	cout << "¥Û–¥µƒΩ·π˚ «£∫" << endl;
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
	if (shiyi != 0)
	{
		if (shiyi == 1)
			cout << "“º";
		if (shiyi == 2)
			cout << "∑°";
		if (shiyi == 3)
			cout << "»˛";
		if (shiyi == 4)
			cout << "À¡";
		if (shiyi == 5)
			cout << "ŒÈ";
		if (shiyi == 6)
			cout << "¬Ω";
		if (shiyi == 7)
			cout << "∆‚";
		if (shiyi == 8)
			cout << "∞∆";
		if (shiyi == 9)
			cout << "æ¡";
		cout << " ∞";
	}
	if (yi != 0)
	{
		if (yi == 1)
			cout << "“º";
		if (yi == 2)
			cout << "∑°";
		if (yi == 3)
			cout << "»˛";
		if (yi == 4)
			cout << "À¡";
		if (yi == 5)
			cout << "ŒÈ";
		if (yi == 6)
			cout << "¬Ω";
		if (yi == 7)
			cout << "∆‚";
		if (yi == 8)
			cout << "∞∆";
		if (yi == 9)
			cout << "æ¡";
	}
	if (shiyi != 0 || yi != 0)
		cout << "“⁄";
	if (qianwan != 0)
	{
		if (qianwan == 1)
			cout << "“º";
		if (qianwan == 2)
			cout << "∑°";
		if (qianwan == 3)
			cout << "»˛";
		if (qianwan == 4)
			cout << "À¡";
		if (qianwan == 5)
			cout << "ŒÈ";
		if (qianwan == 6)
			cout << "¬Ω";
		if (qianwan == 7)
			cout << "∆‚";
		if (qianwan == 8)
			cout << "∞∆";
		if (qianwan == 9)
			cout << "æ¡";
		cout << "«™";
	}
	else if ((shiyi != 0 || yi != 0) && (qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0))
		cout << "¡„";
	if (baiwan != 0)
	{
		if (baiwan == 1)
			cout << "“º";
		if (baiwan == 2)
			cout << "∑°";
		if (baiwan == 3)
			cout << "»˛";
		if (baiwan == 4)
			cout << "À¡";
		if (baiwan == 5)
			cout << "ŒÈ";
		if (baiwan == 6)
			cout << "¬Ω";
		if (baiwan == 7)
			cout << "∆‚";
		if (baiwan == 8)
			cout << "∞∆";
		if (baiwan == 9)
			cout << "æ¡";
		cout << "∞€";
	}
	else if (qianwan != 0 && (shiwan != 0 || wan != 0))
		cout << "¡„";
	if (shiwan!= 0)
	{
		if (shiwan == 1)
			cout << "“º";
		if (shiwan == 2)
			cout << "∑°";
		if (shiwan == 3)
			cout << "»˛";
		if (shiwan == 4)
			cout << "À¡";
		if (shiwan == 5)
			cout << "ŒÈ";
		if (shiwan == 6)
			cout << "¬Ω";
		if (shiwan == 7)
			cout << "∆‚";
		if (shiwan == 8)
			cout << "∞∆";
		if (shiwan == 9)
			cout << "æ¡";
		cout << " ∞";
	}
	else if (baiwan != 0&&wan!=0)
		cout << "¡„";
	if (wan != 0)
	{
		if (wan == 1)
			cout << "“º";
		if (wan == 2)
			cout << "∑°";
		if (wan == 3)
			cout << "»˛";
		if (wan == 4)
			cout << "À¡";
		if (wan == 5)
			cout << "ŒÈ";
		if (wan == 6)
			cout << "¬Ω";
		if (wan == 7)
			cout << "∆‚";
		if (wan == 8)
			cout << "∞∆";
		if (wan == 9)
			cout << "æ¡";
		
	}
	if(qianwan!=0||baiwan!=0||shiwan!=0||wan!=0)
		cout << "ÕÚ";
	if (qian != 0)
	{
		if (qian == 1)
			cout << "“º";
		if (qian == 2)
			cout << "∑°";
		if (qian == 3)
			cout << "»˛";
		if (qian == 4)
			cout << "À¡";
		if (qian == 5)
			cout << "ŒÈ";
		if (qian == 6)
			cout << "¬Ω";
		if (qian == 7)
			cout << "∆‚";
		if (qian == 8)
			cout << "∞∆";
		if (qian == 9)
			cout << "æ¡";
		cout << "«™";
	}
	else if ((shiyi != 0||yi!=0||qianwan!=0||baiwan!=0||shiwan!=0||wan!=0)&&(bai!=0||shi!=0||ge!=0))
		cout << "¡„";
	if (bai != 0)
	{
		if (bai == 1)
			cout << "“º";
		if (bai == 2)
			cout << "∑°";
		if (bai == 3)
			cout << "»˛";
		if (bai == 4)
			cout << "À¡";
		if (bai == 5)
			cout << "ŒÈ";
		if (bai == 6)
			cout << "¬Ω";
		if (bai == 7)
			cout << "∆‚";
		if (bai == 8)
			cout << "∞∆";
		if (bai == 9)
			cout << "æ¡";
		cout << "∞€";
	}
	else if (qian!=0&&(shi!=0||ge!=0))
		cout << "¡„";
	if (shi != 0)
	{
		if (shi == 1)
			cout << "“º";
		if (shi == 2)
			cout << "∑°";
		if (shi == 3)
			cout << "»˛";
		if (shi == 4)
			cout << "À¡";
		if (shi == 5)
			cout << "ŒÈ";
		if (shi == 6)
			cout << "¬Ω";
		if (shi == 7)
			cout << "∆‚";
		if (shi == 8)
			cout << "∞∆";
		if (shi == 9)
			cout << "æ¡";
		cout << " ∞";
	}
	else if (bai != 0&&ge!=0)
		cout << "¡„";
	if (ge != 0)
	{
		if (ge == 1)
			cout << "“º";
		if (ge == 2)
			cout << "∑°";
		if (ge == 3)
			cout << "»˛";
		if (ge == 4)
			cout << "À¡";
		if (ge == 5)
			cout << "ŒÈ";
		if (ge == 6)
			cout << "¬Ω";
		if (ge == 7)
			cout << "∆‚";
		if (ge == 8)
			cout << "∞∆";
		if (ge == 9)
			cout << "æ¡";
		cout << "‘≤";
	}
    else if(shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0||qian!=0||bai!=0||shi!=0)
	cout << "‘≤";
	num += 1e-5;
	if (shiyi == 0 && yi == 0 && qianwan == 0 && baiwan == 0 && shiwan == 0 && wan == 0 && qian == 0 && bai == 0 && shi == 0 && ge == 0 && jiao == 0 && fen == 0)
		cout << "¡„‘≤";
	s = (int)(floor(num * 10) - floor(num) * 10);
	sq= (int)(floor(num * 100) - floor(num * 10) * 10);
	if (s == 0 && sq == 0)
		cout << "’˚";
	else if (sq == 0)
	{
		if (s == 1)
			cout << "“º";
		if (s == 2)
			cout << "∑°";
		if (s == 3)
			cout << "»˛";
		if (s == 4)
			cout << "À¡";
		if (s == 5)
			cout << "ŒÈ";
		if (s == 6)
			cout << "¬Ω";
		if (s == 7)
			cout << "∆‚";
		if (s == 8)
			cout << "∞∆";
		if (s == 9)
			cout << "æ¡";
		cout << "Ω«";
		cout << "’˚";
	}
	else if (s == 0)
	{
		if(shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0 || qian != 0 || bai != 0 || shi != 0||ge!=0)
		cout << "¡„";
		if (sq == 1)
			cout << "“º";
		if (sq == 2)
			cout << "∑°";
		if (sq == 3)
			cout << "»˛";
		if (sq == 4)
			cout << "À¡";
		if (sq == 5)
			cout << "ŒÈ";
		if (sq == 6)
			cout << "¬Ω";
		if (sq == 7)
			cout << "∆‚";
		if (sq == 8)
			cout << "∞∆";
		if (sq == 9)
			cout << "æ¡";
		cout << "∑÷";
	}
	else
	{
		if (s == 1)
			cout << "“º";
		if (s == 2)
			cout << "∑°";
		if (s == 3)
			cout << "»˛";
		if (s == 4)
			cout << "À¡";
		if (s == 5)
			cout << "ŒÈ";
		if (s == 6)
			cout << "¬Ω";
		if (s == 7)
			cout << "∆‚";
		if (s == 8)
			cout << "∞∆";
		if (s == 9)
			cout << "æ¡";
		cout << "Ω«";

		if (sq == 1)
			cout << "“º";
		if (sq == 2)
			cout << "∑°";
		if (sq == 3)
			cout << "»˛";
		if (sq == 4)
			cout << "À¡";
		if (sq == 5)
			cout << "ŒÈ";
		if (sq == 6)
			cout << "¬Ω";
		if (sq == 7)
			cout << "∆‚";
		if (sq == 8)
			cout << "∞∆";
		if (sq == 9)
			cout << "æ¡";
		cout << "∑÷";
	}
	return 0;

}