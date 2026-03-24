#include <stdio.h>

void sort_strings(char *s[], int size) {

}

void change_by_alphabet(char **was_front, char **was_back) {
    // 아스키 코드 기준 a < b < c < d 순서니까, 더 크면 뒤로 가야함
    // 앞쪽에 있던 게 더 크면 뒤로 감
    if (*was_front[0] > *was_back[0]) {
        char *temp = *was_front;
        *was_front = *was_back;
        *was_back = temp;
    }
}

int main() {

    return 0;
}