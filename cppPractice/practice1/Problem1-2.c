#include <stdio.h>

int main() {
    int arr_size = 10;
    // 일단 입력 받는 배열
    int input[arr_size];
    
    // 하나씩 숫자 입력
    for (int i = 0; i < arr_size; i++) {
        printf("%d번째 숫자(하나씩 숫자 입력): ", i+1);
        scanf("%d", &input[i]);
    }
    // 짝수
    int even[arr_size];
    // 홀수
    int odd[arr_size];
    return 0;
}