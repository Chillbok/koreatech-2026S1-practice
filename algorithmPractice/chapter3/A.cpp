/*
모든 문제를 분할 정복 기법을 이용해 해결해야 함.
더 효과적인 방법이 있더라도, 반드시 강의 슬라이드에 제시된 알고리즘을 활용해 완성할 것.
*/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <vector>
using std::vector;

long long merge_and_count(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    long long split_inv = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            split_inv += (mid -i + 1);
        }
    }
    
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];
    for (int p = 0; p < temp.size(); p++) arr[left + p] = temp[p];
    
    return split_inv;
}

long long sort_count_inv(vector<int>& arr, int left, int right) {
    if (left >= right) return 0;
    int mid = left + (right - left) / 2;

    long long L = sort_count_inv(arr, left, mid);
    long long R = sort_count_inv(arr, mid + 1, right);
    long long S = merge_and_count(arr, left, mid, right);

    return L + R + S;
}

int main() {
    int testcase_count;
    if (!(cin >> testcase_count)) return 1;
    while (testcase_count--) {
        int arr_size;
        cin >> arr_size;
        vector<int> arr(arr_size);
        for (int i = 0; i < arr_size; i++) cin >> arr[i];
        cout << sort_count_inv(arr, 0, arr_size - 1) << "\n";
    }

    return 0;
}