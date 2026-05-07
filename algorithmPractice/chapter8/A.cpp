#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <vector>
using std::vector;

struct Work {
    int D;
    int P;
}

void test() {
    // 테스트 케이스 생성 및 입력
    int N;
    cin >> N;
    vector<Work> testcase(N);
    for (Work& x : testcase) { cin >> x.D >> x.P; }
    // 연산 과정

    // 출력 과정
}

int main() {
    int T; cin >> T;
    while (T--) test();
}
