//	define class to save string
#include <iostream>
#include <string>
using namespace std;

class Printer
{
private:
	string str;
public:
	void SetString(string a);
	void ShowString();
};

void Printer::SetString(string a)
{
	str = a;
}
void Printer::ShowString()
{
	cout << str << endl;
}
int main()
{
	Printer pnt;
	pnt.SetString("Hello world!");
	pnt.ShowString();

	pnt.SetString("I love C++");
	pnt.ShowString();
	return 0;
}
