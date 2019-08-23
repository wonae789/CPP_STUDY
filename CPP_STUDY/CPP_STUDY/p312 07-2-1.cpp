#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;


class Rectangle
{
private:
	int x;
	int y;
public:
	Rectangle(int n, int m) :x(n), y(m)
	{}

	void ShowAreaInfo() const
	{
		cout << "¸éÀû: " << x * y << endl;
	}
};

class Square : public Rectangle
{
public:
	Square(int n) :Rectangle(n,n)
	{}
};

int main(void)
{

	Rectangle rec(4, 3);
	rec.ShowAreaInfo();

	Square sqr(7);
	sqr.ShowAreaInfo();

	return 0;
}