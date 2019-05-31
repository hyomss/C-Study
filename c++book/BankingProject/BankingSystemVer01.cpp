/*
Ellen Yoo
20190121 
c++ Project ver1*/

#include <iostream>
#include <string>
using namespace std;
enum { _Open = 1, _Deposit, _Withdrawal, _Information, _Quit };
int numofperson = 0;

typedef struct _Person
{
	int id;
	string name;
	int deposit;
} Person;
Person arr[100];


void OpenAccount()
{
	int newid;
	cout << "[ Open Account ]" << endl;
	while (1)
	{
		cout << "ID : ";
		cin >> newid;
		for (int i = 0; i <= numofperson; i++)
		{
			if (arr[i].id == newid)
			{
				cout << "This ID already exists." << endl;
				break;
			}
			else
			{
				cout << "Available ID :)" << endl;
				arr[numofperson].id = newid;
				cout << "NAME : ";
				cin >> arr[numofperson].name;
				cout << "Deposit : ";
				cin >> arr[numofperson].deposit;
				numofperson++;
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
		if (arr[i].id == findid)
		{
			arr[i].deposit += newdeposit;
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
		if (arr[i].id == findid)
		{
			if (arr[i].deposit < newwithdrawal)
			{
				cout << "Low Balance" << endl;
				return;
			}
			arr[i].deposit -= newwithdrawal;
			cout << "Success" << endl;
			return;
		}
	}
	cout << "ID does not exist" << endl;
}

void Information()
{
	for (int i = 0; i < numofperson; i++)
	{
		cout << "ID : " << arr[i].id << endl;
		cout << "Name : " << arr[i].name << endl;
		cout << "balance : " << arr[i].deposit << endl << endl;
	}
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
			Information();
			break;
		case _Quit:
			return 0;
		default:
			cout << "Enter Again" << endl;
		}
	}
	return 0;
}