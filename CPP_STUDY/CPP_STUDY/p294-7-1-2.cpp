#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;

class MyFriendInfo
{
private:
	char* name;
	int age;
public:
	MyFriendInfo(const char* name1, int age1) :age(age1)
	{
		name = new char[strlen(name1) + 1];
		strcpy(name, name1);
	}
	
	void ShowMyFriendInfo()
	{
		cout << "이름 : " << name << endl;
		cout << "나이 : " << age << endl;
	}

	~MyFriendInfo()
	{
		delete[] name;
	}
};


class MyFriendDetailInfo : public MyFriendInfo
{
private:
	char* addr;
	char* phone;
public:
	MyFriendDetailInfo(const char* name1, int age1, const char* addr1, const char* phone1) :MyFriendInfo(name1, age1)
	{
		addr = new char[strlen(addr1) + 1];
		strcpy(addr, addr1);
		phone = new char[strlen(phone1) + 1];
		strcpy(phone, phone1);


	}
	
	void ShowMyFriendDetailInfo()
	{
		ShowMyFriendInfo();
		cout << "주소: " << addr << endl;
		cout << "전화: " << phone << endl << endl;
	}
	~MyFriendDetailInfo()
	{
		delete[]addr;
		delete[]phone;

	}
};





int main(void)
{
	MyFriendDetailInfo data("정재훈", 32, "경기도안산", "010-3588-4256");
	
	data.ShowMyFriendDetailInfo();

	return 0;
}