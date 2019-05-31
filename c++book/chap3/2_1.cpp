//	define class for a calculator
#include <iostream>
using namespace std;

class Calculator
{
private:
	int addcnt;
	int divcnt;
	int mincnt;
	int mulcnt;

public:
	void Init();
	double Add(double a, double b);
	double Div(double a, double b);
	double Min(double a, double b);
	double Mul(double a, double b);
	void ShowOpCount();
};

void Calculator::Init()
{
	addcnt = 0;
	divcnt = 0;
	mincnt = 0;
	mulcnt = 0;
}
double Calculator::Add(double a, double b)
{
	addcnt++;
	return a + b;
}
double Calculator::Div(double a, double b)
{
	divcnt++;
	return a / b;

}
double Calculator::Min(double a, double b)
{
	mincnt++;
	return a - b;
}
double Calculator::Mul(double a, double b)
{
	mulcnt++;
	return a * b;
}

void Calculator::ShowOpCount()
{
	cout << "Addition \t: " << addcnt << endl;
	cout << "Division \t: " << divcnt << endl;
	cout << "Subtraction \t: " << mincnt << endl;
	cout << "Multiplication \t: " << mulcnt << endl;
}
int main()
{
	Calculator cal;
	cal.Init();
	cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
	cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
	cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
	cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;

	cal.ShowOpCount();

	return 0;
}