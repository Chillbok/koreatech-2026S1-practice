#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;

template <typename T>
T findMax(T arr[], int size) {
	T maxVal = arr[0];
	for (int i = 0; i < size; ++i) if (arr[i] > maxVal) maxVal = arr[i];
	return maxVal;
}

int main() {
	int iArr[] = {15, 42, 7, 23, 31};
	cout << "정수 배열 최대값: " << findMax(iArr, 5) << endl;

	double dArr[] = {3.14, 1.59, 5.35, 2.65};
	cout << "실수 배열 최대값: " << findMax(dArr, 4) << endl;

	string sArr[] = {"Orange", "Apple", "Zebra", "Banana"};
	cout << "문자열 배열 최대값(사전순): " << findMax(sArr, 4) << endl;
	return 0;
}