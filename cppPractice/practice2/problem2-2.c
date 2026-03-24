#include <stdio.h>
#include <stdbool.h>
void change_by_alphabet(char **was_front, char **was_back) {
    // 아스키 코드 기준 a < b < c < d 순서니까, 더 크면 뒤로 가야함
    // 앞쪽에 있던 게 더 크면 뒤로 감
    if (*was_front[0] > *was_back[0]) {
        char *temp = *was_front;
        *was_front = *was_back;
        *was_back = temp;
    }
}

void sort_strings(char *s[], int size) {
    bool isChanged = false;

    // 버블 정렬
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) change_by_alphabet(&s[j], &s[j+1]);
    }
}

void print_array(char* title, char *arr[], int size) {
    printf("%s: ", title);
    for (int i = 0; i < size; i++) printf("%s ", arr[i]);
    printf("\n");
}

int main() {
    char *s[] = {"mycopy", "src", "dst"};
    print_array("정렬 전", s, 3);
    sort_strings(s, 3);
    print_array("정렬 후", s, 3);
    return 0;
}