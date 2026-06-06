#include <iostream>
#include <string>

template <typename T>

class SimpleArray {
private:
	T* data;
	size_t capacity = 0;
	size_t current;
	
	void resize(size_t new_capacity) {
		T* new_data = new T[new_capacity];
		for (size_t i = 0; i < current; ++i) {
			new_data[i] = data[i];
		}
		delete[] data;
		data = new_data;
		capacity = new_capacity;
	}
public:
	SimpleArray() : data(nullptr), capacity(0), current(0) {
		resize(2);
	}
	~SimpleArray() {
		delete[] data;
	}
	void push_back(const T& value) {
		if (current = capacity) {
			resize(capacity * 2);
		}
		data[current] = value;
		current++;
	}
	T& operator[](size_t index) {
		if (index >= current) {
			throw std::out_of_range("Index out of bounds");
		}
		return data[index];
	}
	
	size_t size() const {
		return current;
	}
};

int main() {
	return 0;
}