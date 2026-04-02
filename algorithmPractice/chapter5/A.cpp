#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <vector>
using std::vector;

void swap (int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
}

void test() {
    int size; cin >> size;
    int numbers[size];
    for (int i = 0; i < size; i++) cin >> numbers[i];
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) test();
    return 0;
}