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


class Account
{
private:
	int accID;
	int balance;
	char* cusName;
public:
	Account(int ID, int money, char* name)
		:accID(ID), balance(money)
	{
		cusName = new char[strlen(name + 1)];
		strcpy(cusName, name);
	}

	Account(const Account & ref) // 복사생성자 추가
		:accID(ref.accID), balance(ref.balance)
	{
		cusName = new char[strlen(ref.cusName + 1)];
		strcpy(cusName, ref.cusName);
	}

	int GetAccID() { return accID; }

	void Deposit(int money)
	{
		balance += money;
	}

	int Withdraw(int money)
	{
		if (balance < money)
			return 0;
		balance -= money;
		return money; // ??
	}

	void ShowAccInfo()
	{
		cout << "------------------" << endl;
		cout << "계좌ID : " << accID << endl;
		cout << "고객 이름 : " << cusName << endl;
		cout << "잔액 : " << balance << endl;
		cout << "------------------" << endl;
	}

	~Account()
	{
		delete[]cusName;
	}
};

Account* accArr[100]; // Account 저장을 위한 배열
int accNum = 0; // 저장된 Account 수



int main(void)
{
	int choice;

	while (1)
	{
		ShowMunu();
		cout << "선택 : ";
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
				delete accArr[i];
			break;
		default:
			cout << "잘못 입력하셨습니다.." << endl;
			getchar(); getchar();
		}
	}
	return 0;
}

void ShowMunu(void)
{
	system("cls");
	cout << "----------------" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "----------------" << endl;
}

void MakeAccount(void)
{
	int id;
	char name[NAME_LEN];
	int balance;
	cout << "[계좌개설]" << endl;
	cout << "계좌ID : "; cin >> id;
	cout << "고객 이름 : "; cin >> name;
	cout << "잔액 : "; cin >> balance;
	cout << endl;

	accArr[accNum++] = new Account(id, balance, name);

}

void DepositMoney(void)
{
	int money;
	int id;
	cout << "[입 금]" << endl;
	cout << "계좌ID : "; cin >> id;
	cout << "입금액 : "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			accArr[i]->Deposit(money);
			cout << "입금완료" << endl;
			getchar(); getchar();
			return;
		}
		cout << "유효하지 않은 ID 입니다." << endl << endl;
		getchar(); getchar();
	}

}

void WithdrawMoney(void)
{
	int money;
	int id;
	cout << "[출 금]" << endl;
	cout << "계좌ID : "; cin >> id;
	cout << "출금액 : "; cin >> money;
	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccID() == id)
		{
			if (accArr[i]->Withdraw(money) == 0)
			{
				cout << "잔액 부족" << endl;
				getchar(); getchar();
				return;
			}
			cout << "출금 완료" << endl;
			getchar(); getchar();
			return;
		}
		cout << "유효하지 않은 ID 입니다." << endl << endl;
		getchar(); getchar();

	}
}

void ShowAllAccInfo(void)
{
	for (int i = 0; i < accNum; i++)
	{
		accArr[i]->ShowAccInfo();
		cout << endl;
		getchar(); getchar();
	}
}