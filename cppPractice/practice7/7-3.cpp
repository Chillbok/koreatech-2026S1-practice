#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <cstdlib>
#include <ctime>

class Dice {
private:
	int face;
public:
	int get_face() const {return face;}
	void roll() { face = rand() % 6 + 1; }
};

class Data {
private:
	int total;
	int count;
public:
	Data() {
		total = 0;
		count = 0;
	}
	void add_number(int n) {
		total += n;
		++count;
	}
	float get_average() { return total / count; }
};

int main() {
	srand((unsigned int)time(NULL));
	Dice d1;
	
	Data data;
	
	for (int i = 0; i < 10; ++i) {
		d1.roll();
		data.add_number(d1.get_face());
	}
	return 0;
}