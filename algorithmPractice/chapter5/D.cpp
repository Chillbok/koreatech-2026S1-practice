#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <vector>
using std::vector;
#include <algorithm>

struct Time {
    int hour;
    int minute;
};

int change_to_minute(int hour, int minute) {
    return hour * 60 + minute;
}

void make_testcase(vector<Time>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        int h, m;
        char c;
        cin >> h >> c >> m;
        arr[i].hour = h;
        arr[i].minute = m;
    }
}

vector<int> change_only_minute(const vector<Time>& arr) {
    vector<int> result(arr.size());
    for (int i = 0; i < arr.size(); ++i) result[i] = change_to_minute(arr[i].hour, arr[i].minute);
    return result;
}

void test() {
    int length; cin >> length;
    vector<Time> testcase(length);
    make_testcase(testcase);
    vector<int> testcase_minute = change_only_minute(testcase);
    std::sort(testcase_minute.begin(), testcase_minute.end());
    int min_gap = 1440;
    for (int i = 0; i < length - 1; ++i) {
        int current_gap = testcase_minute[i+1] - testcase_minute[i];
        if (current_gap < min_gap) min_gap = current_gap;
    }
    
    if (length > 1) {
        int circular_gap = (1440 - testcase_minute.back()) + testcase_minute[0];
        if (circular_gap < min_gap) min_gap = circular_gap;
    }
    
    cout << min_gap << endl;
}

int main() {
    int T; cin >> T;
    while (T--) test();
    return 0;
}