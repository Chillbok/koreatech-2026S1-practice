#include <stdio.h>
#include <stdbool.h>

bool is_this_even(int number) {
    if (number % 2 == 0) return true;
    else return false;
}

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
    int even_count = 0;
    int odd_count = 0;
    // 짝수 홀수 나눠서 각각 배열에 넣기
    for (int i = 0; i < arr_size; i++) {
        int value = input[i];
        // 짝수면
        if (is_this_even(value)) {
            even[even_count] = value;
            even_count++;
        }
        else
        {
            odd[odd_count] = value;
            odd_count++;
        }
    }

    int answer[arr_size];
    for (int i = 0; i < odd_count; i++) {
        answer[i] = odd[i];
    }
    for (int i = 0; i < even_count; i++) {
        int j = arr_size - 1 - i;
        answer[j] = even[i];
    }
    
    printf("배열 출력: ");
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", answer[i]);
    }
    printf("\n");
    
    return 0;
}