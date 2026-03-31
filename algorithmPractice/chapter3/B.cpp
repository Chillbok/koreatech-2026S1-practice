/*
모든 문제를 분할 정복 기법을 이용해 해결해야 함.
더 효과적인 방법이 있더라도, 반드시 강의 슬라이드에 제시된 알고리즘을 활용해 완성할 것.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using std::cin; using std::cout; using std::endl;
using std::vector;

int solve(const std::vector<int>& H, int left, int right) {
    // 막대가 하나뿐일 때
    if (left == right) return H[left];

    // 중앙값 구하기
    int mid = (left + right) / 2;
    // 왼쪽 반과 오른쪽 반을 넣어서 재귀적으로 호출
    int rectangle = std::max(solve(H, left, mid), solve(H, mid + 1, right));

    // 중앙을 가로지르는 사각형 구하기
    int lo = mid, hi = mid + 1;
    int height = std::min(H[lo], H[hi]);
    // 너비 2짜리 사각형 구하기
    rectangle = std::max(rectangle, height * 2);

    while (left < lo || hi < right) {
        // 더 높은 쪽으로 확장해 사각형 높이를 최대한 유지
        if (hi < right && (lo == left || H[lo - 1] < H[hi + 1])) {
            hi++;
            height = std::min(height, H[hi]);
        } else {
            lo--;
            height = std::min(height, H[lo]);
        }
        rectangle = std::max(rectangle, height * (hi - lo + 1));
    }

    return rectangle;
}

void test() {
    int case_length;
    if (!(cin >> case_length)) return;
    std::vector<int> cases(case_length);
    for (int i = 0; i < case_length; ++i) cin >> cases[i];
    cout << solve(cases, 0, case_length - 1) << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int testcase_count;
    if (!(cin >> testcase_count)) return 0;
    
    while (testcase_count--) test();
    return 0;
}
