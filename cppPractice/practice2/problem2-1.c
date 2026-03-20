#include <stdio.h>

void print_scores(const char* student_names[], const float scores[][4], const char* score_names[], const int student_count, const int score_count) {
    // 첫줄 작성
    printf("\t");
    printf("|");

    // 첫 열 출력
    for (int i = 0; i < score_count; i++) {
        printf("%s\t", score_names[i]);
        printf("|");
    }
    printf("\n");
    
    for (int i = 0; i < (score_count+1) * 8; i++) {
        printf("-");
    }
    printf("-\n");

    // 점수들 출력하기
    for (int i = 0; i < student_count; i++) {
        printf("%s\t", student_names[i]);
        printf("|");
        for (int j = 0; j < score_count; j++) {
            printf("%.1f\t", scores[i][j]);
            printf("|");
        }
        printf("\n");
    }
}

int main() {
    int student_count = 4;
    int score_type_count = 4;
    // 문자열 안전하게 출력하기 위해 빈칸 하나 추가함
    const char* student_names[] = { "철희", "철수", "영희", "영수" };
    const char* score_type_names[] = { "국어", "영어", "수학", "도덕" };
    float scores[student_count][score_type_count];
    for (int i = 0; i < student_count; i++) {
        for (int j = 0; j < score_type_count; j++) {
            printf("%s의 %s 점수를 입력하세요. : \n", student_names[i], score_type_names[j]);
            scanf("%f", &scores[i][j]);
        }
    }
    print_scores(student_names, scores, score_type_names, student_count, score_type_count);
    
    // 점수별 평균 구하기
    float score_average[score_type_count];
    for (int i = 0; i < score_type_count; i++) score_average[i] = 0;
    for (int i = 0; i < student_count; i++) {
        for (int j = 0; j < score_type_count; j++) {
            score_average[j] = scores[i][j];
        }
    }
    for (int i = 0; i < score_type_count; i++) score_average[i] /= student_count;

    return 0;
}