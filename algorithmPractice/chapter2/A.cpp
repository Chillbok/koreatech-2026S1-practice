#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

bool solve(vector<int> numbers, int target, int index) {
    // 공집합이거나, 조합을 완성한 경우
    if (target == 0) return true;
    //끝까지 확인했는데 못 맞춘 경우거나, 목표가 음수가 된 경우
    if (index >= numbers.size() || target < 0) return false;
    // 분기 생성 조건문들
    // 현재 숫자를 포함하는 경우
    if (solve(numbers, target - numbers[index], index + 1)) return true;
    // 현재 숫자를 포함하지 않는 경우
    if (solve(numbers, target, index + 1)) return true;
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int testcase_length;
    cin >> testcase_length;
    vector<bool> testcase_result;
    for (int i = 0; i < testcase_length; i++) {
        int m;
        int n;
        cin >> m; cin >> n;
        vector<int> input_integers(n);
        for (int& selected_integer : input_integers) {
            cin >> selected_integer;
        }
        
        testcase_result.push_back(solve(input_integers, m, 0));
    }
    
    for (bool const& x : testcase_result) {
        if (x == true) cout << "true";
        else if (x == false) cout << "false";
        cout << endl;
    }
    return 0;
}