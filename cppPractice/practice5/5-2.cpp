#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <cmath>
#include <string>
using std::string;

class Point {
private:
    int x,y;
public:
    // 인공지능에게 질문하여 매개변수를 굳이 적지 않더라도 변수를 할당하는 방법을 찾았음.
    Point(int x_val = 0, int y_val = 0);
    void SetX(int value);
    void SetY(int value);
    int GetX();
    int GetY();
    void ShowData();
    double Distance(const Point &p1);
    int GetArea();
    int GetVolume();
    string GetName();
};

// 클래스 Point 함수들
Point::Point(int x_val, int y_val) { x = x_val, y = y_val; }

void Point::SetX(int value) { x = value; }

void Point::SetY(int value) { y = value; }

int Point::GetX() { return x; }

int Point::GetY() { return y; }

void Point::ShowData() { cout << "데이터 출력: (" << x << "," << y << ")" << endl; }

double Point::Distance(const Point &p1) {
    float x_dist_pow = std::pow(x - p1.x, 2);
    float y_dist_pow = std::pow(y - p1.y, 2);

    double d = std::sqrt(x_dist_pow + y_dist_pow);
    return d;
}

int Point::GetArea() { return 0; }

int Point::GetVolume() { return 0; }

string Point::GetName() { return "Point"; }

int main() {
    Point p1(1, 2);
    Point p2;
    p2.SetX(7);
    p2.SetY(8);
    cout << "=== Object Information ===" << endl;
    p1.ShowData();
    p2.ShowData();

    cout << "\n=== Member Function Test ===" << endl;
    cout << "Name of p1: " << p1.GetName() << endl;
    cout << "Area of p1: " << p1.GetArea() << endl;
    cout << "Volume of p1: " << p1.GetVolume() << endl;

    // 3. 두 점 사이의 거리 계산 (p1과 p2의 거리)
    double dist = p1.Distance(p2);

    cout << "\n=== Distance Result ===" << endl;
    cout << "Distance between p1(1, 2) and p2(7, 8): " << dist << endl;

    return 0;
}
