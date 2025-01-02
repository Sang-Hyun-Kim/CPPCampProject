#include "BorrowManager.h"
/*
- Ư�� å�� �뿩 ���θ� �� �� �־�� �մϴ�.
- å�� �̸����� �뿩 ���θ� �˻��ϰ� �뿩�� �ƴ� ��� �뿩�� �� �־�� �մϴ�.
=> BookManager���� BorrowManager�� ��� ������ ���� ���� ������ ����� �����
- å�� �۰��� �뿩 ���θ� �˻��ϰ� �뿩�� �ƴ� ��� �뿩�� �� �־�� �մϴ�.
=> �۰��� ���� ��� å�� ��� ����

- å�� �ݳ��� �� �־�� �մϴ�.
- ��� å�� ���� ���̵��� ���߱� ���� 3������ ���� �մϴ�.
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
	// å���ִ��� ��ȸ�� BookManager���� �ϱ�
	
	stock[_title]--;
	return;
}

void BorrowManager::ReturnBook(const string& _title)
{
	stock[_title]++;
}

