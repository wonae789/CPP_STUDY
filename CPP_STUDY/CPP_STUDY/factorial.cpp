#include<iostream>
using namespace std;



int factorial(int a)
{
	if (a == 1)
		return 1;
	return a* factorial(a - 1);
	
}



int main(void)
{
	int a = 5;
	cout << factorial(a) << endl;
	return 0;
}