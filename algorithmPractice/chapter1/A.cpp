#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using std::cin;
using std::cout;
using std::vector;
using std::unordered_map;

void solve() {
    int n;
    cin >> n;
    unordered_map<long long, int> counts;
    vector<long long> nums(n);
    
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        counts[nums[i]]++;
    }
    
    int max_length = 0;
    
    for (auto const& [val, count] : counts) {
        // 현재 숫자(val)보다 1 큰 숫자가 존재하는지 확인
        if (counts.find(val + 1) != counts.end()) {
            int current_length = count + counts[val + 1];
            max_length = std::max(max_length, current_length);
        }
    }
    cout << max_length << "\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int testcase_count;
    cin >> testcase_count;
    for (int i = 0; i < testcase_count; i++) {
        solve();
    }
    return 0;
}