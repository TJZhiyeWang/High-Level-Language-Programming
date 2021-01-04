/* 3班 1553449 王志业*/
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <windows.h> //取系统时间
using namespace std;

int main()
{
	LARGE_INTEGER tick, fc_begin, fc_end;

	QueryPerformanceFrequency(&tick);	//获得时钟频率
	QueryPerformanceCounter(&fc_begin);	//获得初始硬件定时器计数

										/* 此处是你的程序开始 */
	int a, b, c, d, e, f, g, h, i,n=1;
	for (a = 1; a <= 9; a++)
	{
		for (b = 1; b <= 9; b++)
		{
			if (a == b)
				continue;
			for (c = 1; c <= 9; c++)
			{
				if (c == b||c==a)
					continue;
				for (d = 1; d <= 9; d++)
				{
					if ((a>d)||(d == c || d == b||d==a))
						continue;
					for (e = 1; e <= 9; e++)
					{
						if (e == d || e == c || e == b || e == a)
							continue;
						for (f = 1; f <= 9; f++)
						{
							if (f == e || f == d || f == c || f == b || f == a)
								continue;
							for (g = 1; g <= 9; g++)
							{
								if (d>g||(g == f || g == e || g == d || g == c || g == b || g == a))
									continue;
								for (h = 1; h <= 9; h++)
								{
									if (h == g || h == f || h == e || h == d || h == c || h == b || h == a)
										continue;
									for (i = 1; i <= 9; i++)
									{
										if (i == h || i == g || i == f || i == e || i == d || i == c || i == b || i == a)
											continue;
										if (((a + d + g) * 100 + (b + e + h) * 10 + c + f + i) == 1953)
										{
											cout << "No." <<setw(3)<< n << " : " << a << b << c << "+" << d << e << f << "+" << g << h << i << "=" << 1953 << endl;
											n++;
										}
											
									}
								}
							}
						}
					}
				}
			}
		}
	}











										/* 此处是你的程序结束 */

	QueryPerformanceCounter(&fc_end);//获得终止硬件定时器计数
	cout << setiosflags(ios::fixed) << setprecision(3);
	cout << "时钟频率：" << double(tick.QuadPart) / 1024 / 1024 << "GHz" << endl;
	cout << setprecision(0);
	cout << "时钟计数：" << double(fc_end.QuadPart - fc_begin.QuadPart) << endl;
	cout << setprecision(6) << double(fc_end.QuadPart - fc_begin.QuadPart) / double(tick.QuadPart) << "秒" << endl;

	return 0;
}