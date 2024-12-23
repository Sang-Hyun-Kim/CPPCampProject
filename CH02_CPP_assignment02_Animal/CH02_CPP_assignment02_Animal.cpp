// 
#include <iostream>
#include <cstdlib> // rand, srand
#include <ctime> // time
#include "Animal.h"
#include "Zoo.h"
using namespace std;
Animal* createRandomAnimal();

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    Zoo zoo;

    for (int i = 0; i < 15; ++i)
    {
        zoo.addAnimal(createRandomAnimal());
    }

    zoo.performActions();

}

Animal* createRandomAnimal()
{
    Animal* rtAnimal = nullptr;
    int rannum = rand() % 3;
    //C++ 지식
    // 자식클래스에서 부모클래스로 포인터타입 형변환을 업 캐스팅이라하며 이는 암시적 형변환으로
    // 컴파일러가 지원해준다.
    // Dynamic_cast는 검증을 지원해주는 STL 기능이다 상속관계의 Casting에 쓰이며
    // 만약 잘못된 캐스팅의 경우 nullptr을 반환해준다.
    // 안전성이 있지만 검증과정에 따른 성능저하가 존재한다.
    // 개
    if (rannum == 0)
    {
        Dog* dog = new Dog();
        rtAnimal = dynamic_cast<Animal*>(dog);

    }
    // 고양이
    else if (rannum == 1)
    {
        Cat* dog = new Cat();
        rtAnimal = dog;
    }
    // 소 == 2
    else
    {
        Cow* dog = new Cow();
        rtAnimal = dog;
    }

    return rtAnimal;
}
