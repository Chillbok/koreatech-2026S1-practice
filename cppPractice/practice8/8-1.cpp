#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <cstring>

class NameCard {
protected:
    char* name = nullptr;
    char* phone_number = nullptr;

    char* changeCharTo(const char* s) {
        if (!s) return nullptr;
        char* temp = new char[strlen(s) + 1];
        strcpy(temp, s);
        return temp;
    }

public:
    // 기본 생성자
    NameCard(const char* name) {
        this->name = changeCharTo(name);
    }

    // 소멸자
    virtual ~NameCard() {
        delete[] name;
        delete[] phone_number;
        cout << "[System] NameCard(Base) 자원 해제 완료" << endl;
    }

    virtual void showInfo() const {
        cout << "이름: " << name << endl;
    }

    // getter 함수들
    const char* getName() const { return name; }
};

class RankNameCard : public NameCard {
private:
    char* rank = nullptr;
public:
    RankNameCard(const char* name, const char* rank) : NameCard(name) {
        this->rank = changeCharTo(rank);
    }
    ~RankNameCard() {
        delete[] rank;
    }
    
    void showInfo() const override {
        cout << "이름: " << name << " | 직급: " << rank << endl;
    }
    
    // RTTI 실습을 위한 자식전용함수
    void checkBonus() const {
        cout << " -> [알림: 본인 확인 완료. 연말 특별 보너스 지급 대상자입니다.]" << endl;
    }
};

int main() {
    NameCard junho("이준호");
    junho.showInfo();
    
    RankNameCard junho_kim("김준호", "CEO");
    junho_kim.showInfo();
    return 0;
}