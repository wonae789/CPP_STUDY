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
		cout << "���K������" << endl;
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
	cout << "��ü ���� ��" << endl;
	asdf sim2 = sim1;
	cout << "��ü ���� ��" << endl;
	sim2.Show();
	return 0;

}