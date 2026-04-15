#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <vector>
using std::vector;
#include <algorithm>
using std::swap; using std::sort;

vector<int> wiggle_sort(vector<int>& arr) {
	sort(arr.begin(), arr.end());
	int n = arr.size();
	vector<int> result(n);
	
	int mid = (n + 1) / 2;
	int left = mid - 1, right = n - 1;
	
	for (int i = 0; i < n; ++i) {
		if (i % 2 == 0) result[i] = arr[left--];
		else result[i] = arr[right--];
	}
	return result;
}

void test() {
	int N; cin >> N;
	vector<int> input(N);
	for (int& x : input) cin >> x;
	vector<int> sorted_arr = wiggle_sort(input);
	
	// 출력 부분
	cout << sorted_arr.size() << endl;
	for (int& x : sorted_arr) cout << x << " ";
	cout << endl;
}

int main() {
	int T; cin >> T;
	while (T--) test();
	return 0;
}