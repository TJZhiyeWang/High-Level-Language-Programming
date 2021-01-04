/*王志业 1553449 3班*/
#include <iostream>
#include <cmath> 
using namespace std;
double vector_product(double x1, double y1, double x2, double y2)
{
	return x1*y2 - x2*y1;
}
int main()
{
	bool isconvex;       //判断是不是凸多边形
	double points[2][7];     //所有点的坐标
	double arrays[2][7];      //所有边的向量坐标
	double x, y;
	int num;             //点的个数
	double S = 0;


	while (1)
	{
		cout << "请输入多边形的顶点数量(4-7):";
		cin >> num;
		if (!cin)
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else if (num > 3 && num < 8)
		{
			cin.ignore(1024, '\n');
			break;
		}
	}
	cout << "请按顺时针/逆时针方向输入" << num << "个顶点的x,y坐标" << endl;
	for (int i = 0; i < num; i++)
	{
		cout << "请输入第" << i + 1 << "个顶点的坐标:" << endl;
		while (1)
		{
			cin >> x >> y;
			if (!cin)
			{
				cin.clear();
				cin.ignore(1024, '\n');
				continue;
			}
			break;
		}
		points[0][i] = x;
		points[1][i] = y;
	}
	for (int i = 0; i < num - 1; i++)
	{
		arrays[0][i] = points[0][i + 1] - points[0][i];
		arrays[1][i] = points[1][i + 1] - points[1][i];
	}
	arrays[0][num - 1] = points[0][0] - points[0][num - 1];
	arrays[1][num - 1] = points[1][0] - points[1][num - 1];

	for (int i = 0; i < num - 1; i++)
	{
		if (fabs(vector_product(arrays[0][i], arrays[1][i], arrays[0][i + 1], arrays[1][i + 1])) < 1e-8)
		{
			cout << "不是凸" << num << "边形" << endl;
			return 0;
		}

		else if (vector_product(arrays[0][i], arrays[1][i], arrays[0][i + 1], arrays[1][i + 1]) > 0)
			isconvex = false;
	}
	if (isconvex)
	{
		for (int i = 1; i < num - 1; i++)
			S += 0.5*fabs(vector_product(points[0][i] - points[0][0], points[1][i] - points[1][0], points[0][i + 1] - points[0][0], points[1][i + 1] - points[1][0]));
		cout << "凸" << num << "边形的面积=" << S << endl;
	}
	else
		cout << "不是凸" << num << "边形" << endl;
	return 0;
}
