/*
모든 문제를 분할 정복 기법을 이용해 해결해야 함.
더 효과적인 방법이 있더라도, 반드시 강의 슬라이드에 제시된 알고리즘을 활용해 완성할 것.
*/
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <vector>
using std::vector;

void test() {
    int case_length;
    cin >> case_length;
    vector<int> cases(case_length);
    for (int& x : cases) cin >> x;
}

int main() {
    int testcase_count;
    if (!(cin >> testcase_count)) return 0;
    
    while (testcase_count--) test();
    return 0;
}