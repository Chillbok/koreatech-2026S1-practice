#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int multiples_of_3(bool is_multiple_3, int arr[], int size, int result[]) {
    int result_count = 0;
    for (int i = 0; i < size; i++) {
        bool current_multiple3 = (arr[i] % 3 == 0);
        if (current_multiple3 == is_multiple_3) {
            result[result_count] = arr[i];
            result_count += 1;
        }
    }
    return result_count;
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
    int multiple3_array[size];
    int multiple3_count = multiples_of_3(true, array, size, multiple3_array);
    
    printf("3의 배수: ");
    for (int i = 0; i < multiple3_count; i++) {
        printf("%d ", multiple3_array[i]);
    }
    printf("\n");
    
    // 3의 배수가 아닌 숫자 담을 배열 생성하고, 배열에 담기
    int not_multiple3_array[size];
    int not_multiple3_count = multiples_of_3(false, array, size, not_multiple3_array);
    
    printf("3의 배수가 아닌 수: ");
    for (int i = 0; i < not_multiple3_count; i++) {
        printf("%d ", not_multiple3_array[i]);
    }
    printf("\n");
    return 0;
}