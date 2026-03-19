#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

bool solve(const vector<int>& numbers, int target, int index) {
    // 공집합이거나, 조합을 완성한 경우
    if (target == 0) return true;
    //끝까지 확인했는데 못 맞춘 경우거나, 목표가 음수가 된 경우
    if (index >= numbers.size() || target < 0) return false;
    // 분기 생성 조건문들
    return solve(numbers, target - numbers[index], index + 1) || solve(numbers, target, index + 1);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int testcase_length;
    cin >> testcase_length;
    vector<bool> testcase_result;
    for (int i = 0; i < testcase_length; i++) {
        int m, n;
        cin >> m >> n;
        vector<int> input_integers(n);
        for (int& selected_integer : input_integers) {
            cin >> selected_integer;
        }
        
        // 결과 즉시 출력
        if (solve(input_integers, m, 0)) cout << "true\n";
        else cout << "false\n";
    }

    return 0;
}