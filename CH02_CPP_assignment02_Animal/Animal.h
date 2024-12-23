#pragma once
#include <iostream>
using namespace std;
class Animal
{
public:
	Animal();
	virtual ~Animal();
	// �Ҹ��� �����Լ�ȭ�� �θ� Ŭ���� ������ Ÿ�� ȣ��ÿ��� �˸��� �ڽ�Ŭ�����Ҹ��� ȣ�⿡ �ſ� �߿��� ����̴�.
	// �θ� Ŭ���� ������ Ÿ���� ȣ���ص� 
	// � ��ü�� �����Ǿ����� Ȯ���Ͽ� �ùٸ� ��ü�� �Ҹ��ڸ� ȣ���Ѵ�.
	// �̴� �ڽ� Ŭ���� �Ҹ��ڿ��� ����Ǿ���ϴ� �ڵ带 �ǹٸ��� �����ϱ� ���ؼ� �ʼ����̴�.
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