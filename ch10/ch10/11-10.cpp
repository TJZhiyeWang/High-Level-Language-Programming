/*1553449 Õı÷æ“µ 3∞‡*/
#include <iostream>
#include <string>
using namespace std;
class Teacher
{
public:
	Teacher(int num, string name, char sex);
	void show();
private:
	int num;
	string name;
	char sex;
};
Teacher::Teacher(int num1, string name1, char sex1)
{
	num = num1;
	name = name1;
	sex = sex1;
}
void Teacher::show()
{
	cout << "num:" << num << endl;
	cout << "name:" << name << endl;
	cout << "sex:" << sex << endl;
}
class BirthDate
{
public:
	void set(int y, int m, int d);
	BirthDate(int y, int m, int d);
	void show();
private:
	int year;
	int month;
	int day;
};
BirthDate::BirthDate(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}
void BirthDate::set(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}
void BirthDate::show()
{
	cout << "year:" << year << endl;
	cout << "month:" << month << endl;
	cout << "day:" << day << endl;
}
class Professor :public Teacher
{
public:
	Professor(int num1, string name1, char sex1, int y, int m, int d);
	void show();
	void set(int y, int m, int d);
private:
	BirthDate birthday;
};
Professor::Professor(int num1, string name1, char sex1, int y, int m, int d) :Teacher(num1, name1, sex1), birthday(y, m, d)
{
}
void Professor::show()
{
	Teacher::show();
	birthday.show();
}
void Professor::set(int y, int m, int d)
{
	birthday.set(y, m, d);
}
/*int main()
{
	Professor prof1(110, "ª∆»ÿ", 'f', 1997, 1, 30);
	prof1.set(1998, 2, 28);
	prof1.show();
	return 0;
}*/