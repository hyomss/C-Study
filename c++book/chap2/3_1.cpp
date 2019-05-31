//	new & delete of structure
#include <iostream>
using namespace std;

typedef struct __Point
{
	int xpos;
	int ypos;
} Point;

Point& PntAdder(const Point &p1, const Point &p2)
{
	Point *pnew = new Point;
	pnew->xpos = p1.xpos + p2.xpos;
	pnew->ypos = p1.ypos + p2.ypos;

	return *pnew;
}

int main()
{
	Point *p1 = new Point;
	p1->xpos = 1;
	p1->ypos = 1;
	Point *p2 = new Point;
	p2->xpos = 2;
	p2->ypos = 2;

	Point &p3 = PntAdder(*p1, *p2);
	cout << p3.xpos << " " << p3.ypos << endl;

	delete p1;
	delete p2;
	delete &p3;


	return 0;
}