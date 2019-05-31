//	use reference to make two functions below
//	1. increase the value
//	2. change the sign
#include <iostream>
using namespace std;

void increase(int &val1, int &val2)
{
	val1++;
	val2++;
}

void changesign(int &val1, int &val2)
{
	val1 *= (-1);
	val2 *= (-1);
}

int main()
{
	int val1 = 10, val2 = 20;
	increase(val1, val2);
	changesign(val1, val2);
	cout << val1 << "  " << val2 << endl;
}