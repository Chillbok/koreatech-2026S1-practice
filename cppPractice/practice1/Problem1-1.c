#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int multiples_of_3(int arr[], int size, int result[]) {
    int result_count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 3 == 0) {
            result[result_count] = arr[i];
            result_count += 1;
        }
    }
    return result_count;
}

int main() {
    int size = 10;
    int array[size], not_multiple3_array[size];

    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        int num = rand() % 101;
        array[i] = num;
    }
    
    int multiple3_array[size];
    int multiple3_count = multiples_of_3(array, size, multiple3_array);
    
    // 배열 요소 출력
    printf("array: ");
    for (int i = 0; i < size; i++) {
        printf("%d, ", array[i]);
    }
    printf("\n");
    
    printf("3의 배수: ");
    for (int i = 0; i < multiple3_count; i++) {
        printf("%d, ", multiple3_array[i]);
    }
    printf("\n");
    return 0;
}