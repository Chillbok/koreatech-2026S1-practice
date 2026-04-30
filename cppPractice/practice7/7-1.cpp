#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <vector>
using std::vector;

struct Point {
	int x;
	int y;
	Point(int n1, int n2) { x = n1; y = n2};
};

class Rectangle {
private:
	Point leftupper;
	Point rightdown;
	int width;
	int height;
public:
	Rectangle(const Rectangle& other);
	Rectangle(Point point_1, Point point_2);
	void Center();
	void Display();
};

Rectangle::Rectangle(const Rectangle& other) {
	leftupper = other.leftupper;
	rightdown = other.rightdown;
	width = other.width;
	height = other.height;
}

Rectangle::Rectangle(Point point_1, Point point_2) {
	leftupper = point_1; rightdown = point_2;
	width = rightdown.x - leftupper.x;
	height = leftupper.y - rightdown.y;
}

void Rectangle::Center() {
	float x_center = (rightdown.x + leftupper.x) / 2;
	float y_center = (leftupper.y + rightdown.y) / 2;

	cout << "사각형의 중심 좌표는 (" << x_center << "," << y_center << ") 입니다." << endl;
}

void Rectangle::Display() {
	int area = width * height;
	int full_length = 2 * width + 2 * height;
	
	cout << "사각형의 넓이는 " << area << "이고, 둘레는 " << full_length << "입니다." << endl;
}

int main() {
	Point p1(10, 10);
	Point p2(20, 20);
	return 0;
}