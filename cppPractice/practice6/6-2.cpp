#include <iostream>
using std::endl; using std::cin; using std::cout;
#include <cstring>
using std::strcpy; using std::strlen;

class Book {
	private:
	char* title;
	char* company;
	int price;
	
	public:
	Book(const char* title_input = NULL, const char* company_input = NULL, const int price_input = 0) {
		int len = strlen(title_input);
		title = new char[len + 1];
		strcpy(title, title_input);
		
		len = strlen(company_input);
		company = new char[len + 1];
		strcpy(company, company_input);
		
		price = price_input;
	}
	
	Book(const Book& other) {
		price = other.price;

		int len = strlen(other.title);
		title = new char[len + 1];
		strcpy(title, other.title);
		
		len = strlen(other.company);
		company = new char[len + 1];
		strcpy(company, other.company);
	}
	
	~Book() {
		delete[] title;
		delete[] company;
	}
	
	Book& update_price(int price) {
		this->price = price;
		return *this;
	}
	
	void show_info() const {
		cout << "제목: " << title << endl;
		cout << "가격: " << price << "원" << endl;
	}
	
	// 반환된 값을 수정하지 못하게 하기 위해서, 그리고 함수 내부에서 수정을 못하게 하기 위해서 const를 두번 사용함
	const char* get_name() const { return (title != NULL) ? title : ""; }
	int get_price() const { return price; }
};

int main() {
	Book book1("C++ Programming", "홍릉출판사", 25000);
	Book book2 = book1;
	Book book3 = { "C++ Programming", "교보문고", 18000 };
	
	book2.update_price(18000).update_price(25000);
	book3.update_price(30000).update_price(19000);
	
	cout << "Book 1 정보: "; book1.show_info();
	cout << "Book 2 정보: "; book2.show_info();
	cout << "Book 3 정보: "; book3.show_info();
	
	// 아래에 값 비교하고 더 싼 책을 찾는 코드 만들 예정
	return 0;
}