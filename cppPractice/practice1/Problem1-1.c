#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int count_number(bool is_multiple3, int arr[], int arrSize) {
    int result = 0;
    for (int i = 0; i < arrSize; i++)
    {
        bool current_is_multiple3 = (arr[i] % 3 == 0);
        if (current_is_multiple3 == is_multiple3) {
            result += 1;
        }
    }
    return result;
}

void make_array_of_multiple3(bool is_multiple3, int unsorted[], int unsorted_size, int result[], int result_size) {
    int count = 0;
    for (int i = 0; i < unsorted_size; i++) {
        bool current_multiple3 = (unsorted[i] % 3 == 0);
        if (current_multiple3 == is_multiple3) {
            result[count] = unsorted[i];
            count++;
        }
    }
}

int main() {
    int size = 10;
    int array[size];

    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        int num = rand() % 101;
        array[i] = num;
    }
    
    // 배열 출력
    printf("array: ");
    for (int i = 0; i < size; i++) {
        printf("%d, ", array[i]);
    }
    printf("\n");
    
    // 3의 배수 담을 배열 생성하고, 배열에 담기
    int multiple3_count = count_number(true, array, size);
    int multiple3_array[multiple3_count];
    make_array_of_multiple3(true, array, size, multiple3_array, multiple3_count);
    
    printf("3의 배수: ");
    for (int i = 0; i < multiple3_count; i++) {
        printf("%d ", multiple3_array[i]);
    }
    printf("\n");
    
    // 3의 배수가 아닌 숫자 담을 배열 생성하고, 배열에 담기
    int not_multiple3_count = count_number(false, array, size);
    int not_multiple3_array[not_multiple3_count];
    make_array_of_multiple3(false, array, size, not_multiple3_array, not_multiple3_count);
    
    printf("3의 배수가 아닌 수: ");
    for (int i = 0; i < not_multiple3_count; i++) {
        printf("%d ", not_multiple3_array[i]);
    }
    printf("\n");

    return 0;
}