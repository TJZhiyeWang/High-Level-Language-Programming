/*1553449 王志业 3班*/
#include <stdio.h>
#define pi 3.14
int main()
{
	double r = 1.5, h = 3,c,sc,sb,vb,vc;
	c = 2 * pi*r;
	sc = pi*r*r;
	sb = 4 * pi*r*r;
	vb = 4.0 / 3 * pi*r*r*r;
	vc = sc*h;
	printf("圆的周长为%.2lf，圆的面积为%.2lf,球体的体积为%.2lf,表面积为%.2lf,圆柱的体积为%.2lf", c, sc, vb, sb, vc);
	return 0;

}