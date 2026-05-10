#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <cstdlib>
#include <typeinfo>
#include <ctime>

class Shape {
public:
	virtual void draw() {}
};

class Rectangle : public Shape {
public:
	void draw() {
		cout << "*****" << endl;
		for (int i = 0; i < 2; ++i) cout << "*   *" << endl;
		cout << "*****" << endl;
	}
};

class Triangle : public Shape {
public:
	void draw() {
		cout << "  *" << endl;
		cout << " * *" << endl;
		cout << "*****" << endl;
	}
};

class Line : public Shape {
public:
	void draw() {
		cout << "********\n\n";
	}
};

class NullShape : public Shape {
public:
	void draw() {}
};

Shape *generator() {
	srand(static_cast<unsigned int>(time(0)));

	switch(rand() % 4) {
		case 0:
			return new Line;
		case 1:
			return new Rectangle;
		case 2:
			return new Triangle;
		case 3:
			return new NullShape;
	}
	return NULL;
}

int main() {
	int i;
	Shape *p;
	
	p = generator();

	cout << typeid(*p).name() << endl;
	p->draw();

	delete p;

	return 0;
}