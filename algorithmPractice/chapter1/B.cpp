#include <iostream>
#include <vector>

// 이번에 배워서 처음 써보는 구조체
struct TestCase {
    int integer_count;
    std::vector<int>data;
};

// 입력값을 띄어쓰기로 구분해서 값 집어넣는 함수
void fill_vector(std::vector<int>& param_vector) {
    using std::cin;
    int size = param_vector.size();
    for (int i = 0; i < size; i++) {
        cin >> param_vector[i];
    }
}

// 요구한 계산 진행하는 함수
int calculate(int n, int i, int j, int k) {
    int result = n * n * k * (i - j);
    if (result < 0) result = 0;
    return result;
}

// 번호 3개 고른 뒤 해당 테스트케이스에서 계산값 가장 큰 것 찾는 함수

int main() {
    using std::vector;
    using std::cin;
    using std::cout;
    using std::endl;

    // 테스트 케이스 생성
    int testcase_count;
    cin >> testcase_count;
    vector<TestCase> user_input(testcase_count);
    
    // 테스트케이스에 값 집어넣기
    for (int i = 0; i < testcase_count; i++) {
        cin >> user_input[i].integer_count;
        user_input[i].data.resize(user_input[i].integer_count);
        fill_vector(user_input[i].data);
    }
    
    // 변호 3개 고르고, 요구한 계산 진행하는 함수 아래에 적어야 함

    return 0;
}