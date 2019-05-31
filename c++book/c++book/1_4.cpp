//	Salary calculator
#include <iostream>
#define BONUS 0.12
using namespace std;

int main()
{
	int base = 50;
	int sell;

	while (1)
	{
		cout << "판매 금액을 만원 단위로 입력(-1 to end): ";
		cin >> sell;

		if (sell == -1)	break;

		cout << "이번 달 급여: " << base + sell * BONUS << "만원" << endl;
	}

	return 0;
}