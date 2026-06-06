#include <iostream>
#include <string>

template <typename T>

class SimpleArray {
private:
	// 데이터 저장할 변수
	T* arr[5];
	// 할당된 총 메모리 공간 크기
	int count = 5;
	// 현재 실제로 저장된 원소의 개수
	int current = 0;
public:
	void add(T data) {
		current++;
	}
};

int main() {
	return 0;
}