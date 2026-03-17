#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct TestCase {
    vector<int> input;
    vector<int> longest_vector;
};

vector<int> get_longer_vector(vector<int> v1, vector<int> v2) {
    if (v1.size() < v2.size()) return v2;
    else return v1;
}

// 숫자 두 개 중 하나가 있으면 벡터에 넣어서 조화시퀸스 만들어서 반환하는 함수
// 만약 조화시퀸스를 만들지 못했다면 0 하나만 들어있는 벡터 반환
vector<int> get_longer_harmony_vector(vector<int> v, int selected_number, int addable_number) {
    vector<int> result;
    bool usable = false;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == selected_number) result.push_back(v[i]);
        else if (v[i] == addable_number)
        {
            if (usable == false) usable = true;
            result.push_back(v[i]);
        }
    }
    
    if (usable == true) return result;
    vector<int> unusable_result;
    return unusable_result;
}

// 테스트케이스를 받으면, 그 테스트케이스에서 만들 수 있는 가장 조화시퀸스 만들어서 테스트케이스 구조체에 집어넣는 함수반환하는 함수
void get_longest_harmony_sequence(TestCase& tc) {
    // 테스트케이스를 받으면 두 개의 벡터를 만들어야 함
    for (int i = 0; i < tc.input.size(); i++) {
        vector<int> smaller_than_first_index = get_longer_harmony_vector(tc.input, tc.input[i], tc.input[i] - 1);
        vector<int> bigger_than_first_index = get_longer_harmony_vector(tc.input, tc.input[i], tc.input[i] + 1);
        vector<int> longer_vector = get_longer_vector(smaller_than_first_index, bigger_than_first_index);
        if (tc.longest_vector.size() < longer_vector.size()) tc.longest_vector = longer_vector;
    }
}

int main() {
    // 테스트케이스 개수 입력받고, 테스트케이스 배열 생성
    int testcase_count;
    cin >> testcase_count;
    vector<TestCase> testcases(testcase_count);
    
    // 각 테스트케이스의 크기 설정하고, 값 입력받기
    for (int i = 0; i < testcase_count; i++) {
        int v_length;
        cin >> v_length;
        vector<int>& v = testcases[i].input;
        v.resize(v_length);
        for (int j = 0; j < v_length; j++) {
            cin >> v[j];
        }
    }
    
    // 테스트케이스에서 가장 긴 조화시퀸스 만들기
    for (int i = 0; i < testcases.size(); i++) {
        get_longest_harmony_sequence(testcases[i]);
        cout << testcases[i].longest_vector.size() << endl;
    }
    
    return 0;
}