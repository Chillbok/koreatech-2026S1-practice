#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

vector<vector<int>> _able_arr;

vector<int>* solve(int target, const vector<int>& numbers) {
    if (target == 0) return new vector<int>();
    if (target < 0) return nullptr;
    
    for (int num : numbers) {
        int remainder = target - num;
        vector<int>* remainderResult = solve(remainder, numbers);
        
        if (remainderResult != nullptr) {
            remainderResult->push_back(num);
            return remainderResult;
        }
    }
    return nullptr;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int testcase_count;
    if (!(cin >> testcase_count)) return 0;
    
    while (testcase_count--) {
        int M, N;
        cin >> M >> N;
        
        vector<int> numbers(N);
        for (int i = 0; i < N; ++i) {
            cin >> numbers[i];
        }
        
        if (M == 0) {
            cout << 0 << "\n";
            continue;
        }
        
        vector<int>* result = solve(M, numbers);
        if (result != nullptr) {
            cout << result->size() << " ";
            for (int i = 0; i < result->size(); ++i) {
                cout << (*result)[i] << " ";
            }
            cout << endl;
            
            delete result;
        }
        else {
            cout << -1 << endl;
        }
    }
    
    return 0;
}