// custom container with inner iterator class
#include <iostream>
#include <algorithm>


template<class T>
class rkvector
{
	int _size = 0;
	T* _buffer = nullptr;

public:
	/*
	template<
		class Category,
		class T,
		class Distance = std::ptrdiff_t,(depressed c++17)
		class Pointer = T*,
		class Reference = T&
	> struct iterator;
	*/

	// inner iterator class
	class iterator : std::iterator<std::input_iterator_tag, T>
	{
		T* _ptr;
	public:
		explicit iterator(T* ptr) :_ptr(ptr) {}
		// ++ 연산자 경우 직접적인 값이 아니라 iterator 를 반환
		// * 연산자를 통해서만 직접적인 값을 반환

		iterator& operator++() { ++_ptr; return (*this); }
		iterator operator++(int) { iterator retval = *this; ++_ptr; return retval; }

		T& operator*() { return *_ptr; }
		bool operator==(iterator other) const { return _ptr == other._ptr; }
		bool operator!=(iterator other) const { return _ptr != other._ptr; }
	};


	// 생성자
	rkvector() {}
	rkvector(int size)
	{
		if (_buffer == nullptr)
		{
			std::cout << "dynamic allocate" << std::endl;
			_buffer = new T[size];

			// T()  <-어떤 의미 일까요?
			std::fill(_buffer, _buffer + size, T());
			_size = size;
		}
	}

	// 소멸자
	~rkvector()
	{
		if (_size > 1)
			delete _buffer;
		else
			delete[] _buffer;
	}


	int size() const
	{
		return _size;
	}

	T operator[](int index) const
	{
		return _buffer[index];
	}

	iterator begin()
	{
		return iterator(_buffer);
	}
	iterator end()
	{
		return iterator(_buffer + _size);
	}

	void fill(T&& val)
	{
		for (int i = 0; i < _size; ++i)
			_buffer[i] = val;
	}
};

int main()
{
	rkvector<int> vec(5);
	vec.fill(20);
	sort(vec.begin(), vec.end());
	for (rkvector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
	std::cout << "C++11 range based for loop" << std::endl;
	for (int element : vec)
	{
		std::cout << element << std::endl;
	}
	return 0;
}