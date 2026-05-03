#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <cstdlib>
#include <ctime>
#include <vector>
using std::vector;

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
	vector<int> dice_face_count;
public:
	Data() {
		total = 0;
		count = 0;
		for (int i = 0; i < 6; ++i) dice_face_count.push_back(0);
	}
	void add_number(int n) {
		total += n;
		++dice_face_count[n-1];
		++count;
	}
	float get_face_average(int face_number) {
		return (float)dice_face_count[face_number-1] / (float)count * 100;
	}
	float get_average() {
		float fl_total = total;
		float fl_count = count;
		return fl_total / fl_count;
	}
	int get_count() { return count; }
};

int main() {
	srand((unsigned int)time(NULL));
	Dice d1;
	Data data;
	
	for (int i = 0; i < 10; ++i) {
		d1.roll();
		data.add_number(d1.get_face());
	}
	float average = data.get_average();
	
	while (average < 3.45 || average > 3.64) {
		d1.roll();
		data.add_number(d1.get_face());
		average = data.get_average();
	}
	cout << "횟수: " << data.get_count() << " " << "평균: " << average << endl;
	cout << "각 주사위 면 별 등장 확률: ";
	for (int i = 0; i < 6; ++i) cout << i + 1 << "번: " << data.get_face_average(i+1) << "%" << endl;
	return 0;
}