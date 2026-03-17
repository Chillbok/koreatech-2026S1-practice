#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct TestCase {
    vector<int> data;
    vector<int> longest_vector;
};

// 유저의 입력 받아서 int 벡터로 반환하는 함수
vector<int> make_input_data_vector() {
    vector<int> result;
    int data_length;
    cin >> data_length;
    result.resize(data_length);
    for (int i = 0; i < data_length; i++) {
        cin >> result[i];
    }
    return result;
}

// 조화배열을 만들기 위한 숫자 두개 가지고 있는지 확인하는 함수
bool does_have_two_numbers(vector<int> data, int a, int b) {
    bool has_a = false;
    bool has_b = false;
    for (int i = 0; i < data.size(); i++) {
        if (data[i] == a) has_a = true;
        else if (data[i] == b) has_b = true;
        if (has_a == true && has_b == true) return true;
    }
    return false;
}

// 하모니시퀸스 만드는 함수
vector<int> make_harmony_vector(vector<int>& testcase_data, int selected_number, int other_number) {
    vector<int> result;
    for (int i = 0; i < testcase_data.size(); i++) {
        if (testcase_data[i] == selected_number || testcase_data[i] == other_number) result.push_back(testcase_data[i]);
    }
    return result;
}

vector<int> get_longer_vector(vector<int>& a, vector<int>& b) {
    if (a.size() < b.size()) return b;
    else return a;
}

int main() {
    int testcase_count;
    cin >> testcase_count;
    vector<TestCase> testcases;
    testcases.resize(testcase_count);
    for (int i = 0; i < testcase_count; i++) {
        // 유저 입력 받아서 int 벡터로 반환
        testcases[i].data = make_input_data_vector();
        // 숫자 두개 골라서 조화배열 만들 수 있는지 확인
        for (int j = 0; j < testcases[i].data.size(); j++) {
            // 먼저 선택한 숫자, 선택한 숫자 -1만 있는 경우 만듬
            int selected_number = testcases[i].data[j];
            int other_number = selected_number - 1;
            bool can_make_harmony = does_have_two_numbers(testcases[i].data, selected_number, other_number);
            vector<int> smaller;
            if (can_make_harmony == true) smaller = make_harmony_vector(testcases[i].data, selected_number, other_number);
            // 선택한 숫자, 선택한 숫자 +1만 있는 경우 만듬
            vector<int> bigger;
            other_number = selected_number + 1;
            can_make_harmony = does_have_two_numbers(testcases[i].data, selected_number, other_number);
            if (can_make_harmony == true) smaller = make_harmony_vector(testcases[i].data, selected_number, other_number);
            // 두개 비교해서 더 큰거 기록
            vector<int> longer = get_longer_vector(smaller, bigger);
            testcases[i].longest_vector = get_longer_vector(longer, testcases[i].longest_vector);
        }
    }
    
    for (int i = 0; i < testcase_count; i++) {
        cout << testcases[i].longest_vector.size() << endl;
    }

    return 0;
}