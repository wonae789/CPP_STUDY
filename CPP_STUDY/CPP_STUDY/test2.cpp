#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<cstring>
using namespace std;

char * MakeStrAdr(int len)
{
	char* asdf = new char[len];
	return asdf;
}


int main(void) 
{
	int a;
	scanf("%d", &a);
	char* str = MakeStrAdr(a);
	strcpy(str, "as2");
	cout << str[0] << endl;
	cout << str[1] << endl;
	cout << str[2] << endl;
	delete []str;
	return 0;

}