#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
	char* name;
	int age;
public:
	Person(const char* myname, int myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}
	Person(const Person& DeepCopy):age(DeepCopy.age) // const �־��ִ°� ����. 
	{
		name = new char[strlen(DeepCopy.name) + 1];
		strcpy(name, DeepCopy.name);
	}
	void ShowPersonInfo() const
	{
		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
	}

	~Person()
	{
		delete[]name;
		cout << "called destructor!" << endl;
	}
};

int main(void)
{
	Person man1("Jeong Jae hun", 32);
	Person man2 = man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();

	return 0;
}