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

int main() {
	srand((unsigned int)time(NULL));
	Dice d1;
	for (int i = 0; i < 100; ++i) {
		d1.roll();
		if (d1.get_face() <= 0 || d1.get_face() >= 7) cout << endl << "1부터 6 사이가 아닌 수가 출력됨." << endl;
		cout << d1.get_face() << " ";
	}
	cout << endl;
	return 0;
}