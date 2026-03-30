/*
모든 문제를 분할 정복 기법을 이용해 해결해야 함.
더 효과적인 방법이 있더라도, 반드시 강의 슬라이드에 제시된 알고리즘을 활용해 완성할 것.
*/
// C번 출력 방법:
// printf("%.2f\n", answer); // C++
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <cmath>
#include <algorithm>
#include <cstdio>

struct Pair {
    int x, y;
};

bool compare_x(const Pair& a, const Pair& b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

bool compare_y(const Pair& a, const Pair& b) {
    return a.y < b.y;
}

float get_dist (Pair p1, Pair p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

float solve(vector<Pair>& arr, int start, int end) {
    if (end - start + 1 <= 3) {
        float min_dist = -1;
        for (int i = start; i < end; i++) {
            for (int j = i + 1; j <= end; j++) {
                float d = get_dist(arr[i], arr[j]);
                if (min_dist == -1 || d < min_dist) min_dist = d;
            }
        }
        return min_dist;
    }
    
    int mid = (start + end) / 2;
    float dl = solve(arr, start, mid);
    float dr = solve(arr, mid + 1, end);
    
    float d = std::min(dl, dr);

    vector<Pair> strip;
    for (int i = start; i <= end; i++) if (std::abs(arr[i].x - arr[mid].x) < d) strip.push_back(arr[i]);
    
    std::sort(strip.begin(), strip.end(), compare_y);
    
    for (int i = 0; i < strip.size(); i++)
    for (int j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < d; j++)
    d = std::min(d, get_dist(strip[i], strip[j]));
    
    return d;
}

void test() {
    int location_count;
    cin >> location_count;
    int pair_size = 2;
    vector<Pair> testcase(location_count);
    for (int i = 0; i < location_count; i++) cin >> testcase[i].x >> testcase[i].y;
    
    sort(testcase.begin(), testcase.end(), compare_x);

    float answer = solve(testcase, 0, location_count - 1);
    printf("%.2f\n", answer);
}

int main() {
    int testcase_count;
    if(!(cin >> testcase_count)) return 0;
    while (testcase_count--) test();
    return 0;
}