#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <vector>
using std::vector;
#include <random>

class Dice {
private:
	int face;
	std::mt19937 gen;
	std::uniform_int_distribution<int> dis;
public:
	// 생성자
	Dice() : gen(std::random_device{}()), dis(1, 6), face(0) {};

	// 함수들
	int get_face() const {return face;};
	void roll() {face = dis(gen);};
};

int main() {
	int amount = 0;
	return 0;
}