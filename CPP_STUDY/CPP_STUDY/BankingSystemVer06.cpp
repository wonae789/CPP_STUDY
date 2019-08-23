#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class A {
public:
	void a() {
		cout << "a()" << endl;
	}
};

class B : public A {
public:
	void b() {
		cout << "b()" << endl;
	}
};

class C : public B {
public:
	void c() {
		cout << "c()" << endl;
	}
};

int main(void)
{
	C* c = new C();
	c->a();
	c->b();
	c->c();
	return 0;
}