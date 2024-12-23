#pragma once
class Zoo
{
private:
	int idx = 0;
	class Animal* animals[10] = {nullptr,};
public:
	Zoo() {};
	~Zoo();
	void addAnimal(Animal* _animal);
	void performActions();

};

