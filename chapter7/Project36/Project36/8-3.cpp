/*1553449 Õı÷æ“µ 3∞‡*/
#include <iostream>
using namespace std;
class Time
{
public:
	void set_time(Time *t);
	void show_time(Time *t);
private:
	int hour;
	int minute;
	int sec;
};

int main()
{
	Time t1;
	t1.set_time(&t1);
	t1.show_time(&t1);
	return 0;
}
void Time::set_time(Time *t)
{
	cin >> (*t).hour;
	cin >> (*t).minute;
	cin >> (*t).sec;
}
void Time::show_time(Time *t)
{
	cout << (*t).hour << ":" << (*t).minute << ":" << (*t).sec << endl;
}