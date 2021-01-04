/*1553449 王志业 3班*/
#include <iostream>
#include <string>
using namespace std;
class Teacher
{
protected:
	string name;
	int age;
	char sex;
	string addr;
	string num;
	string title;
public:
	void display();
	Teacher(string name, int age, char sex, string addr, string num, string title);
};
void Teacher::display()
{
	cout << "name:" << name << endl;
	cout << "age:" << age << endl;
	cout << "sex:" << sex << endl;
	cout << "address:" << addr << endl;
	cout << "num:" << num << endl;
}
Teacher::Teacher(string name1, int age1, char sex1, string addr1, string num1, string title1)
{
	name = name1;
	age = age1;
	sex = sex1;
	addr = addr1;
	num = num1;
	title = title1;
}
class Cadre
{
protected:
	string name;
	int age;
	char sex;
	string addr;
	string num;
	string post;
public:
	void display();
};
void Cadre::display()
{
	cout << "name:" << name << endl;
	cout << "age:" << age << endl;
	cout << "sex:" << sex << endl;
	cout << "address:" << addr << endl;
	cout << "num:" << num << endl;
}
class Teacher_Cadre :public Teacher, public Cadre
{
protected:
	int wages;
public:
	void show();
	Teacher_Cadre(string name, int age, char sex, string addr, string num, string title, int wages);
};
void Teacher_Cadre::show()
{
	Teacher::display();
	cout << "title:" << title << endl;
	cout << "wages:" << wages << endl;
}
Teacher_Cadre::Teacher_Cadre(string name, int age, char sex, string addr, string num, string title, int wages1) :Teacher(name, age, sex, addr, num, title)
{
	wages = wages1;
}
/*int main()
{
	Teacher_Cadre tc("黄蓉", 19, 'f', "桃花岛", "15401801827", "教授",5000);
	tc.show();
	return 0;
}*/