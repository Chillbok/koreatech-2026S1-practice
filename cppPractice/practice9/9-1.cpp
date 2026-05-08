#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;

static const float PI = 3.14;

class Point {
protected:
	int x;
	int y;
	string name;
public:
	Point(int added_x, int added_y) {
		name = "Point";
		x = added_x, y = added_y;
	}
	int GetX() { return x; }
	int GetY() { return y; }
	string GetName() { return name; }
	void ShowData();
};

void Point::ShowData() {
	cout << name << " = (" << x << "," << y << ")" << endl;
}

class Circle : public Point {
protected:
	float radius;
public:
	Circle(int added_x, int added_y);
	void SetRadius(float n) { radius = n; }
	float GetArea() { return PI * radius * radius; }
	float GetVolume() { return 0.0; }
	void ShowData();
};

Circle::Circle(int added_x, int added_y) : Point(added_x, added_y) {
	name = "Circle";
}

void Circle::ShowData() {
	cout << GetName() << " 중심=(" << GetX() << "," << GetY() << ")" << endl;
	cout << GetName() << " 반지름= " << radius << endl;
	cout << GetName() << " 면적 = " << GetArea() << endl;
	cout << GetName() << " 부피 = " << GetVolume() << endl;
}

class Sphere : public Circle {
public:
	Sphere(int added_x, int added_y, int added_radius);
	float GetArea() { return 4 * PI * radius * radius; }
	float GetVolume() { return (4 / 3) * PI * radius * radius * radius; }
	void ShowData();
};

Sphere::Sphere(int added_x, int added_y, int added_radius) : Circle(added_x, added_y) {
	radius = added_radius;
	name = "Sphere";
}

void Sphere::ShowData() {
	cout << GetName() << " 중심: (" << x << "," << y << ")" << endl;
	cout << GetName() << "반지름: " << radius << endl;
	cout << GetName() << " 표면적: " << GetArea() << endl;
	cout << GetName() << " 부피:" << GetVolume() << endl;
}

class Cylinder : public Circle {
private:
	float radius;
	int height;
public:
	Cylinder(int added_x, int added_y, float added_radius, int added_height);
	float GetArea();
	float GetVolume();
	void ShowData();
};

Cylinder::Cylinder(int added_x, int added_y, float added_radius, int added_height) : Circle::Circle(added_x, added_y) {
	name = "Cylinder";
	radius = added_radius;
	height = added_height;
}

float Cylinder::GetArea() { return 2 * PI * radius * radius + 2 * PI * radius * height; }

float Cylinder::GetVolume() { return PI * radius * radius * height; }

void Cylinder::ShowData() {
	cout << name << " 중심: (" << x << "," << y << ")" << endl;
	cout << name << " 반지름: " << radius << endl;
	cout << name << " 표면적: " << GetArea() << endl;
	cout << name << " 부피: " << GetVolume() << endl;
}

int main() {
	Point p1(1, 2);
	cout << "이름: " << p1.GetName() << endl;
	p1.ShowData();
	cout << endl;
	
	Circle c1(1, 2);
	c1.SetRadius(4.0);
	cout << "이름: " << c1.GetName() << endl;
	c1.ShowData();
	cout << endl;
	
	Sphere s1(1, 2, 4.0);
	cout << "이름: " << s1.GetName() << endl;
	s1.ShowData();
	cout << endl;
	
	Cylinder cy1(1, 2, 4.0, 7);
	cout << "이름: " << c1.GetName() << endl;
	c1.ShowData();
	cout << endl;
	return 0;
}