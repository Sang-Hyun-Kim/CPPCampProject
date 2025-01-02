// CH02_CPP_assignment03.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

/*
필수
- 배열의 맨 끝에 원소를 삽입/삭제 하는 기능이 요구사항에 맞게 동작하는지 확인
도전
- 배열 크기 확장 및 정렬 로직이 요구사항에 맞게 동작하는지 확인
필수
- 템플릿을 적용한 경우와 적용하지 않은 경우를 비교해서 설명할 수 있는지 확인
도전
- 원소 추가시 메모리를 재 할당하는 경우에 어떤 방식으로 코드가 동작하는지 그림을 그려서 설명할 수 있는지 확인
필수
- 요구사항에 있는 생성자 구현시, 다수의 생성자를 만들지 않고, 기본인자를 활용해서 하나의 생성자로 처리할 수 있는지(처리했는지) 확인
도전
- 메모리를 재 할당해야 하는 경우에 예외가 발생하지 않고 정상적으로 동작하는지 확인
- 소멸자에서 동적할당한 메모리가 제대로 해지되고 있는지 확인
*/
#include "SimpleVector.h"
#include <vector>

using namespace std;
int main()
{
    SimpleVector<int> SVint(11);
    for (int i = 0; i < 14; ++i)
    {
        SVint.push_back(i + 10);
    }

    int debug = 3;
    for (int i = 0; i < SVint.size(); ++i)
    {
        cout << i << " 번째 값: " << SVint[i] << endl;
    }

    cout << "반복자 접근" << endl;
    for (auto it = SVint.begin(); it != SVint.end(); ++it)
    {
        cout << *it << endl;
    }
    SimpleVector<int> SV2(SVint);
    for (int i = 0; i < 14; ++i)
    {
        SV2[i] += 100;
    }
    for (int i = 0; i < SVint.size(); ++i)
    {
        cout << "SV배열의" << i << " 번째 값: " << SV2[i] << endl;
    }
    //SVint.sortData();
    cout << "SV[2]: " << SV2[2] << endl;
    int debug2 = 12;

}
