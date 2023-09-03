#include<iostream>

//std::unique_ptr своими руками

template <class T>
class unique_ptr {
private:
	T* pointer;
	
public:
	unique_ptr(T* raw) : pointer(raw) {};
	~unique_ptr() {
		delete pointer;
	}

	unique_ptr(unique_ptr&) = delete; //prohibit copy constr 
	unique_ptr& operator=(const unique_ptr&) = delete; //prohibit operator =

	//overload operator *
	T const & operator*() {
		return *pointer;
	}
	operator T* ()const { return pointer; };

	//release()
	T* release() {
		//free ownership
		//return raw_pointer
		T* new_ptr = pointer;
		delete pointer;
		pointer = nullptr;
		return new_ptr;
	}
};

int main() {
	int* raw = new int[10];
	for (int i = 0; i < 10; ++i) {
		raw[i] = i * i;
	}

	unique_ptr<int> ptr(new int(3));
	auto it = *ptr;
	std::cout << it << std::endl;
	raw = ptr.release();

	std::cout << ptr << ' ' << raw;

	return 0;
}