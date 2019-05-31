//	define multiple classes with user defined consturctor and destructor
#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x, int y)
		:xpos(x), ypos(y) {}
	void ShowPointInfo() const
	{
		cout << "[" << xpos << " , " << ypos << "]" << endl;
	}
};

class Circle
{
private:
	int rad;
	Point center;
public:
	//Circle(int x, int y, int r)
	//{
	//	rad = r;
	//	center(x, y);
	//}
	/*
	�����ڴ� ��ü ���� �ÿ� ȣ���� �˴ϴ�. ���� ��ä ������ ���ÿ� �ʱ�ȭ�� ���־�� �ϹǷ� �̴ϼȶ������� ���� �ʱ�ȭ�� ���־�� �մϴ�.
������ �в��� �ּ�ó�� �Ͻ� �κ���
Point Center;
Center(x, y); 
�� �� �ٰ� �� �ǹ̰� �����ϴ�.

�׸��� SoSimple�� ��� num1 �� num2�� �ش� ��ü ���� �ִ� ��������� �ƴ�����?
�� �ڵ忡�� ������ ���� �κ��� �ش簴ü ������ �ٸ� "��ü"�� �����ϰ� �ʱ�ȭ�ϴ� �κ��� ������ �Ǵ°���.
��ü ���� �� ���� ������ �����ڰ� �ִ� ��� �� �����ڸ� �������� �ʱ�ȭ�� ��������.
(��, �����ڸ� ���� �������� ���� ���� ����Ʈ �����ڰ� ȣ���� ������, ���� �������� ���� ����Ʈ �����ڸ� ȣ������ �ʽ��ϴ�.)
���⼭ �� ���� �ָ��ϼž� �ϴ� �κ��� �������� ȣ��ñ��Դϴ�. 
�����ڴ� ��ü ���� �� ȣ���� �Ǵµ�, �ּ��� ���� �̴ϼȶ������� �ʱ�ȭ�� ������ �ʰ� �Լ���ü���� ��ü�� �ʱ�ȭ ���ִ� �ڵ带 �����Ͻø� 
����� �ʱ�ȭ�� ���� �̷������ �˴ϴ�. �� ��� ���� �ÿ� �ƹ� ���ڵ� �������� �ʰԵǰ� ������ ���� ������.
	*/
	Circle(int x, int y, int r)	: center(x,y)
	{
		rad = r;
	}

	void ShowCircleInfo() const
	{
		cout << "radious : " << rad << endl;
		center.ShowPointInfo();
	}
};

class Ring
{
private:
	Circle inner;
	Circle outter;
public:
	Ring(int xx1, int yy1, int rr1, int xx2, int yy2, int rr2)
		:inner(xx1, yy1, rr1), outter(xx2, yy2, rr2)
	{}
	void ShowRingInfo()
	{
		cout << "Inner circle information..." << endl;
		inner.ShowCircleInfo();

		cout << "Outter circle information..." << endl;
		outter.ShowCircleInfo();
	}
};

int main()
{
	Ring ring(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}