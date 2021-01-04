/*ÍõÖ¾Òµ 3°à 1553449*/
#include <iostream>
#include <string>
using namespace std;
class Student
{
public:

protected:
	int num;
	string name;
	char sex;
};
class Student1 :public Student
{
public:
	void get_value_1()
	{
		cin >> num >> name >> sex;
		cin >> age >> addr;
	}
	void display_1()
	{
		cout << "num:" << num << endl;
		cout << "name:" << name << endl;
		cout << "sex:" << sex << endl;
		cout << "age:" << age << endl;
		cout << "address:" << addr << endl;
	}
private:
	int age;
	string addr;
};
int main()
{
	Student1 stud;
	stud.get_value_1();
	stud.display_1();
	return 0;
}