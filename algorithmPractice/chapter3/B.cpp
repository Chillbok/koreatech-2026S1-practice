#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <vector>
using std::vector;

void test() {
    int case_length;
    cin >> case_length;
    vector<int> cases(case_length);
    for (int& x : cases) cin >> x;
}

int main() {
    int testcase_count;
    if (!(cin >> testcase_count)) return 0;
    
    while (testcase_count--) test();
    return 0;
}