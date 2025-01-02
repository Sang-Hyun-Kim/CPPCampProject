#pragma once
#include "Book.h"
#include <vector>
#include <iostream>
#include "BorrowManager.h"
using namespace std;

// 도서관에 책을 추가하고 책의 이름, 저자를 검색 하는 BookManager
// 북 매니저
// 책 추가와 검색

class BookManager{
private:
    vector<Book> books; // 책 목록 저장
    BorrowManager* borrowManager;
public:
    BookManager();
    ~BookManager();
    // 책 추가 메서드
    void addBook(const string& title, const string& author) {
        Book newbook = Book(title, author);
        books.push_back(newbook); // push_back 사용
        cout << "책이 추가되었습니다: " << title << " by " << author << endl;
        borrowManager->initializeStock(newbook);
    }

    // 모든 책 출력 메서드
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "현재 등록된 책이 없습니다." << endl;
            return;
        }

        cout << "현재 도서 목록:" << endl;
        for (size_t i = 0; i < books.size(); i++) { // 일반적인 for문 사용
            cout << "- " << books[i].title << " by " << books[i].author << endl;
        }
    }
    // 책 제목 검색
    void searchByTitle(const string& _title);
    // 책 작가 검색, 작가 중복에 대한 제한조건이 없어서
    // 작가로 대여한다기보단 작가가 쓴 모든 책의 목록을 나열하고 사용자가 그중 존재하는
    // 책의 제목을 다시 한번 대여 기능을 통해 빌리도록 설계 함
    void searchByAuthor(const string& _author);

    // 작가의 이름이 입력되면 해당 작가가 쓴 모든 시스템에 등록된 저서를 배열에 담아 반환
    vector<string> getTitleByAuthor(const string& _author);

    // 책 이름으로 빌리기
    void BorrowingBook(const string& _title);

    // 책이 시스템이 있는지 판단하는 함수, 자주 쓰여서 함수화해서 사용
    int isTitlehere(const string& _title); // 책의 idx 반환 없을 경우 -1 반환

    // 책 이름으로 반환하기
    void returningBook(const string& _title); // 책 반환하기
};