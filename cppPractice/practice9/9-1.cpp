#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;

static const float PI = 3.14;

class Point {
private:
	int x;
	int y;
	string name;
public:
	Point(int added_x, int added_y) { name = "Point", x = added_x, y = added_y; }
	int GetX() { return x; }
	int GetY() { return y; }
	string GetName() { return name; }
	void ShowData();
};

void Point::ShowData() {
	cout << "Point = (" << x << "," << y << ")" << endl;
}

int main() {
	Point p1(1, 2);
	cout << "이름: " << p1.GetName() << endl;
	p1.ShowData();
	cout << endl;
	return 0;
}