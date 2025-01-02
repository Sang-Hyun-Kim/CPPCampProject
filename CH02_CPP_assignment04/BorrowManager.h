#pragma once
#include "Book.h"
#include "unordered_map"
#include <iostream>

// BookManager�� ���� ��� �߰�, �뿩 ��û, ��ȯ ��û�� ������
// �ý��ۿ� å�� �����ϴ��� Ȯ�� �� �뿩, ��ȯ�� ���� ��

class BorrowManager
{
public:
    BorrowManager() {};
	void initializeStock(Book book,int quantity=3);// ��� �߰�

    // å���� ���� ��� ��ȯ
    int GetQuantitybyTitle(const string& _title);
    // ������
    void BorrowBook(const string& _title);
    //�ݳ��ϱ�
    void ReturnBook(const string& _title);

private:
	unordered_map<string, int> stock;
};

