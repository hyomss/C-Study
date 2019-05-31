//	copy constructor for deep copy
//	define NameCard class with user defined constructor and destructor
#define _CRT_SECURE_NO_WARNINGS	//	이건 <iostream>위에다가 넣을 것!
#include <iostream>
#include <cstring>
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
	char *name;
	char *company;
	char *phone;
	int position;
public:
	NameCard(char* name, char* company, char* phone, int position)
		:position(position)
	{
		this->name = new char[strlen(name) + 1];
		this->company = new char[strlen(company) + 1];
		this->phone = new char[strlen(phone) + 1];
		strcpy(this->name,  name);
		strcpy(this->company, company);
		strcpy(this->phone, phone);
	}

	NameCard(const NameCard& ref)
		:position(ref.position)
	{
		this->name = new char[strlen(ref.name) + 1];
		this->company = new char[strlen(ref.company) + 1];
		this->phone = new char[strlen(ref.phone) + 1];
		strcpy(this->name,  ref.name);
		strcpy(this->company, ref.company);
		strcpy(this->phone,ref.phone);
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
		delete[] name;
		delete[] company;
		delete[] phone;
	}
};


int main()
{
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", POSITION::CLERK);
	NameCard copy1 = manClerk;
	NameCard manSenior("hong", "OrangeEng", "010-3333-4444", POSITION::SENIOR);
	NameCard copy2 = manSenior;
	copy1.showInfo();
	copy2.showInfo();
	return 0;
}


