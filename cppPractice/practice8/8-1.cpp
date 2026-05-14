#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <cstring>

class NameCard {
protected:
    char* name;
    int phone_number;
    
    char* allocateAndCopy(const char* s) {
        if (!s) return nullptr;
        char* temp = new char[strlen(s) + 1];
        strcpy(temp, s);
        return temp;
    }
public:
    // 기본 생성자
    NameCard(const char* name, int phone_number) {
        this->name = allocateAndCopy(name);
        this->phone_number = phone_number;
    }
    // 복사생성자
    NameCard(const NameCard& other) {
        this->name = allocateAndCopy(other.name);
        this->phone_number = other.phone_number;
    }
    // 대입연산자
    NameCard& operator=(const NameCard& other) {
        if (this != &other) {
            char* new_name = allocateAndCopy(other.name);
            delete[] name;
            name = new_name;
            phone_number = other.phone_number;
        }
        return *this;
    }
    // 소멸자
    ~NameCard() {
        delete[] name;
    }
};
