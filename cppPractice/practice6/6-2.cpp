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
		cout << "도서명: " << title;
		cout << " | ";
		cout << "출판사:";
		cout << " | ";
		cout << "가격: " << price << "원";
		cout << endl;
	}
	
	// 반환된 값을 수정하지 못하게 하기 위해서, 그리고 함수 내부에서 수정을 못하게 하기 위해서 const를 두번 사용함
	const char* get_name() const { return (title != NULL) ? title : ""; }
	const char* get_company() const { return (company != NULL) ? company : ""; }
	int get_price() const { return price; }
};

void find_cheaper(Book& a, Book& b) {
	int a_price = a.get_price();
	int b_price = b.get_price();

	cout << "=== 가격 비교 결과 ===";
	cout << a.get_company() << " vs " << b.get_company() << endl;
	
	if (a_price == b_price) cout << "두 책의 가격이 같습니다" << endl;
	else if (a_price < b_price) cout << "더 저렴한 책: " << a.get_name() << "." << a.get_company() << endl;
	else if (a_price > b_price) cout << "더 저렴한 책: " << b.get_name() << "." << b.get_company() << endl;
}

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
	find_cheaper(book1, book2);
	find_cheaper(book1, book3);
	find_cheaper(book2, book3);

	return 0;
}