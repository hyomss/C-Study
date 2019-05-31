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
	생성자는 객체 생성 시에 호출이 됩니다. 따라서 객채 생성과 동시에 초기화를 해주어야 하므로 이니셜라이저를 통한 초기화를 해주어야 합니다.
질문자 분께서 주석처리 하신 부분은
Point Center;
Center(x, y); 
위 두 줄과 그 의미가 같습니다.

그리고 SoSimple의 경우 num1 과 num2가 해당 객체 내에 있는 멤버변수가 아닌지요?
본 코드에서 에러가 나는 부분은 해당객체 내에서 다른 "객체"를 선언하고 초기화하는 부분이 문제가 되는거죠.
객체 생성 시 따로 정의한 생성자가 있는 경우 그 생성자를 바탕으로 초기화를 진행하죠.
(즉, 생성자를 따로 정의하지 않은 경우는 디폴트 생성자가 호출이 되지만, 따로 정의해준 경우는 디폴트 생성자를 호출하지 않습니다.)
여기서 한 가지 주목하셔야 하는 부분은 생성자의 호출시기입니다. 
생성자는 객체 선언 시 호출이 되는데, 주석과 같이 이니셜라이저로 초기화를 해주지 않고 함수몸체에서 객체를 초기화 해주는 코드를 구성하시면 
선언과 초기화가 따로 이루어지게 됩니다. 이 경우 선언 시에 아무 인자도 전달하지 않게되고 에러가 나는 것이죠.
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