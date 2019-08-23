#include <iostream>

using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	void Init(int x, int y)
	{
		xpos = x;
		ypos = y;
	}

	void ShowPointInfo() const
	{
		cout << "[" << xpos << "," << ypos << "]" << endl;
	}
};

class Circle
{
private:
	int rad; // 반지름
	Point center; // 원의 중심
public:
	void Init(int x, int y, int r)
	{
		rad = r; // 반지름
		center.Init(x, y);
	}
	void ShowCircleInfo() const
	{
		cout << "radius : " << rad << endl;
		center.ShowPointInfo();
	}
};

class Ring
{
private:
	Circle in;
	Circle out;
public:
	void Init(int inx, int iny, int inr, int outx, int outy, int outr)
	{
		in.Init(inx, iny, inr);
		out.Init(outx, outy, outr);
	}

	void ShowRingInfo() const
	{
		cout << "inner circle info.." << endl;
		in.ShowCircleInfo();
		cout << "out circle info.." << endl;
		out.ShowCircleInfo();
	}


};

int main(void)
{
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}