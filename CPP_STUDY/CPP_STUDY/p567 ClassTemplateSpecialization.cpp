#include<iostream>
using namespace std;

template <class T>
class Point
{
private:
	T xpos, ypos;
public:
	Point(T x = 0, T y = 0);
	void ShowPosition() const;

};


template <class T>
Point<T>::Point(T x, T y) :xpos(x), ypos(y)
{}


template <class T>
void Point<T>::ShowPosition() const
{
	cout << "[" << xpos << "," << ypos << "]" << endl;
}



int main(void)
{
	Point<int> pos1(3, 4);
	pos1.ShowPosition();


	Point<double> pos2(3.1, 4.1);
	pos2.ShowPosition();

	Point<char> pos3('f', 'b');
	pos3.ShowPosition();



	return 0;
}