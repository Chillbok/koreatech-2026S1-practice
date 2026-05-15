#include <cstring>
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <cstring>

class Account {
protected:
    int acc_num; // 계좌 번호
    int balance; // 계좌 잔액
    char name[20]; // 이름
public:
    Account(int _acc_num, int _balance, const char* _name) {
        acc_num = _acc_num;
        balance = _balance;
        strcpy(name, _name);
    }
    virtual void ShowData(void) const {
        cout << "계좌번호: " << acc_num << endl;
        cout << "계좌잔액: " << balance << endl;
    }
    virtual ~Account() {}
};

class LAccount : public Account {
private:
    // 고객별 현금 서비스 한도 정보
    int credit;
    // 고객별 신용도 정보 (0 ~ 1)
    float credit_rate;
public:
    LAccount(int _acc_num, int _balance, const char* _name, int credit, float credit_rate) : Account(_acc_num, _balance, _name) {
        this->credit = credit;
        this->credit_rate = credit_rate;
    }
    void ShowData() const override {
        cout << "이름: " << name << endl;
        cout << "계좌번호: " << acc_num << endl;
        cout << "계좌잔액: " << balance << endl;
        cout << "현금서비스 한도: " << credit << endl;
        cout << "신용도: " << credit_rate << endl;
        cout << "---------------------------------" << endl;
    }
};

int main() {
    LAccount user1(100, 5000, "김삼순", 2000, 1.0);
    LAccount user2(101, -2000, "홍길동", 100, 0.2);

    cout << "=== 계좌 정보 출력 ===" << endl;
    user1.ShowData();
    user2.ShowData();

	return 0;
}
