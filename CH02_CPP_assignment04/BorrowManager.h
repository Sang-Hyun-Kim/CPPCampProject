#pragma once
#include "Book.h"
#include "unordered_map"
#include <iostream>

// BookManager로 부터 재고 추가, 대여 요청, 반환 요청을 받으면
// 시스템에 책이 존재하는지 확인 후 대여, 반환을 수행 함

class BorrowManager
{
public:
    BorrowManager() {};
	void initializeStock(Book book,int quantity=3);// 재고 추가

    // 책제목에 따른 재고 반환
    int GetQuantitybyTitle(const string& _title);
    // 빌리기
    void BorrowBook(const string& _title);
    //반납하기
    void ReturnBook(const string& _title);

private:
	unordered_map<string, int> stock;
};

