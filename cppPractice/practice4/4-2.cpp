#include <iostream>
using std::cout; using std::cin; using std::endl;

struct Student {
    char name[20];
    int id;
    int scores[10];
};

void printExcellentStudent(Student& selected_student, int name_length, int score_length) {
    float result = 0;
    for (int i = 0; i < score_length; i++) result += selected_student.scores[i];
    result /= score_length;
    
    cout << "이름: " << selected_student.name << " (평균: " << result << "점) ";

    // 학생 수준 판별 후 출력
    cout << "결과: ";
    if (result >= 90) cout << "우수";
    else cout << "일반";
    cout << "학생입니다!" << endl;
}

void addBonusPoint(Student& student, int bonus) {
    int const score_length = 10;
    for (int i = 0; i < score_length; i++) student.scores[i] += bonus;
}

int main() {
    // 1. 학생 배열 선언 및 초기화
    Student stdList[2] = {
        {"Lee K.H.", 20260001, {85, 88, 82, 90, 87, 85, 88, 84, 89, 87}},
        {"Park S.Y.", 20260002, {95, 98, 92, 94, 96, 95, 97, 93, 99, 95}}
    };
    
    // 2. 보너스 전 전체 명단 출력
    cout << "--- [1차 성적 확인(전체)] ---" << endl;
    for (int i = 0; i < 2; i++) printExcellentStudent(stdList[i], 20, 10);
    
    // 3. 첫 번째 학생(stdList[0])에게 보너스 부여
    cout << "\n>> " << stdList[0].name << " 학생에게 보너스 10점 부여 중..." << endl;
    addBonusPoint(stdList[0], 10);
    
    // 4. 보너스 후 전체 명단 재확인
    cout << "\n--- [2차 성적 확인 (전체)] ---" << endl;
    for (int i = 0; i < 2; i++) printExcellentStudent(stdList[i], 20, 10);
    return 0;
}