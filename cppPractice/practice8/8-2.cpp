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
    void ShowData(void) {
        cout << "계좌번호: " << acc_num << endl;
        cout << "계좌잔액: " << balance << endl;
    }
};

int main() {
	return 0;
}
