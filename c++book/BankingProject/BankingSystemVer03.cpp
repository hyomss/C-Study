/*
Ellen Yoo
20190209
c++ Project */
//	Solution -> c/c++ preprocessor -> _CRT_SECURE_NO_WARININGS
//	오늘의 실수: 생성자가 있는데 이용하지 않고 MakeId 등의 함수를 또 만들었다 new Account(id, name, deposit)으로 동적할당하자!
#include <iostream>
#include <cstring>
using namespace std;
enum { _Open = 1, _Deposit, _Withdrawal, _Information, _Quit };

class Account
{
private:
	int id;
	char* name;
	int deposit;

public:
	Account(int id, char*name, int deposit)	//	Constructor
	{
		this->id = id;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->deposit = deposit;
	}

	int GetId() {
		return id;
	}
	void Deposit(int deposit) {
		this->deposit += deposit;
	}
	void MakeWithdrawal(int withdrawal) {
		if (this->deposit < withdrawal) {
			cout << "Low Balance" << endl;
			return;
		}
		this->deposit -= withdrawal;
		cout << "Success" << endl;
	}

	void Information()
	{
		cout << "ID : " << id << endl;
		cout << "Name : " << name << endl;
		cout << "balance : " << deposit << endl << endl;
	}

	~Account()	//	Destructor
	{
		delete[] name;
	}
};

Account *arrAcc[100];
int numofperson = 0;


void OpenAccount()
{
	int newid, newdeposit;
	char* newname = NULL;
	cout << "[ Open Account ]" << endl;
	while (1)
	{
		cout << "ID : ";
		cin >> newid;
		for (int i = 0; i <= numofperson; i++)
		{
			if (arrAcc[i]->GetId() == newid)
			{
				cout << "This ID already exists." << endl;
				break;
			}
			else
			{
				cout << "Available ID :)" << endl;
				cout << "NAME : ";
				cin >> newname;
				cout << "Deposit : ";
				cin >> newdeposit;
				arrAcc[numofperson++] = new Account(newid, newname, newdeposit);
				return;
			}
		}
	}


}

void Deposit()
{
	cout << "[ Deposit ]" << endl;

	int findid, newdeposit;
	cout << "ID : ";
	cin >> findid;
	cout << "Deposit : ";
	cin >> newdeposit;

	for (int i = 0; i < numofperson; i++)
	{
		if (arrAcc[i]->GetId() == findid)
		{
			arrAcc[i]->Deposit(newdeposit);
			cout << "Success" << endl;
			return;
		}
	}
	cout << "ID does not exist" << endl;
}

void Withdrawal()
{
	cout << "[ Withdrawal ]" << endl;

	int findid, newwithdrawal;
	cout << "ID : ";
	cin >> findid;
	cout << "Withdrawal : ";
	cin >> newwithdrawal;

	for (int i = 0; i < numofperson; i++)
	{
		if (arrAcc[i]->GetId() == findid)
		{
			arrAcc[i]->MakeWithdrawal(newwithdrawal);
			return;
		}
	}
	cout << "ID does not exist" << endl;
}



int main()
{

	while (1)
	{
		int choice;
		cout << "----- MENU-----" << endl;
		cout << "1. Open Account" << endl;
		cout << "2. Deposit     " << endl;
		cout << "3. Withdrawal  " << endl;
		cout << "4. All Account Information" << endl;
		cout << "5. Quit        " << endl << endl;

		cin >> choice;

		switch (choice)
		{
		case _Open:
			OpenAccount();
			break;
		case _Deposit:
			Deposit();
			break;
		case _Withdrawal:
			Withdrawal();
			break;
		case _Information:
			for (int i = 0; i < numofperson; i++) {
				arrAcc[i]->Information();
			}
			break;
		case _Quit:
			return 0;
		default:
			cout << "Enter Again" << endl;
		}
	}
	return 0;
}