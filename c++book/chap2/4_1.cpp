//	c++ standard function 1
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char *a = "home";
	cout << strlen(a) << endl;
	
	char dest[10];
	strcat_s(dest, sizeof(dest), a);
	cout << dest << endl;

	strcpy_s(dest, sizeof(dest), a);
	cout << dest << endl;

	cout << strcmp(dest, a) << endl;
	
	
	
	
	
	
	return 0;
}
