#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int get_count(int target, vector<int> testcase) {
    if (target < 0) return 0;
    if (target == 0) return 1;
    int count = 0;
    for (const int& x : testcase) count += get_count(target - x, testcase);
    return count;
}

void test() {
    int target, count;
    cin >> target >> count;
    vector<int> testcase(count);
    for (int& x : testcase) cin >> x;
    int result = get_count(target, testcase);
    cout << result << endl;
}

int main() {
    int testcase_count;
    cin >> testcase_count;
    while (testcase_count--) test();
    return 0;
}