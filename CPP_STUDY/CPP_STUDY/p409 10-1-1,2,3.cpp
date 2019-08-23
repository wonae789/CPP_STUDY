#include <iostream>
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

	Point& operator+=(const Point& ref) // ����2
	{
		xpos += ref.xpos;
		ypos += ref.ypos;
		return *this;
	}

	Point& operator-=(const Point& ref) // ����2
	{
		xpos -= ref.xpos;
		ypos -= ref.ypos;
		return *this;
	}

	friend Point operator-(const Point& pos1, const Point& pos2);// ����1
	friend bool operator==(const Point& , const Point& );// ����3
	friend bool operator!=(const Point&, const Point&);// ����3



};


Point operator-(const Point& pos1, const Point& pos2) // ����1
{
	Point pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
	return pos;
}

bool operator==(const Point& pos2, const Point& pos3) // ����3
{
	if (pos2.xpos == pos3.xpos && pos2.ypos == pos3.ypos)
		return true;
	else
		return false;
}
bool operator!=(const Point& pos2, const Point& pos3) // ����3
{
	return !(pos2 == pos3);
}



int main(void)
{
	Point pos1(20, 30); 
	Point pos2(5,7); 
	Point pos3(5,7);



	(pos1 - pos2).ShowPosition(); // ����1
	(pos1 += pos2).ShowPosition(); // ����2
	(pos1 -= pos2).ShowPosition(); // ����2

	if (pos2 == pos3)
		cout << "equal" << endl;
	else
		cout << "not equal" << endl;

	if (pos2 != pos3)
		cout << "not equal" << endl;
	else
		cout << "equal" << endl;


}
