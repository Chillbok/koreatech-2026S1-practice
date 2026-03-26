#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

/*
인공지능에게 한글 문자는 어떻게 세고, 어떻게 변경해야 하는지 물어봤음.
마찬가지로 문자열에 대해 조금 더 확실히 배워보기 위해 라이브러리 또는 헤더 파일 함수의 활용을 최소화해서 구현해보고 싶다고 부탁했음.
*/

// UTF-8 문자의 바이트 길이를 판별하는 함수
int get_utf8_char_length(const char* c) {
    if (c == NULL) return 0;
    unsigned char first_byte = (unsigned char)* c;
    
    // 비트 연산? 과 비트 이동이라는 것을 사용하여 상위 비트를 검사한다고 함.
    
    /*
    인공지능에게 이 부분이 작동하는 원리를 설명해달라고 요청했음.
    UTF-8 형식 문자의 인코딩 규칙을 알아야 한다고 함.

    UTF-8은 문자에 따라 1바이트에서 4바이트까지 가변적인 길이를 가진다고 함.
    어떤 문자가 몇 바이트인지 알기 위해, 첫 번째 바이트의 가장 왼쪽에 특별한 패턴을 집어넣는다고 한다.
    - 0xxxxxxx 비트 패턴을 가지는 문자는 1바이트 문자이다. 여기에는 영문자, 숫자, 일부 기호들이 들어간다.
    - 110xxxxx 비트 패턴을 가지는 문자는 2바이트 문자이다. 여기에는 추가된 라틴 문자, 그리스어, 히브리어 등이 포함된다.
    - 1110xxxx 비트 패턴을 가지는 문자는 한글, 일본어, 중국어 등 대부분의 아시아 문자들이 포함된다. 즉, 이번 질문의 의도인 한글은 여기에 포함된다.
    - 11110xxx 비트 패턴을 가지는 문자들은 이모지, 고대 문자 등이 포함된다. 따라서 이번에 인공지능에게 질문한 것과는 큰 연관이 없다.
    */
    // 1바이트 문자: 0xxxxxxx
    // 비트를 오른쪽으로 7회 이동시키면 상위 1비트만 남게 된다. 이 값이 0이면 1바이트 문자이므로 1을 출력한다.
    if ((first_byte >> 7) == 0x00) return 1;
    // 2바이트 문자: 110xxxxx
    // 비트를 오른쪽으로 5번 이동시켜 상위 3비트만 남겼을 때, 이 값이 이진수 110(16진수로 0x06)이라면 2를 반환한다.
    else if ((first_byte >> 5) == 0x06) return 2;
    // 3바이트 문자 (한글 포함): 1110xxxx
    // 비트를 오른쪽으로 4번 이동시켜 상위 4비트만 남긴다. 이때 이 값이 1110, 이진수로 0x0E라면 3바이트 문자이므로 3을 반환한다.
    else if ((first_byte >> 4) == 0x0E) return 3;
    // 4바이트 문자: 11110xxx
    // 비트를 오른쪽으로 3번 이동시키면 상위 5비트만 남게 된다. 이 값이 이진수로 11110이라면, 16진수로 0x1E라면 4바이트 문자이므로 4를 반환한다.
    else if ((first_byte >> 3) == 0x1E) return 4;
    
    // 만약 잘못된 바이트라면 1바이트로 간주
    return 1;
}

int count_utf8_characters(const char* s) {
    if (s == NULL) return 0;
    int char_count = 0;
    int byte_offset = 0;
    while (s[byte_offset] != '\0') {
        int char_len = get_utf8_char_length(&s[byte_offset]);
        byte_offset += char_len;
        char_count++;
    }
    return char_count;
}

char* reverse_string_utf8(const char* src) {
    if (src == NULL) return NULL;
    
    // 문자 수와 전체 바이트 길이 계산
    int total_bytes = strlen(src);
    int char_count = count_utf8_characters(src);

    // 문자의 시작 포인터와 길이를 저장할 배열 생성
    const char** char_pointers = (const char**)malloc(sizeof(const char*) * char_count);
    int* char_lengths = (int*)malloc(sizeof(int) * char_count);
    
    // 메모리 할당 실패할 경우
    if (char_pointers == NULL || char_lengths == NULL) {
        free(char_pointers);
        free(char_lengths);
        return NULL;
    }
    
    // 문자열을 한 번 순회하며 배열 채우기
    int current_char = 0;
    int current_byte = 0;
    while (src[current_byte] != '\0') {
        int char_len = get_utf8_char_length(&src[current_byte]);
        char_pointers[current_char] = &src[current_byte];
        char_lengths[current_char] = char_len;
        current_byte += char_len;
        current_char++;
    }
    
    // 결과 문자열을 위한 메모리 할당(원본과 동일한 바이트 수 + null)
    char* result = (char*)malloc(total_bytes + 1);
    if (result == NULL) {
        // 메모리 할당 실패 처리
        free(char_pointers);
        free(char_lengths);
        return NULL;
    }
    
    // 저장된 배열을 역순으로 순회하며 결과를 문자열에 복사
    int result_byte_offset = 0;
    for (int i = char_count - 1; i >= 0; i--) {
        for (int j = 0; j < char_lengths[i]; j++) {
            result[result_byte_offset] = char_pointers[i][j];
            result_byte_offset++;
        }
    }
    
    // null 종결자를 추가하고 리소스를 해제
    result[total_bytes] = '\0';
    free(char_pointers);
    free(char_lengths);
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
    printf("원본 문자열: %s\n", korean_source);
    char* korean_result = reverse_string_utf8(korean_source);
    if (korean_result != NULL) {
        printf("변경된 문자열(한글): %s\n", korean_result);
        free(korean_result);
    }

    return 0;
}