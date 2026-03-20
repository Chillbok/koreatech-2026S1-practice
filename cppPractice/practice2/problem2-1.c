#include <stdio.h>

void print_row_line(int column_size) {
    for (int i = 0; i < column_size * 8 + 1; i++) printf("-");
    printf("\n");
}

void print_scores(const char* student_names[], const float scores[][4], const char* score_names[], const int student_count, const int score_count) {
    printf("점수표\n");
    print_row_line(5);

    // 첫줄 작성
    printf("\t");
    printf("|");

    // 첫 열 출력
    for (int i = 0; i < score_count; i++) {
        printf("%s\t", score_names[i]);
        printf("|");
    }
    printf("\n");
    print_row_line(5);

    // 점수들 출력하기
    for (int i = 0; i < student_count; i++) {
        printf("%s\t", student_names[i]);
        printf("|");
        for (int j = 0; j < score_count; j++) {
            printf("%.1f\t", scores[i][j]);
            printf("|");
        }
        printf("\n");
        print_row_line(5);
    }
}

int main() {
    // 문자열 안전하게 출력하기 위해 빈칸 하나 추가함
    const char* student_names[] = { "철희", "철수", "영희", "영수" };
    const char* score_type_names[] = { "국어", "영어", "수학", "도덕" };
    float scores[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%s의 %s 점수를 입력하세요. : \n", student_names[i], score_type_names[j]);
            scanf("%f", &scores[i][j]);
        }
    }
    print_scores(student_names, scores, score_type_names, 4, 4);
    
    // 학생별 평균 구하기
    float score_average[4];
    for (int i = 0; i < 4; i++) score_average[i] = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            score_average[j] = scores[i][j];
        }
    }
    for (int i = 0; i < 4; i++) score_average[i] /= 4;
    
    // 과목 평균 구하기
    float subject_average[] = {0, 0, 0, 0};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            score_average[i] += scores[j][i];
        }
        score_average[i] /= 4;
    }
    
    printf("학생평균점수표\n");
    print_row_line(5);
    for (int i = 0; i < 4; i++) {
        printf("%s의 평균: %.1f\n", student_names[i], score_average[i]);
    }
    
    printf("과목평균점수표\n");
    print_row_line(5);
    for (int i = 0; i < 4; i++) {
        printf("%s의 평균: %.1f\n", score_type_names[i], subject_average[i]);
    }

    return 0;
}