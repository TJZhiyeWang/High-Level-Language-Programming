/*1553449 Õı÷æ“µ 3∞‡*/
#include <iostream>
using namespace std;
class Time
{
public:                   //ø’
	void set_time(void);
	void show_time(void);
private:                  //ø’
	int hour;
	int minute;
	int sec;
};
Time t;
int main()
{
	t.set_time();//set_time();
	t.show_time();//show_time();
	return 0;
}
void Time::set_time(void)//int set_time(void)
{
	cin >> t.hour;
	cin >> t.minute;
	cin >> t.sec;
}
void Time::show_time(void)//int show_time(void)
{
	cout << t.hour << ":" << t.minute << ":" << t.sec << endl;
}