//	input: user name, phone number -> output
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string name, number;
	cout << "Enter user name:\t";
	cin >> name;
	cout << "Enter user phone number:";
	cin >> number;

	cout << "Name:\t\t" << name << endl << "Phone number:\t" << number;

	return 0;
}