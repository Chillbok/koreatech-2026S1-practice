#include "complex0.h"
#include <iostream>
using std::cin; using std::cout; using std::endl;

int main() {
	Complex c1(1.0, 2.0);
	Complex c2;
	Complex c3 = c1 + c2;

	cout << "c1: " << c1 << endl;
	cout << "c2: " << c2 << endl;
	cout << endl;
	cout << "c1 + c2: " << c3 << endl;

	cout << "(c1 + c2) + 1: " << c3 + 1 << endl;
	c3 = 1 + c3;
	cout << "1 + (c1 + c2): " << 1 + c3 << endl;
	cout << endl;

	c3 = c1 * c2;
	cout << "c1 * c2: " << c3 << endl;
	cout << "3 * (c1 * c2): " << 3 * c3 << endl;
	cout << "(c1 * c2) * 2: " << c3 * 2 << endl;
	return 0;
}