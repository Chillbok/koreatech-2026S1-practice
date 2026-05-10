#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <cstdlib>
#include <typeinfo>
#include <ctime>
#include <vector>
using std::vector;

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

Shape *generator(vector<int>& counts) {
	switch(rand() % 4) {
		case 0:
			counts[0]++;
			return new Line;
		case 1:
			counts[1]++;
			return new Rectangle;
		case 2:
			counts[2]++;
			return new Triangle;
		case 3:
			counts[3]++;
			return new NullShape;
	}
	return NULL;
}

int main() {
	srand(static_cast<unsigned int>(time(0)));
	Shape *p;
	
	int max_count = 10;

	vector<int> shape_counts(4);
	for (int& x : shape_counts) x = 0;
	
	cout << "=== " << max_count << "개의 Shape 생성을 시작합니다 ===" << endl << endl;
	for (int i = 0; i < max_count; ++i) {
		p = generator(shape_counts);
		cout << "[" << i + 1 << "번째 생성 객체: class " << typeid(*p).name() << endl;
		p->draw();
		cout << "--------------------------------------" << endl;
	}

	delete p;
	
	for (int i = 0; i < shape_counts.size(); ++i) cout << shape_counts[i] << endl;

	return 0;
}