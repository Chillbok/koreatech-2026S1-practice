#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <vector>
using std::vector;

bool check_same(const int n1, const int n2, const int n3) {
	int number = (n1 + n3) / 2;
	// 둘이 같으면 true 반환
	return (n2 == number) ? true : false;
}

void test() {
	int N; cin >> N;
	vector<int> input(N);
	for (int& x : input) cin >> x;
}

int main() {
	int T; cin >> T;
	while (T--) test();
	return 0;
}