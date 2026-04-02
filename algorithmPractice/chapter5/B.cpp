/*
확률적 알고리즘으로 해결해야 함.
알고리즘의 정확성과 성능을 분석해 간단히 주석에 포함해야 함.
확률적 알고리즘: 전체 구간에서 한 요소를 랜덤하게 선택하였을 때, 이 요소가 절반이 넘는 수가 될 확률은 50%입니다.

- 따라서 랜덤하게 선택하였을 때 답을 찾을 확률의 기대값은 2입니다.
- 이를 활용한 알고리즘을 구현해보고 실제 답을 찾을 수 있는지(정확성), 찾을 수 있다면 이 알고리즘의 성능은 어떻게 되는지 간단히 분석해 보세요.
- Rselect를 이용하여 중간값을 찾는 것은 아닙니다.
*/
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <vector>
using std::vector;
#include <map>
using std::map;

void test() {
    int integer_count;
    cin >> integer_count;
    vector<int> arr(integer_count);
    for (int i = 0; i < integer_count; i++) cin >> arr[i];
}

int main() {
    int T;
    cin >> T;
    while (T--) test();
    return 0;
}