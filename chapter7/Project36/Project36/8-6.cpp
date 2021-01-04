#include <iostream>
using namespace std;
class Cube
{
private:
	double length;
	double width;
	double height;
	double vol;
public:
	void input()
	{
		cin >> length;
		cin >> width;
		cin >> height;
	}
	void volume()
	{
		vol = length*width*height;
	}
	void output()
	{
		cout << endl << vol;
	}
};
int main()
{
	Cube a;
	a.input();
	a.volume();
	a.output();
	return 0;
}