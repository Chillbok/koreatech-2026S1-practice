#include<iostream>
using std::cin; using std::cout; using std::endl;
#include<vector>
using std::vector;
#include<algorithm>

void test() {
	int M, N; cin >> M >> N;
	vector<int> testcase(N);
	for (int& x : testcase) cin >> x;

	std::sort(testcase.begin(), testcase.end());
	int count = 0;
	for (int price : testcase) {
		if (M >= price) {
			M -= price;
			count++;
		} else {
			break;
		}
	}
	cout << count << endl;
}

int main() {
	int T; cin >> T;
	while(T--) test();
}