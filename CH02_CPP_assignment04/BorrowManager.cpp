#include "BorrowManager.h"
/*
- 특정 책의 대여 여부를 알 수 있어야 합니다.
- 책의 이름으로 대여 여부를 검색하고 대여가 아닌 경우 대여할 수 있어야 합니다.
=> BookManager에서 BorrowManager를 멤버 변수로 가진 다음 빌리기 기능을 사용함
- 책의 작가로 대여 여부를 검색하고 대여가 아닌 경우 대여할 수 있어야 합니다.
=> 작가가 같은 모든 책과 재고를 나열

- 책을 반납할 수 있어야 합니다.
- 모든 책의 재고는 난이도를 낮추기 위해 3권으로 통일 합니다.
*/
void BorrowManager::initializeStock(Book book, int quantity)
{
	stock.insert({book.title, quantity});
}

int BorrowManager::GetQuantitybyTitle(const string& _title)
{
	return stock[_title];
}

void BorrowManager::BorrowBook(const string& _title)
{
	// 책이있는지 조회는 BookManager에서 하기
	
	stock[_title]--;
	return;
}

void BorrowManager::ReturnBook(const string& _title)
{
	stock[_title]++;
}

