#include <iostream>
#include <vector>
#include <algorithm>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

// TimSort를 위한 최소 단위
const int RUN = 32;

struct TestCase {
    std::vector<int> data;
    std::vector<int> sorted;
};

// 작은 구간 정렬용 함수
void insertion_sort(vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

// 정렬 구간 합치는 함수
void merge(vector<int>& arr, int l, int m, int r) {
    int len1 = m - l + 1, len2 = r - m;
    vector<int> left(len1), right(len2);

    for (int i = 0; i < len1; i++) left[i] = arr[l + i];
    for (int i = 0; i < len2; i++) right[i] = arr[m + 1 + i];
    
    int i = 0, j = 0, k = l;
    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) arr[k++] = left[i++];
        else arr[k++] = right[j++];
    }
    while (i < len1) arr[k++] = left[i++];
    while (j < len2) arr[k++] = right[j++];
}

// timsort 메인 함수
void tim_sort(vector<int>& arr, int n) {
    // Run 단위로 삽입 정렬
    for (int i = 0; i < n; i += RUN)
        insertion_sort(arr, i, std::min((i + RUN - 1), (n-1)));
    
    // 병합 시작
    for (int size = RUN; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = std::min((left + 2 * size - 1), (n - 1));
            if (mid < right) merge(arr, left, mid, right);
        }
    }
}

int main() {
    // 입출력 속도 향상
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        
        // timsort 실행
        tim_sort(arr, N);
        
        // 결과 출력
        for (int i = 0; i < N; i++) {
            cout << arr[i] << (i == N - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}