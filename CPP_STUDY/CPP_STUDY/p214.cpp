#include<iostream>

using namespace std;


class Sosimple
{
private:
	int num1, num2;
public:
	Sosimple(int n1, int n2) 
		: num1(n1), num2(n2)
	{}

	Sosimple(const Sosimple &copy)
		:num1(-copy.num1+15),num2(copy.num2)
	{
		cout << "called sosimple(sosimple &copy)" << endl;
	}
	void ShowSimpleData()
	{
		cout << num1 << endl;
		cout << num2 << endl;

	}

};


int main(void)
{
	Sosimple sim1(15, 30);
	cout << "생성 및 초기화 직전" << endl;
	Sosimple sim2 = sim1;
	cout << "생성 및 초기화 직후" << endl;
	sim2.ShowSimpleData();

	return 0;
}