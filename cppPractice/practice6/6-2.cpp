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
		company = new[len + 1];
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
};

int main() {
	return 0;
}