#include "complex0.h"
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <string>
using std::string;

Complex::Complex(float real, float imag) : real(real), imag(imag) {}

Complex::Complex() {
	cout << "하나의 복소수를 입력하세요(끝내려면 q): " << endl;
	string input;

	cout << "실수부: ";
	cin >> input;
	if (input == "q") return;
	real = std::stof(input);
	
	cout << "허수부: ";
	cin >> input;
	if (input == "q") return;
	imag = std::stof(input);
	show_number(true);
}

// 복소수 + 복소수
Complex Complex::operator+(const Complex& other) const { return Complex(real + other.real, imag + other.imag); }

// 복소수 + 숫자
Complex Complex::operator+(const float n) const { return Complex(real + n, imag); }

// 숫자 + 복소수
Complex operator+(float n, const Complex& other) { return Complex(n + other.real, other.imag); }

std::ostream& operator<<(std::ostream& os, const Complex& c) {
	if (c.imag < 0) os << c.real << " - " << -1 * c.imag << "i";
	else os << c.real << " + " << c.imag << "i";
	return os;
}

std::istream& operator>>(std::istream& is, Complex& c) {
	cout << "실수부: ";
	cin >> c.real;
	cout << "허수부: ";
	cin >> c.imag;
	return is;
}

//복소수 x 복소수
Complex Complex::operator*(const Complex& other) const {
	float new_real = this->real * other.real - (this->imag * other.imag);
	float new_imag = this->real * other.imag + this->imag * other.real;
	return Complex(new_real, new_imag);
}

// 복소수 * float
Complex Complex::operator*(const float n) const {
	float new_real = this->real * n;
	float new_imag = this->imag * n;
	return Complex(new_real, new_imag);
}

// 일반 숫자 * 복소수
Complex operator*(float n, const Complex& other) {
	float new_real = n * other.real;
	float new_imag = n * other.imag;
	return Complex(new_real, new_imag);
}

void Complex::show_number(bool is_complex_conjugate) {
	if (is_complex_conjugate == true) {
		cout << "공액 복소수: ";
		cout << "(" << real << ", " << -1 * imag << "i)" << endl;
	}
	else {
		cout << "복소수: ";
		cout << "(" << real << ", " << imag << "i)" << endl;
	}
}