#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring> // strcpy ���

#include <cstdlib> // system("cls") ���
#include <cstdio>

using namespace std;
const int NAME_LEN = 20;

void ShowMunu(void);
void MakeAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllAccInfo(void);

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };



class Account
{
private:
	int accID; //���¹�ȣ;
	int balance; // �ܾ�;
	char* cusName; // ���̸�
public:
	Account(int id, int money, char* name) :accID(id), balance(money)
	{
		cusName = new char[strlen(name) + 1];
		strcpy(cusName, name);
	}

	Account(const Account& ref) :accID(ref.accID), balance(ref.balance)
	{
		cusName = new char[strlen(ref.cusName) + 1];
		strcpy(cusName, ref.cusName);
	}

	int accIDInfo()
	{
		return accID;
	}

	void DepositMoney(int money)
	{
		balance += money;
	}

	int WithdrawMoney(int money)
	{
		if (balance < money)
			return 0;
		balance -= money;
		return money;
	}

	void ShowMoney()
	{
		cout << "------------------" << endl;
		cout << "����ID : " << accID << endl;
		cout << "�� �̸� : " << cusName << endl;
		cout << "�ܾ� : " << balance << endl;
		cout << "------------------" << endl;
		getchar();
	}
	~Account()
	{
		delete[]cusName;
	}

};


Account* accArr[100]; // Account ������ �迭
int accNum = 0; // ����� Account ��

int main(void)
{


	int choice;

	while (1)
	{
		ShowMunu();
		cout << "���� : ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{

		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW:
			WithdrawMoney();
			break;
		case INQUIRE:
			ShowAllAccInfo();
			break;
		case EXIT:
			for (int i = 0; i < accNum; i++)
			{
				delete accArr[i];
			}
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�.." << endl;
			getchar();
		}
	}
	return 0;
}
void ShowMunu(void)
{
	system("cls");
	cout << "----------------" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �� ��" << endl;
	cout << "3. �� ��" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << "----------------" << endl;
}

void MakeAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;
	cout << "[���°���]" << endl;
	cout << "����ID : "; cin >> id;
	cout << "�� �̸� : "; cin >> name;
	cout << "�ܾ� : "; cin >> balance;
	cout << endl;

	accArr[accNum++] = new Account(id, balance, name);

}
void DepositMoney(void)
{
	int money;
	int id;
	cout << "[�� ��]" << endl;
	cout << "����ID : "; cin >> id;
	cout << "�Աݾ� : "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{



		if (accArr[i]->accIDInfo() == id)
		{
			accArr[i]->DepositMoney(money);
			cout << "�ԱݿϷ�" << endl;
			getchar();
			return;
		}
		cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
		getchar();
	}
}
void WithdrawMoney(void)
{
	int money;
	int id;
	cout << "[�� ��]" << endl;
	cout << "����ID : "; cin >> id;
	cout << "��ݾ� : "; cin >> money;
	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->accIDInfo() == id)
		{
			if (accArr[i]->WithdrawMoney(money) == 0)
			{
				cout << "��� �ݾ��� �����մϴ�." << endl;
				return;
			}
			cout << "��� �Ϸ�" << endl;
			getchar();
			return;
		}
		cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
		getchar();

	}
}
void ShowAllAccInfo(void)
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowMoney();
		cout << endl;
	}
}
