//	get 5 integer inputs from the user and print the sum
#include <iostream>
using namespace std;

int main()
{/*
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	
	cout << a + b + c + d + e << endl;
	
	return 0;*/

	
	int num = 0;
	int input;

	cout << "Enter 5 integets: ";
	for (int i = 0; i < 5; ++i)
	{
		cin >> input;
		num += input;
	}
	cout << "sum: " << num;

	return 0;

}