#include <iostream>
#include <tuple>

template<typename T>
class table {
private:
	T** t;
	int a;
	int b;

public:

	table(int a, int b) {
		this->a = a;
		this->b = b;
		t = new T*[a];
		for (size_t i = 0; i < a; i++) {
			t[i] = new T[b];
		}
	}

	~table() {
		for (size_t i = 0; i < a; i++) {
			delete[] t[i];
		}
		delete t;
	}

	std::tuple<int, int> Size() const{
		return (a, b);
	}

	T* operator[](int a) const{
		return t[a];
	}

	T* operator[](int a) {
		return t[a];
	}
};

int main() {
	auto test = table<int>(2, 3);
	test[0][0] = 4;
	std::cout << test[0][0];
}