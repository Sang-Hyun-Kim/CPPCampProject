#include "Zoo.h"
#include "Animal.h"

Zoo::~Zoo()
{
    // Zoo 소멸자
    // - Zoo 객체가 소멸될 때, 동물 벡터에 저장된 모든 동물 객체의 메모리를 해제합니다.
    // - 메모리 누수를 방지하기 위해 동적 할당된 Animal 객체를 `delete` 합니다.
    // - 입력 매개변수: 없음
    // - 반환값: 없음
    cout << "동물원 도살 시작" << endl;
    for (int i = 0; i < 10; ++i)
    {
        if (animals[i])
        {
            delete animals[i];
            animals[i] = nullptr;
            cout << "잡았고" << endl;//디버깅용
        }
    }
    //idx = 0;
}

void Zoo::addAnimal(Animal* _animal)
{
    // 동물을 동물원에 추가하는 함수
    // - Animal 객체의 포인터를 받아 포인터 배열에 저장합니다.
    // - 같은 동물이라도 여러 번 추가될 수 있습니다.
    // - 입력 매개변수: Animal* (추가할 동물 객체)
    // - 반환값: 없음
    if(idx >= 10)
    {
        cout << "동물원이 가득차 더 이상 동물을 넣을 수 없습니다." << endl;
        // 받아온 동물 해제
        delete _animal; // 다른함수에서 생성했으므로 안받으면 그만이 아니라
        // 해제까지 진행해준다.
    }
    else
    {
        animals[idx++] = _animal; // 암시정 형변환된 자식클래스의 힙메모리 위치를 가르키는 부모
        // 클래스 포인터 타입이 배열에 저장됨
        cout << "새로운 동물이 합류했어요" << endl;
        cout << "현재 동물의 수: " << idx << endl;
    }
}

void Zoo::performActions()
{
    // 동물원에 있는 모든 동물의 행동을 수행하는 함수
    // - 모든 동물 객체에 대해 순차적으로 소리를 내고 움직이는 동작을 실행합니다.
    // - 입력 매개변수: 없음
    // - 반환값: 없음
    cout << "현재 동물원에 존재하는 동물들의 울음소리를 출력합니다." << endl;
    // 반복문으로 현재 저장된 동물 울음소리 출력
    for (int i = 0; i < idx; ++i)
    {
        if(animals[i]) // nullptr 체크
            animals[i]->makeSound();
        cout << "\n";
        
    }
    // virtual 키워드를 통한 가상함수 재정의로 자식클래스의 주소에 가상함수 테이블이 생성되었고
    // 이를 통해 오버라이딩 된 자식 클래스의 함수가 알맞게 호출된다. 
}
