#include <iostream>
#include <vector>

// 이번에 배워서 처음 써보는 구조체
struct TestCase {
    std::vector<int>data;
    int selected_numbers[3];
    int biggest_calculated;
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
int calculate(int count, int i, int j, int k) {
    int n = count;
    int result = n * n * k * (i - j);
    if (result < 0) result = 0;
    return result;
}

// 번호 3개 고른 뒤 해당 테스트케이스에서 계산값 가장 큰 것 찾는 함수
void select_number_and_find_biggest(TestCase testcase) {
    using std::vector;
    int& biggest_calculated = testcase.biggest_calculated;
    biggest_calculated = 0;
    vector<int>& v = testcase.data;
    int v_size = v.size();
    int selected[3];
    for (int i = 0; i < v_size; i++) {
        selected[0] = v[i];
        for (int j = 0; j < v_size; j++) {
            // 앞 수보다 작거나 같으면 건너뛰기
            if (v[j] <= selected[0]) continue;
            selected[1] = v[j];
            for (int k = 0; k < v_size; k++) {
                // 앞 수보다 작거나 같으면 건너뛰기
                if (v[k] <= selected[1]) continue;
                selected[2] = v[k];
                int value = calculate(v_size, selected[0], selected[1], selected[2]);
                if (value > biggest_calculated) biggest_calculated = value;
            }
        }
    }
}

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
        int integer_count;
        cin >> integer_count;
        user_input[i].data.resize(integer_count);
        fill_vector(user_input[i].data);
    }
    
    // 변호 3개 고르고, 요구한 계산 진행하는 함수 아래에 적어야 함
    /*
    for (int i = 0; i < testcase_count; i++) {
        select_number_and_find_biggest(user_input[i]);
        cout << user_input[i].biggest_calculated << endl;
    }
    */

    return 0;
}