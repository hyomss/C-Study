//	swap pointer
#include <iostream>
using namespace std;

void swappointer(int *(&ptr1), int *(&ptr2))
{
	int * temp = ptr2;
	ptr2 = ptr1;
	ptr1 = temp;
}

int main()
{
	int num1 = 5;
	int *ptr1 = &num1;
	int num2 = 10;
	int *ptr2 = &num2;
	cout << *ptr1 << " " << *ptr2 << endl;	//	5 10

	swappointer(ptr1, ptr2);
	cout << *ptr1 << " " << *ptr2 << endl;	//	10 5

	return 0;
}