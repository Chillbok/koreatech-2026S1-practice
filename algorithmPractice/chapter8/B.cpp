#include<iostream>
using std::cin; using std::cout; using std::endl;
#include<vector>
using std::vector;
#include<string>
using std::string;
#include<algorithm>
using std::sort;

void test() {
	int N; cin >> N;
	vector<string> testcase(N);
	for (string& x : testcase) cin >> x;

	sort(testcase.begin(), testcase.end(), [](const string& a, const string& b) {
		return a + b > b + a;
	});

	if (testcase[0] == "0") {
		cout << "0" << endl;
		return;
	}

	for (const string& x : testcase) cout << x;
	cout << endl;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T; cin >> T;
	while (T--) test();
}
