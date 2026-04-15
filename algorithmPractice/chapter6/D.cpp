#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <vector>
using std::vector;
#include <algorithm>
using std::sort;

void test() {
	int N; cin >> N;
	vector<int> input(N);
	for (int& x : input) cin >> x;
	sort(input.begin(), input.end());
	
	vector<int> result(N);
	int mid = (N + 1) / 2;
	int small_idx = 0;
	int large_idx = mid;
	
	for (int i = 0; i < N; ++i) {
		if (i % 2 == 0) result[i] = input[small_idx++];
		else result[i] = input[large_idx++];
	}
	
	for (int i = 0; i < N; ++i) cout << result[i] << " ";
	cout << endl;
}

int main() {
	int T; cin >> T;
	while (T--) test();
	return 0;
}