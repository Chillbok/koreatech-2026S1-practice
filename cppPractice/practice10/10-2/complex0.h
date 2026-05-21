#ifndef COMPLEX0_H
#define COMPLEX0_H
#include <iostream>
using std::cin; using std::cout; using std::endl;

class Complex {
private:
	float real = 0.0; // 숫자
	float imag = 0.0; // 복소수
public:
	Complex(float real, float imag);
	Complex();

	Complex operator+(const Complex& other) const;
	Complex operator+(const float n) const;
	friend Complex operator+(float n, const Complex& other);

	Complex operator*(const Complex& other) const;
	Complex operator*(const float n) const;
	friend Complex operator*(float n, const Complex& other);

	friend std::ostream& operator<<(std::ostream& os, const Complex& c);
	
	void show_number(bool is_complex_conjugate);
};
#endif
