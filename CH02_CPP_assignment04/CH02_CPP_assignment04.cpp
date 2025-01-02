#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "BookManager.h"
using namespace std; // namespace std 사용

// 검색 및 재고 입력 추가 => BookManager
// BookManager는 멤버 변수 BorrowManager*를 통해
// 반환 빛 대여를 통한 재고 관리
// 대신 시스템에 재고가 있는지에 대한 여부는 BookManager가 담당(int BookManager::isTitlehere())

int main() {
    BookManager manager;

    // 도서관 관리 프로그램의 기본 메뉴를 반복적으로 출력하여 사용자 입력을 처리합니다.
    // 프로그램 종료를 선택하기 전까지 계속 동작합니다.
    while (true) {
        cout << "------------------------------------------------" << "\n";
        cout << "\n도서관 관리 프로그램\n" << endl;
        cout << "1. 책 추가" << endl; // 책 정보를 입력받아 책 목록에 추가
        cout << "2. 모든 책 출력" << endl; // 현재 책 목록에 있는 모든 책 출력
        cout << "3. 책 이름 검색" << endl; // 프로그램 종료
        cout << "4. 작가 검색" << endl; // 프로그램 종료
        cout << "5. 책 대여" << endl;
        cout << "6. 책 반납하기" << endl;


        cout << "7. 종료" << endl; // 프로그램 종료
        cout << "------------------------------------------------" << "\n" << endl;
        cout << "선택: ";

        int choice; // 사용자의 메뉴 선택을 저장
        cin >> choice;

        if (choice == 1) {
            // 1번 선택: 책 추가
            // 사용자로부터 책 제목과 저자명을 입력받아 BookManager에 추가합니다.
            string title, author;
            cout << "책 제목: ";
            cin.ignore(); // 이전 입력의 잔여 버퍼를 제거
            getline(cin, title); // 제목 입력 (공백 포함)
            cout << "책 저자: ";
            getline(cin, author); // 저자명 입력 (공백 포함)
            manager.addBook(title, author); // 입력받은 책 정보를 추가
        }
        else if (choice == 2) {
            // 2번 선택: 모든 책 출력
            // 현재 BookManager에 저장된 책 목록을 출력합니다.
            manager.displayAllBooks();
        }
        else if (choice == 3)
        {
            // 3번 선택: 책 이름 검색
            // 현재 BookManager에 저장된 책 목록 중에 입력된 책 이름과 일치하는 책의 정보를 출력합니다.
            // 만약 일치하지 않다면 일치하는 대상이 없음을 출력
            string targettitle;
            cout << " 찾으시는 책의 제목을 입력해주세요:";
            cin.ignore(); // 버퍼 제거
            getline(cin, targettitle);
            manager.searchByTitle(targettitle);
        }
        else if (choice == 4)
        {
            // 4번 선택: 작가 이름 검색
            // 현재 BookManager에 저장된 책 목록 중에 입력된 저자 이름과 일치하는 책의 정보를 출력합니다.
            // 만약 일치하지 않다면 일치하는 대상이 없음을 출력
            string targetauthor;
            cout << " 찾으시는 책의 저자의 이름을 입력해주세요:";
            cin.ignore(); // 버퍼 제거
            getline(cin, targetauthor);
            manager.searchByAuthor(targetauthor);
        }
        else if (choice == 5)
        {
            // 5번 선택: 책 대여 하기
            // 입력한 책 제목 대여하기
            // 
            string targettitle;
            cout << " 대여하실 책의 이름을 입력해주세요:";
            cin.ignore(); // 버퍼 제거
            getline(cin, targettitle);
            manager.BorrowingBook(targettitle);
        }
        else if (choice == 6)
        {
            // 6번 선택: 책 반납하기
            // 
            // 
            string targettitle;
            cout << " 반납하실 책의 이름을 입력해주세요:";
            cin.ignore(); // 버퍼 제거
            getline(cin, targettitle);
            manager.returningBook(targettitle);
        }
        else if (choice == 7) {
            // 번 선택: 종료
            // 프로그램을 종료하고 사용자에게 메시지를 출력합니다.
            cout << "프로그램을 종료합니다." << endl;
            break; // while 루프 종료
        }
        else {
            // 잘못된 입력 처리
            // 메뉴에 없는 번호를 입력했을 경우 경고 메시지를 출력합니다.
            cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
        }
    }

    return 0; // 프로그램 정상 종료
}

