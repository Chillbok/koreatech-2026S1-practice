#include <iostream>
using std::cin; using std::cout; using std::endl;

class Calculator {
private:
    int count;
public:
    Calculator() { count = 0; }
    float Add(float a, float b) { ++count; return a + b; }
    float Sub(float a, float b) { ++count; return a - b; }
    float Mul(float a, float b) { ++count; return a * b; }
    float Div(float a, float b) {
        if (b == 0) throw "[에러] 0으로 나눌 수 없습니다!";
        ++count;
        return a / b;
    }
    void ShowCount() { cout << "지금까지 총 " << count << " 번의 연산이 수행되었습니다." << endl; }
};

int main() {
    Calculator cal;
    cout << "--- 계산기 작동 시작 ---" << endl;

    double result;
    result = cal.Add(10.5, 20.7);
    cout << "10.5 + 20.7 = " << result << endl;
    result = cal.Sub(15.0, 7.5);
    cout << "15.0 - 7.5 = " << result << endl;
    result = cal.Mul(4.0, 5.0);
    cout << "4.0 * 5.0 = " << result << endl;
    result = cal.Div(10.0, 2.0);
    cout << "10.0 / 2.0 = " << result << endl;
    result = cal.Div(5.0, 0); 

    cout << "-----------------------" << endl;
    cal.ShowCount();
    return 0;
}
