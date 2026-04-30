#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <vector>
using std::vector;

class ObjectTracker {
private:
	static int currentCount;
	static int totalCount;
	int id;
public:
	ObjectTracker();
	~ObjectTracker();
	static void ShowStatus();
};

int ObjectTracker::currentCount = 0;
int ObjectTracker::totalCount = 0;

ObjectTracker::ObjectTracker() {
	currentCount++; totalCount++;
	id = totalCount;
	cout << "[ID: " << id << "] 객체 생성 (" << "현재 생존: " << currentCount << "개)" << endl;
}
ObjectTracker::~ObjectTracker() {
	currentCount--;
	cout << "[ID: " << id << "] 객체 소멸 (현재 생존: " << currentCount << "개)" << endl;
}

void ObjectTracker::ShowStatus() {
	cout << "--- 실시간 시스템 상태 ---" << endl;
	cout << "현재 메모리 내 객체: " << currentCount << " 개" << endl;
	cout << "누적 생성된 총 객체: " << totalCount << " 개" << endl;
	cout << "--------------------------" << endl;
}

int main() {
	cout << "프로그램 시작" << endl;
	ObjectTracker::ShowStatus();

	cout << "1. 객체 a, b 생성" << endl;
	ObjectTracker a;
	ObjectTracker b;

	{
		cout << "\n2. 블록 내부 진입 및 객체 c 생성" << endl;
		ObjectTracker c;
		ObjectTracker::ShowStatus();
		
		cout << "3. 블록 종료 (지역 객체 c가 소멸됩니다)" << endl;
	}
	
	cout << "\n4. 블록 밖에서의 상태 확인" << endl;
	ObjectTracker::ShowStatus();
	cout << "5. 프로그램 종료 (a, b가 소멸됩니다)" << endl;
	return 0;
}