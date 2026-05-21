#include <iostream>
using std::cin; using std::cout; using std::endl;

class Point {
private:
	int x = 0;
	int y = 0;
public:
	Point(int x, int y) : x(x), y(y) {}
	Point operator-(const Point& other) {
		int new_x = this->x - other.x;
		int new_y = this->y - other.y;
		return Point(new_x, new_y);
	}
	Point operator+(const Point& other) {
		int new_x = this->x + other.x;
		int new_y = this->y + other.y;
		return Point(new_x, new_y);
	}
	Point operator*(const Point& other) {
		int new_x = this->x * other.x;
		int new_y = this->y * other.y;
		return Point(new_x, new_y);
	}
	Point operator/(const Point& other) {
		int new_x = this->x / other.x;
		int new_y = this->y / other.y;
		return Point(new_x, new_y);
	}
	void show() {
		cout << "(" << x << "," << y << ")" << endl;
	}
};

int main() {
	Point p1(4, 4), p2(2, 2), p_minus(0,0), p_plus(0,0), p_multiply(0,0), p_divide(0,0);
	
	p_minus = p1-p2;
	p_minus.show();
	p_plus = p1+p2;
	p_plus.show();
	p_multiply = p1 * p2;
	p_multiply.show();
	p_divide = p1 / p2;
	p_divide.show();
	return 0;
}