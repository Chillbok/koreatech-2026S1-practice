#include "complex0.h"
#include <iostream>
using std::cin; using std::cout; using std::endl;

int main() {
	Complex a(3.0, 4.0);
	Complex c;
	cout << "하나의 복소수를 입력하세요(끝내려면 q): \n";
	while(cin >> c) {
		cout << "c= " << c << endl;
		cout << "공액복소수= " << ~c << endl;
		cout << "a = " << a << endl;
		cout << "a+c = " << a+c << endl;
		cout << "a-c = " << a-c << endl;
		cout << "a*c = " << a*c << endl;
		cout << "2*c = " << 2*c << endl;
		cout << "하나의 복소수를 입력하세요(끝내려면 q): \n";
	}
	cout << "프로그램을 종료합니다. \n";
	return 0;
}