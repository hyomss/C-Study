//	define multiple classes (Encalsulation)
#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	void Init(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
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
	void Init(int x, int y, int r)
	{
		rad = r;
		center.Init(x, y);
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
	void Init(int xx1, int yy1, int rr1, int xx2, int yy2, int rr2)
	{
		inner.Init(xx1, yy1, rr1);
		outter.Init(xx2, yy2, rr2);
	}
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
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}