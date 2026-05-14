#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <cstring>
#include <vector>
using std::vector;
#include <typeinfo>

class NameCard {
protected:
    char* name = nullptr;
    char* phone_number = nullptr;

    // 이미 있는 값을 바꾸는 게 목적이라면 이걸 쓰면 안됨. 값 업데이트 전용 함수 필요.
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
        cout << "[System] RankNameCard(Derived) 직급 지원 해제 완료" << endl;
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

class NameCardController {
private:
    vector<NameCard*> card_vector;
public:
    NameCardController() {
        card_vector.resize(0);
    }
    void addCard(NameCard* card) {
        card_vector.push_back(card);
    }
    
    void showAll() {
        cout << "[전체 명함 출력]" << endl;
        for (NameCard* card : card_vector) {
            card->showInfo();
        }
        cout << endl;
    }
    
    void processBonusTask() {
        cout << "=== RTTI 기반 보너스 대상자 정밀 점검 ===" << endl;
        int i = 0;
        for (auto card : card_vector) {
            ++i;
            char* card_type = nullptr;
            if (typeid(*card) == typeid(NameCard)) {
                card_type = new char[strlen("class NameCard") + 1];
                strcpy(card_type, "class NameCard");
            }
            else if (typeid(*card) == typeid(RankNameCard)) {
                card_type = new char[strlen("class RankNameCard") + 1];
                strcpy(card_type, "class RankNameCard");
            }

            cout << i <<"번 객체 정보 확인중..." << endl;
            cout << " - 실제 타입명: " << card_type << endl;
            cout << " - 결과: ";
            if (typeid(*card) == typeid(NameCard)) {
                cout << "일반 명함입니다. 보너스 대상자에서 제외됩니다." << endl;
            }
            else if (typeid(*card) == typeid(RankNameCard)) {
                cout << card->getName() << "님은 직급 명함 소지자입니다.";
                // 자식클래스타입으로 형변환하여 함수 호출
                static_cast<RankNameCard*>(card)->checkBonus();
            }
            cout << "--------------------------" << endl;

            // 메모리 누수 방지를 위해 꼭 필요한 과정이므로 삭제하지 말것.
            delete[] card_type;
        }
    }
    
    ~NameCardController() {
        for (NameCard* card : card_vector) delete card;
    };
};

int main() {
    NameCardController manager;
    
    // 1. 다형성을 이용한 다양한 객체 추가
    manager.addCard(new RankNameCard("김철수", "부장"));
    manager.addCard(new NameCard("이영희")); // 일반명함으로 보너스지급 제외
    manager.addCard(new RankNameCard("박민수", "대리"));

    // 2. 전체 출력 (가상 함수 동작 확인)
    manager.showAll();
    
    // 3. RTTI 동작 확인 (타입 식별 및 캐스팅 확인: 보너스 지급여부 체크 및 보너스 지급)
    manager.processBonusTask();

    return 0;
}