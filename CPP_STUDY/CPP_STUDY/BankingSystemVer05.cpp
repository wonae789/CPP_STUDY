#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;
const int NAME_LEN = 20;

void ShowMunu(void);
void MakeAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllAccInfo(void);

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

/*
  Ŭ���� �̸� : Account
  Ŭ���� ���� : Entity Ŭ����
*/

class Account
{
private:
	int accID;
	int balance;
	char* cusName;
public:
	Account(int ID, int money, char* name);
	Account(const Account& ref); // ver03 ��������� �߰� , ��������ڿ� cont ������ P218��


	int GetAccID() const;
	void Deposit(int money);
	int Withdraw(int money);
	void ShowAccInfo() const;
	~Account();

};

//Account* accArr[100]; // Account ������ ���� �迭          04�� �ִ� ��. ������
//int accNum = 0; // ����� Account ��

Account::Account(int ID, int money, char* name) // �������� ���� Ŭ���� ���� ����Լ���
	:accID(ID), balance(money)                  //  �ΰ� ���Ǵ� Ŭ���� �ܺη� ��
{
	cusName = new char[strlen(name + 1)];
	strcpy(cusName, name);
}
Account::Account(const Account& ref)  
	:accID(ref.accID), balance(ref.balance)
{
	cusName = new char[strlen(ref.cusName + 1)];
	strcpy(cusName, ref.cusName);
}

int Account::GetAccID() const
{
	return accID;
} 

void Account::Deposit(int money)
{
	balance += money;
}

int Account::Withdraw(int money)
{
	if (balance < money)
		return 0;
	balance -= money;
	return money; // ??
}

void Account::ShowAccInfo() const // ver04 const �߰�
{
	cout << "------------------" << endl;
	cout << "����ID : " << accID << endl;
	cout << "�� �̸� : " << cusName << endl;
	cout << "�ܾ� : " << balance << endl;
	cout << "------------------" << endl;
}

Account::~Account()
{
	delete[]cusName;
}

/*
  Ŭ���� �̸� : AccountHandler
  Ŭ���� ���� : ��Ʈ��(Control) Ŭ����
*/

class AccountHandler 
{
private:
	Account* accArr[100];
	int accNum;
public:
	AccountHandler();
	void ShowMunu(void);
	void MakeAccount(void);
	void DepositMoney(void);
	void WithdrawMoney(void);
	void ShowAllAccInfo(void);
	~AccountHandler();
};


void AccountHandler::ShowMunu(void)
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

void AccountHandler::MakeAccount(void)
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

void AccountHandler::DepositMoney(void)
{
	int money;
	int id;
	cout << "[�� ��]" << endl;
	cout << "����ID : "; cin >> id;
	cout << "�Աݾ� : "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			accArr[i]->Deposit(money);
			cout << "�ԱݿϷ�" << endl;
			getchar(); getchar();
			return;
		}
		cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
		getchar(); getchar();
	}

}

void AccountHandler::WithdrawMoney(void)
{
	int money;
	int id;
	cout << "[�� ��]" << endl;
	cout << "����ID : "; cin >> id;
	cout << "��ݾ� : "; cin >> money;
	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			if (accArr[i]->Withdraw(money) == 0)
			{
				cout << "�ܾ� ����" << endl;
				getchar(); getchar();
				return;
			}
			cout << "��� �Ϸ�" << endl;
			getchar(); getchar();
			return;
		}
		cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
		getchar(); getchar();

	}
}

AccountHandler::AccountHandler() :accNum(0)
{

}

void AccountHandler::ShowAllAccInfo(void)
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
		getchar(); getchar();
	}
}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accNum; i++)
	{
		delete accArr[i];
	}
}

//��Ʈ�� Ŭ���� AccountHandler �߽����� ����� main �Լ�

int main(void)
{
	AccountHandler manager;
	int choice;

	while (1)
	{
		manager.ShowMunu();
		cout << "���� : ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{

		case MAKE:
			manager.MakeAccount();
			break;
		case DEPOSIT:
			manager.DepositMoney();
			break;
		case WITHDRAW:
			manager.WithdrawMoney();
			break;
		case INQUIRE:
			manager.ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "�߸� �Է��ϼ̽��ϴ�.." << endl;
			getchar(); getchar();
		}
	}
	return 0;
}