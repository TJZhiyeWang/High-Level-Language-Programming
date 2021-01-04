/*1553449 Õı÷æ“µ 3∞‡*/
#include <iostream>
using namespace std;
class Time
{
public:
	void set_time()
	{
		cin >> hour;
		cin >> minute;
		cin >> sec;
	}
	void show_time()
	{
		cout << hour << ":" << minute << ":" << sec << endl;
	}
private:
	int hour;
	int minute;
	int sec;
};

int main()
{
	Time t1;
	t1.set_time();
	t1.show_time();
	return 0;
}
