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
		cout << "�Ǹ� �ݾ��� ���� ������ �Է�(-1 to end): ";
		cin >> sell;

		if (sell == -1)	break;

		cout << "�̹� �� �޿�: " << base + sell * BONUS << "����" << endl;
	}

	return 0;
}