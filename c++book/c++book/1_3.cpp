//	Enter a number and print multiple table of the number 
#include <iostream>
using namespace std;

int main()
{
	int input, ans;
	cout << "Enter an integer : ";
	cin >> input;

	for (int i = 1; i < 11; ++i)
	{
		cout << input << " * " << i << " = " << input*i << endl;
	}

	return 0;
}