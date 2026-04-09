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
        // 인공지능에게 질문하여 값을 반환하지 않고 함수만 끝내는 법을 알게 되었음.
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
    try {
        result = cal.Div(10.0, 2.0);
        cout << "10.0 / 2.0 = " << result << endl;

        // 여기에서 throw가 발생하고, 즉시 catch로 이동
        result = cal.Div(5.0, 0); 
    }
    // throw로 던져진 문자열을 잡아서 출력
    catch (const char* msg) { cout << msg << endl; }

    cout << "-----------------------" << endl;
    cal.ShowCount();
    return 0;
}
