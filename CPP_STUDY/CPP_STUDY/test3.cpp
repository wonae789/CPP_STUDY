#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;


namespace COMP_POS
{
	enum { CLERK,SENIOR,ASSIST,MANAGER };

	void ShowNameCardInfo(int pos)
	{
		switch (pos)
		{
		case CLERK:
			cout << "���" << endl;
			break;
		case SENIOR:
			cout << "����" << endl;
			break;
		case ASSIST:
			cout << "�븮" << endl;
			break;
		case MANAGER:
			cout << "����" << endl;
			break;
		}
	}
}

class NameCard
{
private:
	char *Name;
	char *CompanyName;
	char *Phone;
	int Position;
public:
	NameCard(char* name, char* company, char* phone, int pos)
		:Position(pos)



};

int main(void)
{
	NameCard manClerk("Lee", "ABCEng", "0102-3-4040", COMP_POS::CLERK);
}