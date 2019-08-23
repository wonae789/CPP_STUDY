
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS	
using namespace std;



class Point
{
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y)
	{}
	void ShowPosition() const
	{
		cout << "[" << xpos << "," << ypos << "]" << endl;
	}


	Point& operator-()
	{
		xpos += (-2 * xpos);
		ypos += (-2 * ypos);

		return *this;
	}


	friend Point operator~(const Point& ref);
	//friend Point& operator-(Point& ref);
};


Point operator~(const Point& ref)
{
	Point pos(ref.ypos, ref.xpos);
	return pos;
}


//
//Point& operator-(Point& ref)
//{
//	ref.xpos += (-2 * ref.xpos);
//	ref.ypos += (-2 * ref.ypos);
//	return ref;
//}



int main(void)
{
	Point pos1(10, 20);
	pos1.ShowPosition();

	Point pos2= -pos1;
	pos2.ShowPosition();

	(~pos2).ShowPosition();

	return 0;
}