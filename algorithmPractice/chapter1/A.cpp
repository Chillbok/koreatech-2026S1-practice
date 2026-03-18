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
    if (!(cin >> n)) return;
    
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
    return 0;
}