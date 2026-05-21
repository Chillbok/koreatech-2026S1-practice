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
	bool operator!=(const Point& other) { return (this->x != other.x || this->y != other.y); }
	friend std::ostream& operator<<(std::ostream& os, const Point& other) {
		os << "[" << other.x << ", " << other.y << "]";
		return os;
	}
};

int main() {
	Point p1(1,2);
	Point p2(3,4);
	Point p3(0,0);
	p3 = p1 - p2;
	cout << "p1(1,2) - p2(3,4) = " << p3 << endl;
	
	p3 = p1 * p2;
	cout << "p1(1,2) * p2(3,4) = " << p3 << endl;
	
	p3 = p1 / p2;
	cout << "p1(1,2) / p2(3,4) = " << p3 << endl;
	
	if (p1 != p2) cout << "다르다!" << endl;
	else cout << "같다!" << endl;

	if (p2 != p3) cout << "다르다!" << endl;
	else cout << "같다!" << endl;

	return 0;
}