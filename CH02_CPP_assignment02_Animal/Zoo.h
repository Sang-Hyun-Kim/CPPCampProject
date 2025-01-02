#pragma once
class Zoo
{
private:
	int idx = 0;
	class Animal* animals[10] = {nullptr,};
	// 배열 동적할당으로 추가하는 기능 보다 최대 크기 보다 더 입력하게 되면 
	// 추가를 거부하면서 동시에 외부 코드에서 생성한 heap 영역에 대한 해제 처리를 하는 코드로
	// 구현함
public:
	Zoo() {};
	~Zoo();
	void addAnimal(Animal* _animal);
	void performActions();

};

