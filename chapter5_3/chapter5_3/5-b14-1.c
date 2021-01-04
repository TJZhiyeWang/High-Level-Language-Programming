/* 1553449 王志业 3班 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
char chistr[] = "零壹贰叁肆伍陆柒捌玖";
char result[256];
/* 可根据需要添加相应的内容
除本函数外，不允许任何函数中输出“零”-“玖”!!!!!! */
void daxie(int num, int flag_of_zero)
{
	char daxie_num[4] = { 0 };
	switch (num) {
		case 0:
			if (flag_of_zero) {
				strncpy(daxie_num, &chistr[0 * 2], 2);
				strcat(result, daxie_num);
			}
			break;
		case 1:
			strncpy(daxie_num, &chistr[1 * 2], 2);
			strcat(result, daxie_num);
			break;
		case 2:
			strncpy(daxie_num, &chistr[2 * 2], 2);
			strcat(result, daxie_num);
			break;
		case 3:
			strncpy(daxie_num, &chistr[3 * 2], 2);
			strcat(result, daxie_num);
			break;
		case 4:
			strncpy(daxie_num, &chistr[4 * 2], 2);
			strcat(result, daxie_num);
			break;
		case 5:
			strncpy(daxie_num, &chistr[5 * 2], 2);
			strcat(result, daxie_num);
			break;
		case 6:
			strncpy(daxie_num, &chistr[6 * 2], 2);
			strcat(result, daxie_num);
			break;
		case 7:
			strncpy(daxie_num, &chistr[7 * 2], 2);
			strcat(result, daxie_num);
			break;
		case 8:
			strncpy(daxie_num, &chistr[8 * 2], 2);
			strcat(result, daxie_num);
			break;
		case 9:
			strncpy(daxie_num, &chistr[9 * 2], 2);
			strcat(result, daxie_num);
			break;
		default:
			printf("error") ;
			break;
	}
}
/* 根据需要完成main函数 */
int main()
{
	int flag_of_zero = 0;//1输出0，否则不输出
	double num;
	int shiyi, yi, qianwan, baiwan, shiwan, wan, qian, bai, shi, ge, jiao, fen, s, sq;
	printf("请输入【0-100亿】之间的数字：\n");
	scanf("%lf",&num);
	printf( "大写的结果是：\n");
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
	daxie(shiyi, flag_of_zero);
	if (shiyi != 0)

		strcat(result,"拾");
	daxie(yi, flag_of_zero);
	if (shiyi != 0 || yi != 0)
		strcat(result,"亿" );

	if ((shiyi != 0 || yi != 0) && (qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0))
		flag_of_zero = 1;
	daxie(qianwan, flag_of_zero);
	if (qianwan != 0)
		strcat(result,"仟" );
	flag_of_zero = 0;

	if (qianwan != 0 && (shiwan != 0 || wan != 0))
		flag_of_zero = 1;
	daxie(baiwan, flag_of_zero);
	if (baiwan != 0)
		strcat(result,"佰");
	flag_of_zero = 0;

	if (baiwan != 0 && wan != 0)
		flag_of_zero = 1;
	daxie(shiwan, flag_of_zero);
	if (shiwan != 0)
		strcat(result,"拾");
	flag_of_zero = 0;

	daxie(wan, flag_of_zero);
	if (qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0)
		strcat(result, "万");

	if ((shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0) && (bai != 0 || shi != 0 || ge != 0))
		flag_of_zero = 1;
	daxie(qian, flag_of_zero);
	if (qian != 0)
		strcat(result, "仟");
	flag_of_zero = 0;

	if (qian != 0 && (shi != 0 || ge != 0))
		flag_of_zero = 1;
	daxie(bai, flag_of_zero);
	if (bai != 0)
		strcat(result, "佰");
	flag_of_zero = 0;

	if (bai != 0 && ge != 0)
		flag_of_zero = 1;
	daxie(shi, flag_of_zero);
	if (shi != 0)
		strcat(result,"拾");
	flag_of_zero = 0;
	if (shiyi == 0 && yi == 0 && qianwan == 0 && baiwan == 0 && shiwan == 0 && wan == 0 && qian == 0 && bai == 0 && shi == 0 && ge == 0 && jiao == 0 && fen == 0)
		flag_of_zero = 1;
	daxie(ge, flag_of_zero);
	if (!(shiyi == 0 && yi == 0 && qianwan == 0 && baiwan == 0 && shiwan == 0 && wan == 0 && qian == 0 && bai == 0 && shi == 0 && ge == 0 && (jiao != 0 || fen != 0)))
		strcat(result,"圆");
	s = (int)(floor(num * 10) - floor(num) * 10);
	sq = (int)(floor(num * 100) - floor(num * 10) * 10);
	flag_of_zero = 0;
	if (s == 0 && sq == 0)
		strcat(result,"整");
		
	else if (sq == 0)
	{
		daxie(jiao, flag_of_zero);
		strcat(result, "角");
		strcat(result, "整");
	}
	else if (s == 0)
	{
		if (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0 || qian != 0 || bai != 0 || shi != 0 || ge != 0)
			flag_of_zero = 1;
		daxie(s, flag_of_zero);
		daxie(fen, flag_of_zero);
		strcat(result, "分");
	}
	else
	{
		daxie(jiao, flag_of_zero);
		strcat(result,"角");
		
		daxie(fen, flag_of_zero);
		strcat(result,"分");
	}
	printf("%s",result);
	return 0;
}
