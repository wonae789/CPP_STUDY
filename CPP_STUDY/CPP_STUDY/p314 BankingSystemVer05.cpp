#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring> // strcpy 사용

using namespace std;
const int NAME_LEN = 20;

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };


class Account
{
private:
	int accID; //계좌번호;
	int balance; // 잔액;
	char* cusName; // 고객이름
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
	cout << "계좌ID : " << accID << endl;
	cout << "고객 이름 : " << cusName << endl;
	cout << "잔액 : " << balance << endl;
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
	Account* accArr[100]; // Account 포인터 배열
	int accNum; // 저장된 Account 수
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
	cout << "1. 계좌개설" << endl;
	cout << "2. 입 금" << endl;
	cout << "3. 출 금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "----------------" << endl;
}

void AccountHandler::MakeAccount(void)
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

void AccountHandler::DepositMoney(void)
{
	int money;
	int id;
	cout << "[입 금]" << endl;
	cout << "계좌ID : "; cin >> id;
	cout << "입금액 : "; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->accIDGetAccID() == id)
		{
			accArr[i]->DepositMoney(money);
			cout << "입금완료" << endl;
			getchar();
			return;
		}
		cout << "유효하지 않은 ID 입니다." << endl << endl;
		getchar();
	}
}

void AccountHandler::WithdrawMoney(void)
{
	int money;
	int id;
	cout << "[출 금]" << endl;
	cout << "계좌ID : "; cin >> id;
	cout << "출금액 : "; cin >> money;
	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->accIDGetAccID() == id)
		{
			if (accArr[i]->WithdrawMoney(money) == 0)
			{
				cout << "출금 금액이 부족합니다." << endl;
				return;
			}
			cout << "출금 완료" << endl;
			getchar();
			return;
		}
		cout << "유효하지 않은 ID 입니다." << endl << endl;
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
		cout << "선택 : ";
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
			cout << "잘못 입력하셨습니다.." << endl;
			getchar();
		}
	}
	return 0;
}