#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <vector>
using std::vector;
#include <limits>

int get_bigger(int a, int b) {
    if (a <= b) return b;
    else return a;
}

void solve(const vector<int>& original_input) {
    int n = original_input.size();
    
    // n보다 크거나 같은 2의 거듭제곱 m 찾기
    int m = 1;
    while (m < n) m *= 2;
    const int INF = std::numeric_limits<int>::lowest();
    vector<int> tree(2 * m - 1, INF);
    
    // 리프 노드에 입력값 채우기 (m-1번 인덱스부터 시작)
    for (int i = 0; i < n; ++i) tree[m - 1 + i] = original_input[i];
    
    // 트리 구축 (위로 올라가며 각 대결의 승자를 결정)
    for (int i = m - 2; i >= 0; --i) tree[i] = get_bigger(tree[2 * i + 1], tree[2 * i + 2]);

    // 최댓값에게 패배한 후보들 수집
    vector<int> losers;
    int curr = 0;
    while (curr < m - 1) {
        int left = 2 * curr + 1;
        int right = 2 * curr + 2;

        // 현재 노드가 왼쪽 자식과 같다면, 오른쪽 자식이 패자 후보
        if (tree[curr] == tree[left]) {
            losers.push_back(tree[right]);
            // 승자의 경로를 따라 내려감
            curr = left;
        }
        else {
            losers.push_back(tree[left]);
            curr = right;
        }
    }
    
    // 패자 후보들 중 최댓값이 곧 두 번째로 큰 수
    int second_max = losers[0];
    for (size_t i = 1; i < losers.size(); ++i) {
        if (losers[i] > second_max) second_max = losers[i];
    }
    
    cout << second_max << endl;
}

void test() {
    int N; cin >> N;
    vector<int> original_input(N);
    for (int i = 0; i < N; ++i) cin >> original_input[i];
    solve(original_input);
}

int main() {
    int T; cin >> T;
    while (T--) test();
	return 0;
}
