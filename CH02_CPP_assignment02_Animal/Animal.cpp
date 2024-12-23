#include "Animal.h"

Animal::Animal()
{
	cout << "Animal created!!" << endl;
}

Animal::~Animal()
{
	cout << "Animal Deleted!!" << endl;
}

void Animal::makeSound()
{
	cout << "Animal Sound" << endl;
}



Dog::Dog()
{
	cout << "Dog is created!!" << endl;
}

Dog::~Dog()
{
	cout << "Dog is Deleted!!" << endl;
}

void Dog::makeSound()
{
	cout << "¸Û¸Û" << endl;
}

Cat::Cat()
{
	cout << "Cat is created!!" << endl;
}

Cat::~Cat()
{
	cout << "Cat is Deleted!!" << endl;
}

void Cat::makeSound()
{
	cout << "³Ä¿Ë" << endl;
}

Cow::Cow()
{
	cout << "Cow is created!!" << endl;
}

Cow::~Cow()
{
	cout << "Cow is Deleted!!" << endl;
}

void Cow::makeSound()
{
	cout << "À½¸Ó" << endl;
}
