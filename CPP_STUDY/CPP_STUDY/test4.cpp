#include<iostream>

using namespace std;

class asdf
{
private : 
	int num1;
	int num2;
public:
	asdf(int n1,int n2) :num1(n1),num2(n2)
	{
		cout << "11111111111111111" << endl;
	}


	asdf(const asdf& ref) :num1(ref.num1), num2(ref.num2)
	{
		cout << "하핳하하하" << endl;
	}
	void Show() const
	{
		cout << num1 << endl;
		cout << num2 << endl;

	}
};


int main(void)
{
	asdf sim1(15, 30);
	cout << "객체 생성 전" << endl;
	asdf sim2 = sim1;
	cout << "객체 생성 후" << endl;
	sim2.Show();
	return 0;

}