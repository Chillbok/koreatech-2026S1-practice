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
	void roll() {
		face = rand() % 6 + 1;
	}
};

class Data {
private:
	int total;
	int count;
	vector<int> dice_face_count;
public:
	// getter 함수들
	int get_count() const { return count; }
	int get_face_count(int idx) { return dice_face_count[idx]; }

	// 생성자
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
	float get_face_average(int idx) {
		return (float)dice_face_count[idx] / (float)count * 100;
	}
	float get_average() {
		float fl_total = total;
		float fl_count = count;
		return fl_total / fl_count;
	}
};

int main() {
	srand((unsigned int)time(NULL));
	Dice d1;
	Data data;
	float average;

	for (int i = 0; i < 10; ++i) {
		d1.roll();
		data.add_number(d1.get_face());
		average = data.get_average();
		cout << data.get_count() << "번째 주사위 면은 = " << d1.get_face() << " . 평균값 : " << data.get_average() << endl;
	}
	

	while (average < 3.45 || average > 3.64) {
		d1.roll();
		data.add_number(d1.get_face());
		average = data.get_average();
		cout << data.get_count() << "번째 주사위 면은 = " << d1.get_face() << " . 평균값 : " << average << endl;
	}
	for (int i = 0; i < 6; ++i) cout << i + 1 << "면: " << data.get_face_count(i) << "번이고, 확률은: " << data.get_face_average(i)<< endl;
	cout << data.get_count() << "번 던졌을 때 평균값은 " << average << "입니다." << endl;
	return 0;
}