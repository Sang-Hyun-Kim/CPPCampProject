#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

/*
- 사용자로부터 5개의 숫자를 입력 받아 배열에 저장하고 이들의 합계와 평균을 계산해서 출력해주세요!
- 5개의 숫자를 입력 받는 공간은 배열을 활용할게요!
=> STL std::vector 사용, 초기화를 통한 메모리 공간 확보

- 합과 평균을 구하는 동작은 main함수에 한번에 작성하지 말고 각각 함수를 구현해주시는 것으로 해요!
- 왜 이렇게 하는 것이 좋은지를 한 번 더 생각해보면서 작성해봐요!
=> 코드 가독성 증가, 간단한 코드가 반복적으로 이루어지는 경우에 대해서는 함수화가 정말 맞는지 또는 inline화 하는 것이 어떤가 라는 추가 공부
=> Sum(), Avg() 함수 생성

- 정렬은 오름차순 정렬과 내림차순 정렬이 가능해야 합니다.
- 숫자 1을 입력 받으면 오름차순 정렬, 숫자 2를 입력 받으면 내림차순 정렬을 하도록 구현해주세요.
    - 입력을 구현하는 방법은 원격강의에서 배울겁니다!
- `algorithm` 헤더의 `sort` 함수를 사용하지 않고 직접 구현해보세요.
=> 메모리를 소비하는 합병 정렬 사용하기

- 오름차순 정렬과 내림차순 정렬 동작을 각각 함수로 구현해봐요
=> 내림차순 Desc(), 오름차순 Asc() 함수 구현
=> 합병정렬 방식을 함수 주소 벡터를 통해 index 접근으로 선택하여 호출

*/

/*******************************************************

                      선   언   부

********************************************************/
using namespace std;
void Sum(int& _sum,vector<int>& _userinput);
void Avg(float& _avg, int& _sum,vector<int>& _userinput);
void Desc(vector<int>& _userinput, int& _method); // 내림 차순
void Asc(vector<int>& _userinput, int& _method); // 오름차순
void MergeAsc(vector<int>& _userinput, int _left, int _right);
void MergeDesc(vector<int>& _userinput, int _left, int _right);
void Partition(vector<int>& _userinput, int _left, int _right,int& _method);
vector<function<void(vector<int>&, int, int)>> MergeArray = { [&](auto a,auto b,auto c) {std::cout << "idx편의용 함수입니다. 잘못된함수호출!!" << endl; },MergeAsc ,MergeDesc };
// 입력된 번호에 맞는 함수가 호출됩니다. 1,2번은 각각 오름차순, 내림차순 함수를 호출하며, 0번은 잘못된 입력을 방지하는 디버깅용 함수 및 idx 호출 편의를 위해 추가했습니다. 
/*******************************************************

                       메 인 함 수

********************************************************/

int main()
{
    int inputSize = 0;
    cout << "입력할 숫자의 수를 입력해주세요: ";
    cin >> inputSize;
    if (inputSize<=0)
    {
        cout << "올바른 입력이 아닙니다. 프로그램을 종료합니다." << endl;
        return 0;
    }
    vector<int> userinput(inputSize, 0);
    cout << "입력한 숫자의 개수만큼 수를 입력해주세요. 수는 한번에 한 숫자씩 띄어쓰기나 줄바꿈을 하면서 입력해주세요." << "\n"
        <<"정수형 입력에 대하여 작동합니다."<<endl;
    for (int i = 0; i < inputSize; ++i)
    {
        cout << "숫자 입력: ";
        cin >> userinput[i];
        cout << "입력된 숫자 : " << userinput[i] << endl;
    }
    cout << "입력된 숫자를 확인합니다." << "\n";
    for (auto input : userinput)
    {
        cout << input << " ";
    }
    cout << endl;
    // 합
    int sum = 0;
    Sum(sum, userinput);

    // 평균
    float avg = 0;
    Avg(avg,sum, userinput);
    
    // 정렬
    cout << "원하시는 정렬 방식을 입력해주세요. " << "\n"
        << "1. 오름차순 정렬 " << "\n"
        << "2. 내림차순 정렬" << "\n"
        << "원하는 입력: ";
    int method=0;
    cin >> method;
    if (method == 1)
    {
        Asc(userinput, method);
    }
    else if (method == 2)
    {
        Desc(userinput,method);
    }
    else
    {
        cout << "올바른 입력이 아닙니다. 프로그램을 종료합니다." << endl;
        return 0;
    }
}


/*******************************************************

                       함 수 정 의

********************************************************/
void Sum(int& _sum, vector<int>& _userinput)
{
    for (auto input : _userinput)
    {
        _sum += input;
    }
    cout << "입력한 숫자들의 총합: " << _sum << endl;
}
void Avg(float& _avg,int& _sum, vector<int>& _userinput)
{
    int size = _userinput.size();
    _avg = _sum / (float)size;
    cout << "입력한 숫자들의 평균: 약 " << _avg << endl;
}

void Desc(vector<int>& _userinput, int& _method)
{
    // 디버깅용
    //sort(_userinput.begin(), _userinput.end(),greater<int>());
    Partition(_userinput, 0, _userinput.size() - 1, _method);
    cout << "내림차순 정렬된 배열 출력" << endl;
    for (auto input : _userinput)
    {
        cout << input << " ";
    }
    cout << "출력 끝" << endl;

}

void Asc(vector<int>& _userinput, int& _method)
{
    // 디버깅용 
    //sort(_userinput.begin(), _userinput.end());
    Partition(_userinput, 0, _userinput.size() - 1, _method);
    cout << "오름차순 정렬된 배열 출력" << endl;
    for (auto input : _userinput)
    {
        cout << input << " ";
    }
    cout << "출력 끝" << endl;

}

void MergeAsc(vector<int>& _userinput, int _left, int _right)
{
    vector<int> tmparr(_right - _left + 1,0);// 합병정렬을 위한 임시 배열
    int mid = (_left + _right) / 2;
    int i = _left;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= _right) // 오름차순 정렬을 위해 작은 값이 앞으로 가도록 정렬
    {
        if (_userinput[i] <= _userinput[j])
            tmparr[k++] = _userinput[i++];
        else
            tmparr[k++] = _userinput[j++];
    }
    
    // 왼쪽 배열의 남은 요소 처리
    while (i <= mid) 
        tmparr[k++] = _userinput[i++];

    // 오른쪽 배열의 남은 요소 처리
    while (j <= _right) 
        tmparr[k++] = _userinput[j++];

    // tmp 배열에서 정렬된 값을 원래 배열에 넣기
    for (int idx = 0; idx < tmparr.size(); ++idx)
        _userinput[_left + idx] = tmparr[idx];
}

void MergeDesc(vector<int>& _userinput, int _left, int _right)// 내림차순 정렬을 위해 작은 값이 앞으로 가도록 정렬
{
    vector<int> tmparr(_right - _left + 1, 0);// 합병정렬을 위한 임시 배열
    int mid = (_left + _right) / 2;
    int i = _left;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= _right)
    {
        if (_userinput[i] >= _userinput[j])
            tmparr[k++] = _userinput[i++];
        else
            tmparr[k++] = _userinput[j++];
    }

    // 왼쪽 배열의 남은 요소 처리
    while (i <= mid)
        tmparr[k++] = _userinput[i++];

    // 오른쪽 배열의 남은 요소 처리
    while (j <= _right)
        tmparr[k++] = _userinput[j++];

    // tmp 배열에서 정렬된 값을 원래 배열에 넣기
    for (int idx = 0; idx < tmparr.size(); ++idx)
        _userinput[_left + idx] = tmparr[idx];
}

void Partition(vector<int>& _userinput, int _left, int _right, int& _method)
{
    // 중앙점을 기준으로 배열을 두 개로 나누는 함수
    // 함수는 배열이 최소 두 칸이 될 때까지 나눈 뒤
    // 구분된 두 칸에 대해 정렬기준에 따라 정렬한 뒤 다시 합친다.
    int mid;
    if (_left < _right)
    {
        mid = (_left + _right) / 2;
        Partition(_userinput, _left, mid, _method); 
        Partition(_userinput, mid + 1, _right, _method);
        MergeArray[_method](_userinput, _left, _right);
    }
}
