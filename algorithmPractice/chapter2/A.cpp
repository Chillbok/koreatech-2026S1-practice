#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

bool solve(vector<int> numbers, int number_to_make) {
    int size = numbers.size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (j == i) continue;
            if (numbers[i] + numbers[j] == number_to_make) return true;
        }
    }
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
        
        testcase_result.push_back(solve(input_integers, m));
    }
    
    for (bool const& x : testcase_result) {
        cout << x << endl;
    }
    return 0;
}