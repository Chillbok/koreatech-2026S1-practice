#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <vector>
using std::vector;

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