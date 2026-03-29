/*
모든 문제를 분할 정복 기법을 이용해 해결해야 함.
더 효과적인 방법이 있더라도, 반드시 강의 슬라이드에 제시된 알고리즘을 활용해 완성할 것.
*/
// C번 출력 방법:
// printf("%.2f\n", answer); // C++
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

float get_answer(float arr[][2], int size) {
    // 여기서부터 구현해야 함.
    float result;
    return result;
}

void test() {
    int location_count;
    cin >> location_count;
    float testcase[location_count][2];
    float answer = get_answer(testcase, location_count);
    printf("%.2f\n", answer);
}

int main() {
    int testcase_count;
    if(!(cin >> testcase_count)) return 0;
    while (testcase_count--) test();
    return 0;
}