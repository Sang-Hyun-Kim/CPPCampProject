#pragma once
#include <iostream>
using namespace std;
class Animal
{
public:
	Animal();
	virtual ~Animal();
	// 소멸자 가상함수화는 부모 클래스 포인터 타입 호출시에도 알맞은 자식클래스소멸자 호출에 매우 중요한 방식이다.
	// 부모 클래스 포인터 타입을 호출해도 
	// 어떤 객체로 생성되었는지 확인하여 올바른 객체의 소멸자를 호출한다.
	// 이는 자식 클래스 소멸자에서 실행되어야하는 코드를 옳바르게 실행하기 위해서 필수적이다.
	virtual void makeSound(); 
};

class Dog : public Animal
{
public:
	Dog();
	~Dog();
	void makeSound();
};

class Cat : public Animal
{
public:
	Cat();
	~Cat();
	void makeSound();
};

class Cow : public Animal
{
public:
	Cow();
	~Cow();
	void makeSound();
};