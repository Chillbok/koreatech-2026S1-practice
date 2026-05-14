#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <cstring>

class NameCard {
protected:
    char* name;
    char* phone_number;
    
    char* changeCharTo(const char* s);
public:
    // 기본 생성자
    NameCard(const char* name);
    // 소멸자
    ~NameCard();
    void showInfo() const;
    // getter 함수들
    const char* getName() const { return name; }
};

char* NameCard::changeCharTo(const char* s) {
    if (!s) return nullptr;
    char* temp = new char[strlen(s) + 1];
    strcpy(temp, s);
    return temp;
}

NameCard::NameCard(const char* name) {
    this->name = changeCharTo(name);
}

NameCard::~NameCard() {
    delete[] name;
    delete[] phone_number;
    cout << "[System] NameCard(Base) 자원 해제 완료" << endl;
}

void NameCard::showInfo() const {
    cout << "이름: " << name << endl;
}