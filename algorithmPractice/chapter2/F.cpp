#include <iostream>
using std::cin, std::cout, std::endl;
#include <vector>
using std::vector;

bool check(const char* s, long long a, long long b, int start_idx) {
    if (start_idx == strlen(s)) return true;
    
    long long c = a + b;
    char c_str[20];
    sprintf(c_str, "%lld", c);
    int len = strlen(c_str);
    
    if (strncmp(s + start_idx, c_str, len) == 0) return check(s, b, c, start_idx + len);
    return false;
}

int main() {
    int testcase_count;
    cin >> testcase_count;
    return 0;
}