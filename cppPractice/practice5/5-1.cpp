#include <iostream>
using std::cin; using std::cout; using std::endl;

class Rectangle {
private:
    int x, y, height, width;

public:
    void Set_XY(int x_val, int y_val);
    void Set_HWidth(int height_val, int width_val);
    int Get_Area();
    int Get_Peripheral();
    void Display();
    bool Area_Compare(Rectangle &r);
};

void Rectangle::Set_XY(int x_val, int y_val) { x = x_val, y = y_val; }

void Rectangle::Set_HWidth(int height_val, int width_val) { height = height_val, width = width_val; }

int Rectangle::Get_Area() { return height * width; }

int Rectangle::Get_Peripheral() { return height * 2 + width * 2; }

void Rectangle::Display() { cout << "사각형의 시작좌표는 (" << x << "," << y << ")이고, Height와 Width는 (" << height << "," << width << ")" << endl; }

bool Rectangle::Area_Compare(Rectangle &r) {
    int r_area = r.Get_Area();
    int this_area = Get_Area();
    if (this_area >= r_area) return 1;
    else return 0;
}

int main() {
    bool b;
    Rectangle r1, r2;

    r1.Set_XY(3, 4);
    r1.Set_HWidth(4, 5);

    r2.Set_XY(5, 5);
    r2.Set_HWidth(4, 5);
    
    r1.Display();
    cout << "사각형 r1의 면적: " << r1.Get_Area() << endl;
    cout << "사각형 r1의 주변길이: " << r1.Get_Peripheral() << endl;

    r2.Display();
    cout << "사각형 r2의 면적: " << r2.Get_Area() << endl;
    cout << "사각형 r2의 주변길이: " << r2.Get_Peripheral() << endl;

    b = r1.Area_Compare(r2);
    if (b == 1) cout << "사각형 r1의 면적이 r2의 면적보다 크거나 같다." << endl;
    else cout << "사각형 r2의 면적이 r1의 면적보다 크다." << endl;

    return 0;
}