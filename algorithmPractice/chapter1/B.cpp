#include <iostream>
#include <vector>

// 이번에 배워서 처음 써보는 구조체
struct TestCase {
    int integer_count;
    std::vector<int>data;
};

int main() {
    using std::vector;
    using std::cin;
    using std::cout;
    using std::endl;

    int testcase_count;
    cin >> testcase_count;
    TestCase user_input[testcase_count];
    return 0;
}