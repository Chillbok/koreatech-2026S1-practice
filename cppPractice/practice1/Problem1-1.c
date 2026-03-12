#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int size = 10;
    int array[size], multiple3_array[size], not_multiple3_array[size];

    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        int num = rand() % 101;
        array[i] = num;
    }
    return 0;
}