// 라이브러리에 있는 기능을 사용하지 않고, 수업시간에 배운 알고리즘을 직접 구현할 것
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <vector>
using std::vector;

void solve(const vector<int>& arr) {
	int max = 0, min = 0;
	int i;
	if (arr.size() % 2 == 0) {
		if (arr[0] < arr[1]) {
			max = arr[1];
			min = arr[0];
		}
		else {
			max = arr[0];
			min = arr[1];
		}
		i = 2;
	}
	else {
		max = arr[0], min = arr[0];
		i = 1;
	}

	while (i <= arr.size() - 1) {
		if (arr[i] < arr[i + 1]) {
			if (arr[i] < min) min = arr[i];
			if (arr[i + 1] > max) max = arr[i + 1];
		}
		else {
			if (arr[i + 1] < min) min = arr[i + 1];
			if (arr[i] > max) max = arr[i];
		}
		i += 2;
	}
	cout << max << " " << min << endl;
}

void test() {
	int N; cin >> N;
	vector<int> arr(N);
	for (int i = 0; i < N; ++i) cin >> arr[i];
	solve(arr);
}

int main() {
	int T; cin >> T;
	while (T--) test();
	return 0;
}