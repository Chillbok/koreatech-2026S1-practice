#include <stdio.h>

struct user_info {
    char id[16];
    char password[16];
    int stage_score_1;
    int stage_score_2;
    int stage_score_3;
    int stage_score_4;
    int stage_score_5;
    int mp;
    int hp;
};

void read_file(struct user_info data[], int data_size) {
    FILE* file_ptr = fopen("user.txt", "r");
    if (file_ptr == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return;
    }
    for (int i = 0; i < data_size; i++) {
        fscanf(file_ptr, "%s %s %d %d %d %d %d %d %d",
            data[i].id,
            data[i].password,
            &data[i].stage_score_1,
            &data[i].stage_score_2,
            &data[i].stage_score_3,
            &data[i].stage_score_4,
            &data[i].stage_score_5,
            &data[i].mp,
            &data[i].hp
        );
    }
    fclose(file_ptr);
}

void print_line(int line_length) {
    while (line_length--) printf("-");
    printf("\n");
}
void print_user(struct user_info data[], int data_length) {
    printf("%s\t%s\t%s\t%s\t%s\n", "아이디", "비밀번호", "5개스테이지별 점수", "마법 포인트", "체력 포인트");
    print_line(64);
    for (int i = 0; i < data_length; i++) {
        printf("%15s\t%15s\t%d, %d, %d, %d, %d\t%d\t%d\n",
            data[i].id,
            data[i].password,
            data[i].stage_score_1,
            data[i].stage_score_2,
            data[i].stage_score_3,
            data[i].stage_score_4,
            data[i].stage_score_5,
            data[i].mp,
            data[i].hp
        );
    }
    print_line(64);
}

int main() {
    int user_count = 3;
    struct user_info data[user_count];
    read_file(data, user_count);
    print_user(data, user_count);
    return 0;
}