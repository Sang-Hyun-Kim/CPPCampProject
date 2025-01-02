#pragma once
#include "Book.h"
#include <vector>
#include <iostream>
#include "BorrowManager.h"
using namespace std;

// �������� å�� �߰��ϰ� å�� �̸�, ���ڸ� �˻� �ϴ� BookManager
// �� �Ŵ���
// å �߰��� �˻�

class BookManager{
private:
    vector<Book> books; // å ��� ����
    BorrowManager* borrowManager;
public:
    BookManager();
    ~BookManager();
    // å �߰� �޼���
    void addBook(const string& title, const string& author) {
        Book newbook = Book(title, author);
        books.push_back(newbook); // push_back ���
        cout << "å�� �߰��Ǿ����ϴ�: " << title << " by " << author << endl;
        borrowManager->initializeStock(newbook);
    }

    // ��� å ��� �޼���
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "���� ��ϵ� å�� �����ϴ�." << endl;
            return;
        }

        cout << "���� ���� ���:" << endl;
        for (size_t i = 0; i < books.size(); i++) { // �Ϲ����� for�� ���
            cout << "- " << books[i].title << " by " << books[i].author << endl;
        }
    }
    // å ���� �˻�
    void searchByTitle(const string& _title);
    // å �۰� �˻�, �۰� �ߺ��� ���� ���������� ���
    // �۰��� �뿩�Ѵٱ⺸�� �۰��� �� ��� å�� ����� �����ϰ� ����ڰ� ���� �����ϴ�
    // å�� ������ �ٽ� �ѹ� �뿩 ����� ���� �������� ���� ��
    void searchByAuthor(const string& _author);

    // �۰��� �̸��� �ԷµǸ� �ش� �۰��� �� ��� �ý��ۿ� ��ϵ� ������ �迭�� ��� ��ȯ
    vector<string> getTitleByAuthor(const string& _author);

    // å �̸����� ������
    void BorrowingBook(const string& _title);

    // å�� �ý����� �ִ��� �Ǵ��ϴ� �Լ�, ���� ������ �Լ�ȭ�ؼ� ���
    int isTitlehere(const string& _title); // å�� idx ��ȯ ���� ��� -1 ��ȯ

    // å �̸����� ��ȯ�ϱ�
    void returningBook(const string& _title); // å ��ȯ�ϱ�
};