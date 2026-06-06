#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <string>
using std::string;

template <typename T>
class SimpleArray {
private:
	T arr[5];
	int count;
public:
	SimpleArray() : count(0) {}
	void add(T data) {
		if (count >= 5) {
			std::cerr << "[Error] 배열이 가득 찼음. 데이터 추가 불가." << endl;
			return;
		}
		arr[count] = data;
		count++;
	}
	T get(int index) {
		if (index < 0) return arr[0];
		else if (index >= count) return arr[count-1];
		else { return arr[index]; }
	}
	void showAll() {
		for (int i = 0; i < count; i++) cout << get(i) << " ";
		cout << endl;
	}
};

int main()
{
    // 1. 정수형 배열 객체 생성 및 테스트
    cout << "--- Integer Array ---" << endl;
    SimpleArray<int> iArr;
    iArr.add(10); iArr.add(20); iArr.add(30);
    iArr.showAll();

    // 2. 실수형 배열 객체 생성 및 테스트
    cout << "\n--- Double Array ---" << endl;
    SimpleArray<double> dArr;
    dArr.add(1.1); dArr.add(2.2); dArr.add(3.3);
    dArr.showAll();

    // 3. 문자열형 배열 객체 생성 및 테스트
    cout << "\n--- String Array ---" << endl;
    SimpleArray<string> sArr;
    sArr.add("Apple"); sArr.add("Banana"); sArr.add("Cherry");
    sArr.showAll();

    return 0;
}