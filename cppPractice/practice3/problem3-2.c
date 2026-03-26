#include <stdio.h>
#include <stdlib.h>

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