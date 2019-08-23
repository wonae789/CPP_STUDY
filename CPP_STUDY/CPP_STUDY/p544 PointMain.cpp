#include<iostream>
#include"p544 PointTemplate.h"
#include"p544 PointTemplate.cpp"
using namespace std;



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