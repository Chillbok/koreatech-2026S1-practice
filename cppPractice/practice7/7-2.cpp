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
	void ShowStatus();
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

int main() {
	return 0;
}