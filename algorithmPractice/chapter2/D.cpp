#include <iostream>
#include <vector>
using std::cin; using std::cout; using std::endl;
using std::vector;

vector<int>* sum(int target, vector<int>& testcase) {
    if (target < 0) return nullptr;
    if (target == 0) return new vector<int>();
    vector<int>* best_case = nullptr;
    
    for (int& x : testcase) {
        vector<int>* current_case = sum(target - x, testcase);
        if (current_case != nullptr) {
            if (best_case == nullptr || best_case->size() > (current_case->size() + 1)) {
                current_case->push_back(x);
                best_case = current_case;
            }
        }
    }
    return best_case;
}

void test() {
    int target, testcase_length;
    cin >> target >> testcase_length;
    vector<int> testcase(testcase_length);
    for (int& x : testcase) cin >> x;
    vector<int>* result = sum(target, testcase);
    if (result == nullptr) cout << -1 << endl;
    else {
        cout << result->size() << " ";
        for (int& x : *result) cout << x << " ";
        cout << endl;
    }
}

int main() {
    int test_count;
    cin >> test_count;
    while (test_count--) test();
    return 0;
}