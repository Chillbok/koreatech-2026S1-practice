#include <stdio.h>
#include <stdlib.h>

int get_string_length(const char* s) {
    int count = 0;
    const char* word = s;
    while (*word != '\0') {
        word++;
        count++;
    }
    // 맨 뒤의 null 값은 제외되어 출력되기 때문에, 잘 생각해야 함.
    // 예를 들어, "hello"를 출력한다면, 5가 출력될 것임. 하지만 배열의 실제 길이는 6임.
    return count;
}

char* reverse_string(const char* src, int len) {
    
}

int main() {
    char source[] = "InternetMedia Engineering";
    char* result = reverse_string(source, strlen(source));
    printf("원본 문자열: %s\n", source);
    printf("변경된 문자열: %s\n", result);
    free(result);
    return 0;
}