#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <vector>
using std::vector;

struct Work {
    int D;
    int P;
};

void test() {
    int N;
    if (!(cin >> N)) return;

    vector<Work> testcase(N);
    for (Work& x : testcase) { cin >> x.D >> x.P; }
}

int main() {
    // 첫 줄에 테스트 케이스의 개수 T를 입력받습니다.
    int T; 
    while (T--) { test(); }
    return 0;
}
