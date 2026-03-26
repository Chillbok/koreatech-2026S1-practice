#include <stdio.h>
#include <stdlib.h>

// strlen()을 사용하면 되지만, 포인터 사용에 익숙해지기 위해 문자열 길이 구하는 함수를 직접 구현해봤음.
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
    char* result = (char*)malloc(len+1);
    result[len] = '\0';
    for (int i = 0;  i < len; i++) {
        result[i] = src[len-1-i];
    }
    return result;
}

int main() {
    char source[] = "InternetMedia Engineering";
    int source_length = get_string_length(source);
    char* result = reverse_string(source, source_length);
    printf("원본 문자열: %s\n", source);
    printf("변경된 문자열: %s\n", result);
    free(result);
    
    // 한글 출력 시도
    char korean_source[] = "안녕세상아";
    int korean_source_length = get_string_length(korean_source);
    char* korean_result = reverse_string(korean_source, korean_source_length);
    printf("원본 문자열: %s\n", korean_source);
    printf("변경된 문자열: %s\n", korean_result);
    free(korean_result);
    return 0;
}