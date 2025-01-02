#include "BookManager.h"

BookManager::BookManager()
    :books(vector<Book>())
{
    borrowManager = new BorrowManager();
}

BookManager::~BookManager()
{
    if (borrowManager)
    {
        delete borrowManager;
    }
}

void BookManager::searchByTitle(const string& _title)
{
    if (books.empty())
    {
        cout << "현재 등록된 책이 없습니다." << endl;
        return;
    }
    else
    {
        if (int idx = isTitlehere(_title))
        {
            cout << "찾으시는 책 " << books[idx].title << " by " << books[idx].author << "이 "
                << borrowManager->GetQuantitybyTitle(books[idx].title) << "권 존재합니다." << endl;
            return;
        }
        else
        {
            // 책이 존재하지 않음
            cout << "찾으시는 책 " << _title << " 이 존재하지 않습니다." << endl;
        }

    }
   
}

void BookManager::searchByAuthor(const string& _author)
{
    if (books.empty())
    {
        cout << "현재 도서관에 등록된 책이 없습니다." << endl;
        return;
    }
    cout << "입력하신 저자의 저서" << endl;
    vector<string> titles = getTitleByAuthor(_author);
    if (titles.size() == 0)
    {
        cout << "입력하진 저자의 저서가 존재하지 않습니다." << endl;
    }
    else
    {
        // 책 이름 하나당 재고 까지 반환
        for (auto title : titles)
        {
            cout << "책이름: " << title << 
                " 재고: " << borrowManager->GetQuantitybyTitle(title)<< endl;
        }
    }
}

vector<string> BookManager::getTitleByAuthor(const string& _author)
{
    vector<string> titles;
    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].author == _author)
        {
            titles.push_back(books[i].title);
        }
    }
    return titles;// 작가의 모든 저서가 담긴 타이틀 반환
}

void BookManager::BorrowingBook(const string& _title)
{
    if (int idx = isTitlehere(_title))
    {
        if (borrowManager->GetQuantitybyTitle(books[idx].title) > 0)
        {
            borrowManager->BorrowBook(books[idx].title);
            cout << "책을 빌렸습니다. 남은 재고: " << borrowManager->GetQuantitybyTitle(books[idx].title)
                << "권 남았습니다." << endl;
        }
        else
        {
            cout << "현재 재고가 없습니다. 대여가 불가능합니다." << endl;
        }
       
    }
    else
    {
        cout << "존재하지 않는 책 입니다." << endl;
    }
    
}

int BookManager::isTitlehere(const string& _title)
{
    for (int i = 0; i < books.size(); ++i)
    {
        if (books[i].title == _title)
        {
            return i;
        }
    }
    return -1;
}

void BookManager::returningBook(const string& _title)
{
    if (int idx = isTitlehere(_title))
    {
        borrowManager->ReturnBook(books[idx].title);
        cout << "책이 반납되었습니다." << endl;
        cout << "반납된 책 " << books[idx].title << "의 현재 재고는 " << 
            borrowManager->GetQuantitybyTitle(books[idx].title) << endl;
    }
    else
    {
        cout << "존재하지 않는 책 입니다." << endl;
    }
}


