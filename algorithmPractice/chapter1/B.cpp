#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int main() {
    // 기초 설정 (fast I/O)
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 테스트케이스 배열 생성
    int testcase_count;
    cin >> testcase_count;

    for (int t = 0; t < testcase_count; t++) {
        int vector_length;
        cin >> vector_length;
        vector<int> selected_vector(vector_length);
        
        // 입력값 저장
        for (int i = 0; i < vector_length; i++) {
            cin >> selected_vector[i];
        }

        // 3개 이상의 데이터가 없으면 계산 불가하므로 0 출력
        if (vector_length < 3) {
            cout << 0 << endl;
            continue;
        }

        // max_val_prefix[i]: 0번부터 i번까지의 데이터 중 최대값
        vector<int> max_val_prefix(vector_length);
        max_val_prefix[0] = selected_vector[0];
        for (int i = 1; i < vector_length; i++) {
            max_val_prefix[i] = std::max(max_val_prefix[i - 1], selected_vector[i]);
        }

        // max_val_suffix[i]: i번부터 마지막까지의 데이터 중 최대값
        vector<int> max_val_suffix(vector_length);
        max_val_suffix[vector_length - 1] = selected_vector[vector_length - 1];
        for (int i = vector_length - 2; i >= 0; i--) {
            max_val_suffix[i] = std::max(max_val_suffix[i + 1], selected_vector[i]);
        }

        // j를 1부터 N-2까지 순회하며 최적의 i와 k를 찾아 biggest 갱신
        long long biggest = 0;
        for (int j = 1; j <= vector_length - 2; j++) {
            // j 이전에 등장한 데이터 중 최대값
            long long current_profit = (long long)max_val_prefix[j - 1] - selected_vector[j];
            // 이익이 발생할 때만 k값을 곱하여 biggest 갱신
            if (current_profit > 0) {
                long long value = current_profit * (long long)max_val_suffix[j + 1];
                if (biggest < value) biggest = value;
            }
        }
        cout << biggest << endl;
    }
    return 0;
}