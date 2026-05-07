// 탐욕적 알고리즘으로 해결하고, 제안한 알고리즘의 정확성을 증명해야 함. 증명은 별도 파일로 작성하여 pdf로 제출해야 함.
#include<iostream>
using std::cin; using std::cout; using std::endl;
#include<vector>
using std::vector;
#include<algorithm>

// 다양한 사탕이 있고, 가격이 주어졌을 때, 가지고 있는 예산으로 최대한 많은 사탕을 구입하려고 한다. 얼마나 많은 사탕을 살 수 있는지 알려주어라.

void test() {
	// M = 가지고 있는 예산(1 이상, 100 이하)
	// N = 사탕 수(1 이상 100 이하)
	int M, N; cin >> M >> N;
	vector<int> testcase(N);
	// N개의 사탕 가격이 주어짐
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

/*
입력 예시:
3
7 5
1 3 2 4 1
5 6
10 6 8 7 7 8
20 6
1 6 3 1 2 5

출력 설명: 각 테스트케이스마다 구매할 수 있는 최대 사탕 수를 출력해야 함.
출력 예시:
4
0
6
*/