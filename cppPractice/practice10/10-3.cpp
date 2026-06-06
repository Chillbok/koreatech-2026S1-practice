#include<iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

class Person
{
	string name;
	string phone;
	int age;

public:
	Person(string _name, string _phone, int _age);
	Person(const Person& p);
	void ShowData();
};

Person::Person(const Person& p)
{
	name = p.name;
	phone = p.phone;
	age = p.age;
}

Person::Person(string _name, string _phone, int _age)
{
	name = _name;
	phone = _phone;
    age=_age;
}
void Person::ShowData()
{
    cout<<"name: "<<name<<endl;
    cout<<"phone: "<<phone<<endl;
    cout<<"age: "<<age<<endl;
}
int main()
{
    Person p1("KIM", "013-333-5555", 22);
    Person p2=p1;
    p1.ShowData();
    p2.ShowData();
    return 0;
} 

