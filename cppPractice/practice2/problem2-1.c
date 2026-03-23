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

float get_average(float selected[], int size) {
    float result = 0;
    for (int i = 0; i < size; i++) {
        result += selected[i];
    }
    return result / size;
}

void print_arr(float arr[], int size) {
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("%.1f\t", arr[i]);
    }
    printf("\n");
}

void set_student_scores(int max_student_count, int max_score_count, const char* student_names[], const char* score_names[], float scores[][max_score_count]) {
    for (int student_count = 0; student_count < max_student_count; student_count++) {
        for (int score_count = 0; score_count < max_score_count; score_count++) {
            printf("%s의 %s 점수를 입력하세요: ", student_names[student_count], score_names[score_count]);
            scanf("%f", &scores[student_count][score_count]);
        }
    }
}

int main() {
    const char* student_names[] = { "철희", "철수", "영희", "영수" };
    const char* subject_names[] = { "국어", "영어", "수학", "도덕" };
    float scores[4][4];
    set_student_scores(4, 4, student_names, subject_names, scores);
    print_scores(student_names, scores, subject_names, 4, 4);
    
    // 학생별 평균 구하기
    float student_score_average[4];
    for (int i = 0; i < 4; i++) {
        float selected[4];
        for (int j = 0; j < 4; j++) {
            selected[j] = scores[i][j];
        }
        student_score_average[i] = get_average(selected, 4);
    }

    // 과목 평균 구하기
    float subject_score_average[4];
    for (int i = 0; i < 4; i++) {
        float selected[4];
        for (int j = 0; j < 4; j++) {
            selected[j] = scores[j][i];
        }
        subject_score_average[i] = get_average(selected, 4);
    }
    
    printf("\n학생평균점수표\n");
    print_row_line(5);
    for (int i = 0; i < 4; i++) {
        printf("%s의 평균: %.1f\n", student_names[i], student_score_average[i]);
    }
    
    printf("\n과목평균점수표\n");
    print_row_line(5);
    for (int i = 0; i < 4; i++) {
        printf("%s의 평균: %.1f\n", subject_names[i], subject_score_average[i]);
    }

    return 0;
}