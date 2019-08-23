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
	Account(int id, int money, char *name) :accID(id), balance(money)
	{
		cusName = new char[strlen(name) + 1];
		strcpy(cusName, name);
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


Account *accArr[100]; // Account ������ �迭
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
			for (int i = 0; i < accNum ; i++)
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

//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <cstring> // strcpy ���
//
//#include <cstdlib> // system("cls") ���
//#include <cstdio>
//
//using namespace std;
//const int NAME_LEN = 20;
//
//void ShowMunu(void);
//void MakeAccount(void);
//void DepositMoney(void);
//void WithdrawMoney(void);
//void ShowAllAccInfo(void);
//
//enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
//
//
//
//class Account
//{
//private:
//	int accID; //���¹�ȣ;
//	int balance; // �ܾ�;
//	char* cusName; // ���̸�
//public:
//	Account(int ID, int money, char* name) :accID(ID), balance(money)
//	{
//		cusName = new char[strlen(name) + 1];
//		strcpy(cusName, name);
//	}
//
//	int GetAccID()
//	{
//		return accID;
//	}
//
//	void Deposit(int money)
//	{
//		balance += money;
//	}
//
//	int Withdraw(int money) // ��ݾ� ��ȯ ������ 0 ��ȯ.
//	{
//		if (balance < money)
//			return 0;
//		balance -= money;
//		return money;
//	}
//
//	void ShowAccInfo()
//	{
//		cout << "����ID : " << accID << endl;
//		cout << "�� �� : " << cusName << endl;
//		cout << "�� �� : " << balance << endl;
//		getchar();
//
//	}
//
//	~Account()
//	{
//		delete[]cusName;
//	}
//
//
//};
//
//
//
//Account *accArr[100]; // Account ������ ���� �迭
//int accNum = 0; // ����� Account ��
//
//int main(void)
//{
//
//
//	int choice;
//
//	while (1)
//	{
//		ShowMunu();
//		cout << "���� : ";
//		cin >> choice;
//		cout << endl;
//
//		switch (choice)
//		{
//
//		case MAKE:
//			MakeAccount();
//			break;
//		case DEPOSIT:
//			DepositMoney();
//			break;
//		case WITHDRAW:
//			WithdrawMoney();
//			break;
//		case INQUIRE:
//			ShowAllAccInfo();
//			break;
//		case EXIT:
//			for (int i = 0; i < accNum; i++)			
//				delete[] accArr[i];
//			return 0;
//			
//		default:
//			cout << "�߸� �Է��ϼ̽��ϴ�.." << endl;
//			getchar();
//		}
//	}
//	return 0;
//}
//void ShowMunu(void)
//{
//	system("cls");
//	cout << "----------------" << endl;
//	cout << "1. ���°���" << endl;
//	cout << "2. �� ��" << endl;
//	cout << "3. �� ��" << endl;
//	cout << "4. �������� ��ü ���" << endl;
//	cout << "5. ���α׷� ����" << endl;
//	cout << "----------------" << endl;
//	
//}
//
//void MakeAccount(void)
//{
//	int id;
//	char name[NAME_LEN];
//	int balance;
//	cout << "[���°���]" << endl;
//	cout << "����ID : "; cin >> id;
//	cout << "�� �̸� : "; cin >> name;
//	cout << "�ܾ� : "; cin >> balance;
//	cout << endl;
//	accArr[accNum++] = new Account(id, balance, name);
//	cout << "�����Ϸ�." << endl;
//	getchar();
//	getchar();
//
//
//}
//void DepositMoney(void)
//{
//	int money;
//	int id;
//	cout << "[�� ��]" << endl;
//	cout << "����ID : "; cin >> id;
//	cout << "�Աݾ� : "; cin >> money;
//
//	for (int i = 0; i < accNum; i++)
//	{
//		if (accArr[i]->GetAccID() == id)
//		{
//			accArr[i]->Deposit(money);
//			cout << "�ԱݿϷ�" << endl;
//			getchar();
//			return;
//		}
//		cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
//		getchar();
//	}
//}
//void WithdrawMoney(void)
//{
//	int money;
//	int id;
//	cout << "[�� ��]" << endl;
//	cout << "����ID : "; cin >> id;
//	cout << "��ݾ� : "; cin >> money;
//	for (int i = 0; i < accNum; i++)
//	{
//		if (accArr[i]->GetAccID() == id)
//		{
//			if (accArr[i]->Withdraw(money) == 0)
//			{
//				cout << "�ܾ� ���� " << endl;
//			}
//			cout << "��� �Ϸ�" << endl;
//			getchar();
//			return;
//		}
//		cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
//		getchar();
//
//	}
//}
//void ShowAllAccInfo(void)
//{
//	for (int i = 0; i < accNum; i++)
//	{
//		accArr[i]->ShowAccInfo();
//		cout << endl;
//	}
//	getchar();
//}



//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<cstring>
//using namespace std;
//const int NAME_LEN = 20;
//
//void ShowMunu(void);
//void MakeAccount(void);
//void DepositMoney(void);
//void WithdrawMoney(void);
//void ShowAllAccInfo(void);
//
//enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };
//
//
//class Account
//{
//private:
//	int accID;
//	int balance;
//	char* cusName;
//public:
//	Account(int ID, int money, char* name)
//		:accID(ID), balance(money)
//	{
//		cusName = new char[strlen(name + 1)];
//		strcpy(cusName, name);
//	}
//
//	int GetAccID() { return accID; }
//
//	void Deposit(int money)
//	{
//		balance += money;
//	}
//
//	int Withdraw(int money)
//	{
//		if (balance < money)
//			return 0;
//		balance -= money;
//		return money; // ??
//	}
//
//	void ShowAccInfo()
//	{
//		cout << "------------------" << endl;
//		cout << "����ID : " << accID << endl;
//		cout << "�� �̸� : " << cusName << endl;
//		cout << "�ܾ� : " << balance << endl;
//		cout << "------------------" << endl;
//	}
//
//	~Account()
//	{
//		delete[]cusName;
//	}
//};
//
//Account* accArr[100]; // Account ������ ���� �迭
//int accNum = 0; // ����� Account ��
//
//
//
//int main(void)
//{
//	int choice;
//
//	while (1)
//	{
//		ShowMunu();
//		cout << "���� : ";
//		cin >> choice;
//		cout << endl;
//
//		switch (choice)
//		{
//
//		case MAKE:
//			MakeAccount();
//			break;
//		case DEPOSIT:
//			DepositMoney();
//			break;
//		case WITHDRAW:
//			WithdrawMoney();
//			break;
//		case INQUIRE:
//			ShowAllAccInfo();
//			break;
//		case EXIT:
//			for (int i = 0; i < accNum; i++)
//				delete accArr[i];
//			break;
//		default:
//			cout << "�߸� �Է��ϼ̽��ϴ�.." << endl;
//			getchar(); getchar();
//		}
//	}
//	return 0;
//}
//
//void ShowMunu(void)
//{
//	system("cls");
//	cout << "----------------" << endl;
//	cout << "1. ���°���" << endl;
//	cout << "2. �� ��" << endl;
//	cout << "3. �� ��" << endl;
//	cout << "4. �������� ��ü ���" << endl;
//	cout << "5. ���α׷� ����" << endl;
//	cout << "----------------" << endl;
//}
//
//void MakeAccount(void)
//{
//	int id;
//	char name[NAME_LEN];
//	int balance;
//	cout << "[���°���]" << endl;
//	cout << "����ID : "; cin >> id;
//	cout << "�� �̸� : "; cin >> name;
//	cout << "�ܾ� : "; cin >> balance;
//	cout << endl;
//
//	accArr[accNum++] = new Account(id, balance, name);
//
//}
//
//void DepositMoney(void)
//{
//	int money;
//	int id;
//	cout << "[�� ��]" << endl;
//	cout << "����ID : "; cin >> id;
//	cout << "�Աݾ� : "; cin >> money;
//
//	for (int i = 0; i < accNum; i++)
//	{
//		if (accArr[i]->GetAccID() == id)
//		{
//			accArr[i]->Deposit(money);
//			cout << "�ԱݿϷ�" << endl;
//			getchar(); getchar();
//			return;
//		}
//		cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
//		getchar(); getchar();
//	}
//
//}
//
//void WithdrawMoney(void)
//{
//	int money;
//	int id;
//	cout << "[�� ��]" << endl;
//	cout << "����ID : "; cin >> id;
//	cout << "��ݾ� : "; cin >> money;
//	for (int i = 0; i < accNum; i++)
//	{
//		if (accArr[i]->GetAccID() == id)
//		{
//			if (accArr[i]->Withdraw(money) == 0)
//			{
//				cout << "�ܾ� ����" << endl;
//				getchar(); getchar();
//				return;
//			}
//			cout << "��� �Ϸ�" << endl;
//			getchar(); getchar();
//			return;
//		}
//		cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
//		getchar(); getchar();
//
//	}
//}
//
//void ShowAllAccInfo(void)
//{
//	for (int i = 0; i < accNum; i++)
//	{
//		accArr[i]->ShowAccInfo();
//		cout << endl;
//		getchar();getchar();
//	}
//}