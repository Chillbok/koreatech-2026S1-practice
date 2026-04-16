#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <cstring>
using std::strcpy;

class Book {
	private:
	char *title;

	public:
	// 매개변수가 제대로 선언되지 않았음.
	// Book(char*);
	// NULL 선언은 선언 부분에서만 해야 함
	Book(const char* str = NULL);
	~Book() {
		delete title;
	}
	void showtitle(void);
};

// NULL 선언을 제거함
Book::Book(const char *str) {
	int len;
	len = strlen(str);
	title = new char[len + 1];
	// 예제로 제공된 strcpy_s는 맥의 clang 컴파일러에서 인식하지 못하므로, strcpy를 사용하였음.
	strcpy(title, str);
}

void Book::showtitle(void) {
	cout << title << endl;
}

// C++ 표준에서는 더 이상 void main()을 지원하지 않는다고 알고 있음. 따라서 int main()으로 수정함.
int main(void) {
	Book book1("A C++ Programming");
	Book book2 = book1;
	
	book1.showtitle();
	book2.showtitle();
	return 0;
}