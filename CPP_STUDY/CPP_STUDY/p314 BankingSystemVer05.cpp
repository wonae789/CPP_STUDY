#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring> // strcpy ���

using namespace std;
const int NAME_LEN = 20;

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };


class Account
{
private:
	int accID; //���¹�ȣ;
	int balance; // �ܾ�;
	char* cusName; // ���̸�
public:
	Account(int id, int money, char* name);
	Account(const Account& ref);

	int accIDGetAccID() const;
	void DepositMoney(int money);
	int WithdrawMoney(int money);
	void ShowMoney() const;
	~Account();
};

Account::Account(int id, int money, char* name) :accID(id), balance(money)
{
	cusName = new char[strlen(name) + 1];
	strcpy(cusName, name);
}

Account::Account(const Account& ref) :accID(ref.accID), balance(ref.balance)
{
	cusName = new char[strlen(ref.cusName) + 1];
	strcpy(cusName, ref.cusName);
}
int Account::accIDGetAccID() const
{
	return accID;
}
void Account::DepositMoney(int money)
{
	balance += money;
}
int Account::WithdrawMoney(int money)
{
	if (balance < money)
		return 0;
	balance -= money;
	return money;
}
void Account::ShowMoney() const
{
	
	cout << "------------------" << endl;
	cout << "����ID : " << accID << endl;
	cout << "�� �̸� : " << cusName << endl;
	cout << "�ܾ� : " << balance << endl;
	cout << "------------------" << endl;
	getchar();
	getchar();

}
Account::~Account()
{
	delete[]cusName;
}

class AccountHandler
{
private:
	Account* accArr[100]; // Account ������ �迭
	int accNum; // ����� Account ��
public:
	AccountHandler();
	void ShowMunu(void) const;
	void MakeAccount(void);
	void DepositMoney(void);
	void WithdrawMoney(void);
	void ShowAllAccInfo(void) const;
	~AccountHandler();
};
AccountHandler::AccountHandler() :accNum(0)
{}
void AccountHandler::ShowMunu(void) const
{
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
		if (accArr[i]->accIDGetAccID() == id)
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

void AccountHandler::WithdrawMoney(void)
{
	int money;
	int id;
	cout << "[�� ��]" << endl;
	cout << "����ID : "; cin >> id;
	cout << "��ݾ� : "; cin >> money;
	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->accIDGetAccID() == id)
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

void AccountHandler::ShowAllAccInfo(void) const
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowMoney();
		cout << endl;
	}
}

AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accNum; i++)
	{
		delete accArr[i];
	}
}
int main(void)
{
	AccountHandler manager;
	int choice;

	while (1)
	{
		system("cls");
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
			getchar();
		}
	}
	return 0;
}