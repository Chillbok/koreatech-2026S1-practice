#include <iostream>
using std::cin; using std::cout; using std::endl;

const double PI = 3.14;

// 원 면적 출력
double calculateArea(double radius) {
    return PI * radius * radius;
}

// 삼각형 면적 출력
double calculateArea(double base, double height) {
    return base * height / 2;
}

// 정사각형 면적 출력
int calculateArea(int width, int height=-1) {
    return width * width;
}

int main() {
    cout << "반지름 5.0인 원: " << calculateArea(5.0) << endl;
    cout << "밑변 4.0, 높이 3.0인 삼각형: " << calculateArea(4.0, 3.0) << endl;
    cout << "가로 10, 세로 5인 직사각형: " << calculateArea(10, 5) << endl;
    cout << "한 변이 10인 정사각형: " << calculateArea(10) << endl;
    return 0;
}