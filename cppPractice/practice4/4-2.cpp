#include <iostream>
using std::cout; using std::cin; using std::endl;

struct Student {
    char name[20];
    int id;
    int scores[10];
};

int const name_length = 20;
int const score_count = 10;

void printExcellentStudent(Student& const selected_student) {
    float result = 0;
    for (int i = 0; i < score_count; i++) result += selected_student.scores[i];
    result /= score_count;;
    
    cout << "이름: " << selected_student.name << " (평균: " << (int)result << "점) ";

    // 학생 수준 판별 후 출력
    cout << "결과: ";
    (result >= 90) ? cout << "우수" : cout << "일반";
    cout << "학생입니다!" << endl;
}

void addBonusPoint(Student& student, int bonus) {
    for (int i = 0; i < score_count; i++) student.scores[i] += bonus;
}

int main() {
    // 1. 학생 배열 선언 및 초기화
    Student stdList[2] = {
        {"Lee K.H.", 20260001, {85, 88, 82, 90, 87, 85, 88, 84, 89, 87}},
        {"Park S.Y.", 20260002, {95, 98, 92, 94, 96, 95, 97, 93, 99, 95}}
    };
    
    // 2. 보너스 전 전체 명단 출력
    cout << "--- [1차 성적 확인(전체)] ---" << endl;
    for (int i = 0; i < 2; i++) printExcellentStudent(stdList[i]);
    
    // 3. 첫 번째 학생(stdList[0])에게 보너스 부여
    cout << "\n>> " << stdList[0].name << " 학생에게 보너스 10점 부여 중..." << endl;
    addBonusPoint(stdList[0], 10);
    
    // 4. 보너스 후 전체 명단 재확인
    cout << "\n--- [2차 성적 확인 (전체)] ---" << endl;
    for (int i = 0; i < 2; i++) printExcellentStudent(stdList[i]);
    return 0;
}