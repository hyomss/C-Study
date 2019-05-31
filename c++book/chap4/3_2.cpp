//	define NameCard class with user defined constructor and destructor
#include <iostream>
#include <string>
using namespace std;

namespace POSITION
{
	enum
	{
		CLERK, SENIOR, ASSIST, MANAGER
	};
	void showPosInfo(int pos) 
	{
		switch (pos)
		{
		case CLERK:
			cout << "Clerk" << endl;
			break;
		case SENIOR:
			cout << "Senior" << endl;
			break;
		case ASSIST:
			cout << "Assist" << endl;
			break;
		case MANAGER:
			cout << "Manager" << endl;
			break;
		default:
			break;
		}
	}
}

class NameCard
{
private:
	string *name;
	string *company;
	string *phone;
	int position;
public:
	NameCard(string myname, string mycompany, string myphone, int myposition)
		:position(myposition)
	{
		name = new string(myname);
		company = new string(mycompany);
		phone = new string(myphone);
	}
	void showInfo()
	{
		cout << "Name : \t\t" << *name << endl;
		cout << "Company : \t" << *company << endl;
		cout << "Phone : \t" << *phone << endl;
		cout << "Position : \t"; POSITION::showPosInfo(position); cout << endl;
	}

	~NameCard()
	{
		delete name;
		delete company;
		delete phone;
	}
};


int main()
{
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", POSITION::CLERK);
	NameCard manSenior("hong", "OrangeEng", "010-3333-4444", POSITION::SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", POSITION::ASSIST);
	manClerk.showInfo();
	manSenior.showInfo();
	manAssist.showInfo();
	return 0;
}


