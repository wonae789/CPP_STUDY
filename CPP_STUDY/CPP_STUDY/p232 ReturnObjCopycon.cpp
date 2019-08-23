#include <iostream>

using namespace std;

class Sosimple
{
private:
	int num;
public:
	Sosimple(int n) :num(n)
	{}
	Sosimple(const Sosimple& copy) :num(copy.num)
	{
		cout << "called Sosimple(const Sosimple& copy)" << endl;
	}

	Sosimple& AddNum(int n)
	{
		num += n;
		return *this;
	}

	void ShowData()
	{
		cout << "num : " << num << endl;
	}
};

Sosimple SimpleFunObj(Sosimple ob)
{
	cout << "return ÀÌÀü" << endl;
	return ob;
}



int main(void)
{
	Sosimple obj(7);
	SimpleFunObj(obj).AddNum(30).ShowData();
	obj.ShowData();
	return 0;
}