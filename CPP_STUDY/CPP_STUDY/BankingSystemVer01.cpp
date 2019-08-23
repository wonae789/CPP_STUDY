#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring> // strcpy 사용

#include <cstdlib> // system("cls") 사용
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
	int accID; //계좌번호;
	char cusName[NAME_LEN]; // 고객이름
	int balance; // 잔액;
}Account;

Account accArr[100]; // Account 저장을 위한 배열
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
			break;
		default:
			cout << "잘못 입력하셨습니다.." << endl;
			getchar();
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

	accArr[accNum].accID = id;
	accArr[accNum].balance = balance;
	strcpy(accArr[accNum].cusName, name);
	accNum++;
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
		if (accArr[i].accID == id)
		{
			accArr[i].balance += money;
			cout << "입금완료" << endl;
			getchar();
			return;
		}
		cout << "유효하지 않은 ID 입니다." << endl << endl;
		getchar();
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
		if (accArr[i].accID == id)
		{
			accArr[i].balance -= money;
			cout << "출금 완료" << endl;
			getchar();
			return;
		}
		cout << "유효하지 않은 ID 입니다." << endl << endl;
		getchar();

	}
}
void ShowAllAccInfo(void)
{
	for (int i = 0; i < accNum; i++)
	{
		cout << "------------------" << endl;
		cout << "계좌ID : " << accArr[i].accID << endl;
		cout << "고객 이름 : " << accArr[i].cusName << endl;
		cout << "잔액 : " << accArr[i].balance << endl;
		cout << "------------------" << endl;
	}
	getchar();
}