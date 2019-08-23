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




typedef struct
{
	int accID; //���¹�ȣ;
	char cusName[NAME_LEN]; // ���̸�
	int balance; // �ܾ�;
}Account;

Account accArr[100]; // Account ������ ���� �迭
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
			break;
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

	accArr[accNum].accID = id;
	accArr[accNum].balance = balance;
	strcpy(accArr[accNum].cusName, name);
	accNum++;
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
		if (accArr[i].accID == id)
		{
			accArr[i].balance += money;
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
		if (accArr[i].accID == id)
		{
			accArr[i].balance -= money;
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
		cout << "------------------" << endl;
		cout << "����ID : " << accArr[i].accID << endl;
		cout << "�� �̸� : " << accArr[i].cusName << endl;
		cout << "�ܾ� : " << accArr[i].balance << endl;
		cout << "------------------" << endl;
	}
	getchar();
}