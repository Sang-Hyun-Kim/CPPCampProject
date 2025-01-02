#pragma once
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <iterator>
using namespace std;
/* 필 수
- 클래스의 이름은 SimpleVector라고 합니다.
- 타입에 의존하지 않고 데이터를 받을수 있는 배열을 멤버변수로 갖습니다.
- 생성자는 아래와 같이 구현 합니다.
    - 기본 생성자는 크기가 10인 배열을 만듭니다.
    - 숫자를 하나 받는 생성자는 해당 숫자에 해당되는 크기의 배열을 만듭니다.
- 아래와 같은 멤버함수를 구현 합니다.
    - push_back  인자로 받은 원소를  맨 뒤에 추가 합니다. 반환값은 없습니다. 배열의 크기가 꽉 찼는데 원소가 더 들어올경우 아무 동작도 하지 않습니다.
    - pop_back은 벡터의 마지막 원소를 제거 합니다. 만약 제거할 원소가 없다면 아무 동작도 하지 않으며, 인자 및 반환값은 없습니다.
    - size는 인자가 없고 현재 원소의 개수를 반환합니다.
    - capacity 현재 내부 배열의 크기를 반환합니다.

구현을 한 뒤에 클래스의 구조는 아래와 같습니다.

*/

/* 도전 기능
- 복사 생성자를 구현 합니다.
- 아래 멤버함수를 추가로 변경/구현 합니다.
    - push_back에서 배열의 크기가 꽉 찼는데 원소가 더 들어올경우, 기존 배열보다 크기를 5만큼 더 늘리고 새로운 원소까지 추가됩니다.(기존에 있던 값도 유지되야 합니다.)
    - resize는 정수 하나를 인자로 받습니다.  해당 정수가 현재 배열의 크기보다 작으면 아무 동작도 하지 않습니다. 만약 현재 배열보다 크기가 크면 해당 값만큼 크기를 재할당 합니다.(기존 원소는 그대로 있어야 합니다.)
    - sortData는 내부 데이터를 정렬하는 함수 입니다. 직접 정렬하지 않고 STL의 sort함수를 활용해서 정렬 합니다.
*/
template<typename T>
class SimpleVector
{
public:

    SimpleVector(int _size = 10);
    SimpleVector(const SimpleVector& other);
    T& operator[](int idx); // [] 접근을 통한 값 출력
    ~SimpleVector();
    int size(); // 현재 원소 개수 반환
    int capacity(); // 현재 Capacity 반환
    void push_back(const T& _data);
    void pop_back();
    void resize(int _newCapacity);
    void sortData();
public:
    // STL 함수 사용을 위한 iterator 구현
    class Iterator
    {
    public:

        using iterator_category = random_access_iterator_tag;
        Iterator(T* ptr) : m_ptr(ptr) {}

        // Dereference operator
        T& operator*() const { return *m_ptr; }

        // Arrow operator
        T* operator->() const { return m_ptr; }

        // Increment operator (prefix)
        Iterator& operator++() {
            ++m_ptr;
            return *this;
        }

        // Increment operator (postfix)
        Iterator operator++(int) {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }

        // Decrement operator (prefix)
        Iterator& operator--() {
            --m_ptr;
            return *this;
        }

        // Decrement operator (postfix)
        Iterator operator--(int) {
            Iterator temp = *this;
            --(*this);
            return temp;
        }

        // Addition operator (iterator + int)
        Iterator operator+(int n) const {
            return Iterator(m_ptr + n);
        }

        // Subtraction operator (iterator - int)
        Iterator operator-(int n) const {
            return Iterator(m_ptr - n);
        }

        // Difference operator (iterator - iterator)
        ptrdiff_t operator-(const Iterator& other) const {
            return m_ptr - other.m_ptr;
        }

        // Comparison operators
        bool operator==(const Iterator& other) const { return m_ptr == other.m_ptr; }
        bool operator!=(const Iterator& other) const { return m_ptr != other.m_ptr; }
        bool operator<(const Iterator& other) const { return m_ptr < other.m_ptr; }
        bool operator<=(const Iterator& other) const { return m_ptr <= other.m_ptr; }
        bool operator>(const Iterator& other) const { return m_ptr > other.m_ptr; }
        bool operator>=(const Iterator& other) const { return m_ptr >= other.m_ptr; }

        // Subscript operator
        T& operator[](int idx) const {
            return *(m_ptr+idx);
        }

    private:
        T* m_ptr;
    };


    Iterator begin() { return Iterator(data); }
    Iterator end() { return Iterator(data + currentSize); }
    
private:
    int currentSize; // 현재 원소의 개수
    int currentCapacity; // 할당 받은 벡터의 크기
    T* data = nullptr;
};

template<typename T>
inline SimpleVector<T>::SimpleVector(int _size) 
    : currentSize(0), currentCapacity(_size)
{
    if (_size <= 0)
    {
        cout << "공간할당은 0 이상의 값이어야 합니다." << endl;
    }
    else
    {
        data = new T[currentCapacity];
    }
    
}

// 도전기능 복사 생성자
// other의 값을 받아 새로운 공간을 할당 받은 뒤 해당 값을 복사
template<typename T>
inline SimpleVector<T>::SimpleVector(const SimpleVector& other)
    : currentCapacity(other.currentCapacity), currentSize(other.currentSize)
{// this를 생성해서 other의 값을 복사
    data = new T[currentCapacity];
    std::copy(other.data, other.data + currentSize, this->data);
}

template<typename T>
inline T& SimpleVector<T>::operator[](int idx)
{
    if (idx < 0 || idx >= currentSize)
    {
        cout << "idx 접근 초과" << endl;
        exit(1);
    }
    else
    {
        return data[idx];
    }
}

template<typename T>
inline SimpleVector<T>::~SimpleVector()
{
    delete[] data;
}


template<typename T>
inline int SimpleVector<T>::size()
{
    return currentSize;
}

template<typename T>
inline int SimpleVector<T>::capacity()
{
    return currentCapacity;
}

template<typename T>
inline void SimpleVector<T>::push_back(const T& _data)
{
    if (currentCapacity == currentSize)
    {
        // 도전기능 벡터 확장
        resize(currentCapacity+5);
    }
    // 값 넣기
    data[currentSize++] = _data;

}

template<typename T>
inline void SimpleVector<T>::pop_back()
{
    if (currentSize == 0)
    {
        //throw invalid_argument("Empty Vector!!");
        cout << "현재 공간이 넘겨 받은 값보다 더 큽니다." << endl;
    }
    else
    {
        data[--currentSize] = T();// 기본 생성자로 초기화
    }
    

}

template<typename T>
inline void SimpleVector<T>::resize(int _newCapacity)
{
    if (_newCapacity > currentCapacity)
    {
        auto temp = new T[_newCapacity]; // 임시 공간 재할당
        for (int i = 0; i < currentSize; ++i)
        {
            temp[i] = data[i]; // 복사
        }
        delete[] data; // 기존 data의 공간 해제 후
        data = temp; // 임시 공간 주소 할당, temp 지역변수 제거
        currentCapacity = _newCapacity;
    }
    else
    {
        cout << "현재 공간이 넘겨 받은 값보다 더 큽니다." << endl;
    }
}

template<typename T>
inline void SimpleVector<T>::sortData()
{
    sort(begin(), end());
}
