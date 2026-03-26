#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <cstring>
#include <cstdlib>

bool check(const char* s, long long a, long long b, int start_idx) {
    if (s[start_idx] == '\0') return true;
    
    long long c = a + b;
    char c_str[40];
    snprintf(c_str, sizeof(c_str), "%lld", c);
    int len = strlen(c_str);
    
    if (strncmp(s + start_idx, c_str, len) == 0) return check(s, b, c, start_idx + len);
    return false;
}

void test() {
    char s[100];
    if(!(cin >> s)) return;

    int n = strlen(s);
    bool found = false;
    
    for (int i = 1; i <= n / 2 + 1; i++) {
        for (int j = 1; i + j < n; j++) {
            char temp_a[40] = {0,}, temp_b[40] = {0,};

            strncpy(temp_a, s, i);
            temp_a[i] = '\0';
            strncpy(temp_b, s + i, j);
            temp_b[j] = '\0';
            
            long long a = atoll(temp_a);
            long long b = atoll(temp_b);
            
            if ((i > 1 && s[0] == '0') || (j > 1 && s[i] == '0')) continue;

            if(check(s, a, b, i + j)) {
                found = true;
                break;
            }
        }
        if (found) break;
    }
    
    if (found) cout << "true" << endl;
    else cout << "false" << endl;
}

int main() {
    int testcase_count;
    if (!(cin >> testcase_count)) return 0;
    
    while (testcase_count--) test();
    return 0;
}