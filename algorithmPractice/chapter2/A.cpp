#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

bool solve(const vector<int>& numbers, int target, int index) {
    if (target < 0) return false;
    // 공집합이거나, 조합을 완성한 경우
    if (target == 0) return true;
    //끝까지 확인했는데 못 맞춘 경우거나, 목표가 음수가 된 경우
    if (index >= numbers.size()) return false;
    for (const int& selected : numbers) {
        if(solve(numbers, target - selected, index + 1)) return true;
    }
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int testcase_length;
    cin >> testcase_length;

    while(testcase_length--) {
        int m, n;
        cin >> m >> n;
        vector<int> input_integers(n);
        for (int& selected : input_integers) {
            cin >> selected;
        }
        if (solve(input_integers, m, 0)) cout << "true" << endl;
        else cout << "false" << endl;
    }

    return 0;
}