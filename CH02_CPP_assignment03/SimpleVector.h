#pragma once
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <iterator>
using namespace std;
/* �� ��
- Ŭ������ �̸��� SimpleVector��� �մϴ�.
- Ÿ�Կ� �������� �ʰ� �����͸� ������ �ִ� �迭�� ��������� �����ϴ�.
- �����ڴ� �Ʒ��� ���� ���� �մϴ�.
    - �⺻ �����ڴ� ũ�Ⱑ 10�� �迭�� ����ϴ�.
    - ���ڸ� �ϳ� �޴� �����ڴ� �ش� ���ڿ� �ش�Ǵ� ũ���� �迭�� ����ϴ�.
- �Ʒ��� ���� ����Լ��� ���� �մϴ�.
    - push_back  ���ڷ� ���� ���Ҹ�  �� �ڿ� �߰� �մϴ�. ��ȯ���� �����ϴ�. �迭�� ũ�Ⱑ �� á�µ� ���Ұ� �� ���ð�� �ƹ� ���۵� ���� �ʽ��ϴ�.
    - pop_back�� ������ ������ ���Ҹ� ���� �մϴ�. ���� ������ ���Ұ� ���ٸ� �ƹ� ���۵� ���� ������, ���� �� ��ȯ���� �����ϴ�.
    - size�� ���ڰ� ���� ���� ������ ������ ��ȯ�մϴ�.
    - capacity ���� ���� �迭�� ũ�⸦ ��ȯ�մϴ�.

������ �� �ڿ� Ŭ������ ������ �Ʒ��� �����ϴ�.

*/

/* ���� ���
- ���� �����ڸ� ���� �մϴ�.
- �Ʒ� ����Լ��� �߰��� ����/���� �մϴ�.
    - push_back���� �迭�� ũ�Ⱑ �� á�µ� ���Ұ� �� ���ð��, ���� �迭���� ũ�⸦ 5��ŭ �� �ø��� ���ο� ���ұ��� �߰��˴ϴ�.(������ �ִ� ���� �����Ǿ� �մϴ�.)
    - resize�� ���� �ϳ��� ���ڷ� �޽��ϴ�.  �ش� ������ ���� �迭�� ũ�⺸�� ������ �ƹ� ���۵� ���� �ʽ��ϴ�. ���� ���� �迭���� ũ�Ⱑ ũ�� �ش� ����ŭ ũ�⸦ ���Ҵ� �մϴ�.(���� ���Ҵ� �״�� �־�� �մϴ�.)
    - sortData�� ���� �����͸� �����ϴ� �Լ� �Դϴ�. ���� �������� �ʰ� STL�� sort�Լ��� Ȱ���ؼ� ���� �մϴ�.
*/
template<typename T>
class SimpleVector
{
public:

    SimpleVector(int _size = 10);
    SimpleVector(const SimpleVector& other);
    T& operator[](int idx); // [] ������ ���� �� ���
    ~SimpleVector();
    int size(); // ���� ���� ���� ��ȯ
    int capacity(); // ���� Capacity ��ȯ
    void push_back(const T& _data);
    void pop_back();
    void resize(int _newCapacity);
    void sortData();
public:
    // STL �Լ� ����� ���� iterator ����
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
    int currentSize; // ���� ������ ����
    int currentCapacity; // �Ҵ� ���� ������ ũ��
    T* data = nullptr;
};

template<typename T>
inline SimpleVector<T>::SimpleVector(int _size) 
    : currentSize(0), currentCapacity(_size)
{
    if (_size <= 0)
    {
        cout << "�����Ҵ��� 0 �̻��� ���̾�� �մϴ�." << endl;
    }
    else
    {
        data = new T[currentCapacity];
    }
    
}

// ������� ���� ������
// other�� ���� �޾� ���ο� ������ �Ҵ� ���� �� �ش� ���� ����
template<typename T>
inline SimpleVector<T>::SimpleVector(const SimpleVector& other)
    : currentCapacity(other.currentCapacity), currentSize(other.currentSize)
{// this�� �����ؼ� other�� ���� ����
    data = new T[currentCapacity];
    std::copy(other.data, other.data + currentSize, this->data);
}

template<typename T>
inline T& SimpleVector<T>::operator[](int idx)
{
    if (idx < 0 || idx >= currentSize)
    {
        cout << "idx ���� �ʰ�" << endl;
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
        // ������� ���� Ȯ��
        resize(currentCapacity+5);
    }
    // �� �ֱ�
    data[currentSize++] = _data;

}

template<typename T>
inline void SimpleVector<T>::pop_back()
{
    if (currentSize == 0)
    {
        //throw invalid_argument("Empty Vector!!");
        cout << "���� ������ �Ѱ� ���� ������ �� Ů�ϴ�." << endl;
    }
    else
    {
        data[--currentSize] = T();// �⺻ �����ڷ� �ʱ�ȭ
    }
    

}

template<typename T>
inline void SimpleVector<T>::resize(int _newCapacity)
{
    if (_newCapacity > currentCapacity)
    {
        auto temp = new T[_newCapacity]; // �ӽ� ���� ���Ҵ�
        for (int i = 0; i < currentSize; ++i)
        {
            temp[i] = data[i]; // ����
        }
        delete[] data; // ���� data�� ���� ���� ��
        data = temp; // �ӽ� ���� �ּ� �Ҵ�, temp �������� ����
        currentCapacity = _newCapacity;
    }
    else
    {
        cout << "���� ������ �Ѱ� ���� ������ �� Ů�ϴ�." << endl;
    }
}

template<typename T>
inline void SimpleVector<T>::sortData()
{
    sort(begin(), end());
}
