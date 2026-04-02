#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <vector>
using std::vector;

void swap_number (int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int divide(vector<int>& arr, int low_idx, int high_idx) {
    int pivot_idx = high_idx;
    int last_moved_idx = low_idx;
    for (int i = low_idx; i < high_idx; i++) {
        if (arr[i] <= arr[pivot_idx]) {
            // 현재 요소를 작은 요소 영역의 끝과 교환
            swap_number(arr[i], arr[last_moved_idx]);
            last_moved_idx++;
        }
    }
    // 마지막에 왼쪽으로 몰아넣은 값 바로 오른쪽에 pivot 넣기
    swap_number(arr[last_moved_idx], arr[pivot_idx]);
    // pivot 위치 알리기
    return last_moved_idx;
}

void quick_sort(vector<int>& arr, int low_idx, int high_idx) {
    if (low_idx < high_idx) {
        // 피벗 인덱스 얻기
        int pivot_idx = divide(arr, low_idx, high_idx);
        quick_sort(arr, low_idx, pivot_idx - 1);
        quick_sort(arr, pivot_idx + 1, high_idx);
    }
}

void test() {
    int size; cin >> size;
    vector<int> numbers(size);
    for (int i = 0; i < size; i++) cin >> numbers[i];
    quick_sort(numbers, 0, numbers.size()-1);
    for (int i = 0; i < size; i++) cout << numbers[i] << " ";
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) test();
    return 0;
}