#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

namespace COMP_POS {
	enum { CLERK, SENIOR, ASSIST, MANAGER };

	void ShowPositionInfo(int pos)
	{
		switch (pos)
		{
		case CLERK:
			cout << "���" << endl;
			break;
		case SENIOR:
			cout << "����" << endl;
			break;
		case ASSIST:
			cout << "�븮" << endl;
			break;
		case MANAGER:
			cout << "����" << endl;
			break;
		}
	}
}

class NameCard
{
private:
	char* name;
	char* company;
	char* phone;
	int position;
public:
	NameCard(const char * _name, const char * _company, const char * _phone,int pos) :position(pos)
	{
		name = new char[strlen(_name)+1];
		company = new char[strlen(_company) + 1];
		phone = new char[strlen(_phone) + 1];
		strcpy(name, _name);
		strcpy(company, _company);
		strcpy(phone, _phone);
	}

	void ShowNameCardInfo()
	{
		cout << "�̸� : " << name << endl;
		cout << "ȸ�� : " << company << endl;
		cout << "��ȭ��ȣ : " << phone << endl;
		cout << "���� : ";
		COMP_POS::ShowPositionInfo(position);
	}
	~NameCard() // ��ü ������ ������� �����Ҵ� �޸� ����
	{
		delete[] name;
		delete[] company;
		delete[] phone;
	}
};


int main(void)
{
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("KIM", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST);
	manClerk.ShowNameCardInfo();
	manSENIOR.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();

	return 0;
}