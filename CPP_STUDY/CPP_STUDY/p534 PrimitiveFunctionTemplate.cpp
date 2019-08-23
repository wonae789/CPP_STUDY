#include<iostream>
using namespace std;

template <class t1, class t2>
void ShowData(double num)
{
	cout << (t1)num << "," << (t2)num << endl;
}



int main(void)
{

	ShowData<char, int>(68);
	ShowData<char, double>(68.9);
	return 0;
}