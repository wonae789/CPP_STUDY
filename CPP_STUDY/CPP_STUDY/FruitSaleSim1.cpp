#include <iostream>

using namespace std;

class FruitSeller
{
private:
	int APPlE_PRICE;
	int numOfApples;
	int myMoney;
public:
	void InitMembers(int price, int num, int money)
	{
		APPlE_PRICE = price;
		numOfApples = num;
		myMoney = money;
	}

	int SaleApples(int money)
	{
		int num = money / APPlE_PRICE;
		numOfApples -= num;
		myMoney += money;
		return num;
	}

	void ShowSalesResult()
	{
		cout << "���� ��� : " << numOfApples << endl;
		cout << "���� ���� : " << myMoney << endl << endl;
	}
};

class FruitBuyer
{
private:
	int myMoney;
	int numOfApples;
public:
	void InitMembers(int money)
	{
		myMoney = money;
		numOfApples = 0;
	}
	void BuyApples(FruitSeller& asdf, int money)
	{
		numOfApples += asdf.SaleApples(money);//�߿�
		myMoney -= money;
	}

	void ShowBuyResult()
	{
		cout << "���� �ܾ� : " << myMoney << endl;
		cout << "��� ���� : " << numOfApples << endl << endl;
	}
};



int main(void)
{
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);

	buyer.BuyApples(seller,2000); // ���� ����

	cout << "���� �Ǹ����� ��Ȳ" << endl;
	seller.ShowSalesResult();
	cout << "���� �������� ��Ȳ" << endl;
	buyer.ShowBuyResult();
	return 0;
}