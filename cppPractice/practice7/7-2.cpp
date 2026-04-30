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
	ObjectTracker::ShowStatus();
	ObjectTracker a;
	ObjectTracker::ShowStatus();
	return 0;
}