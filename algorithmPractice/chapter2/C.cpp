#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

vector<int>* solve(int target, vector<int> testcase) {
    if (target == 0) return new vector<int>();
    if (target < 0) return nullptr;
    vector<int>* best_case = nullptr;
    
    for (int& x : testcase) {
        vector<int>* current_case = solve(target - x, testcase);
        if (current_case != nullptr) {
            if (best_case == nullptr || (best_case->size() > (current_case->size() + 1))) {
                current_case->push_back(x);
                delete best_case;
                best_case = current_case;
            }
        }
    }
    return best_case;
}

int main() {
    int testcase_count;
    cin >> testcase_count;
    
    for (int i = 0; i < testcase_count; i++) {
        int target, integer_count;
        cin >> target >> integer_count;

        vector<int> testcase(integer_count);
        for (int& idx : testcase) cin >> idx;
        // 경우의 수 출력
        vector<int>* result = solve(target, testcase);
        if (result != nullptr) {
            cout << result->size() << " ";
            for (int& x : *result) cout << x << " ";
            cout << endl;
        }
        else cout << -1 << endl;
        delete result;
    }
    
    return 0;
}