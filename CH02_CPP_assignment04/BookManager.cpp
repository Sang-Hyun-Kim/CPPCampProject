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
        cout << "���� ��ϵ� å�� �����ϴ�." << endl;
        return;
    }
    else
    {
        if (int idx = isTitlehere(_title))
        {
            cout << "ã���ô� å " << books[idx].title << " by " << books[idx].author << "�� "
                << borrowManager->GetQuantitybyTitle(books[idx].title) << "�� �����մϴ�." << endl;
            return;
        }
        else
        {
            // å�� �������� ����
            cout << "ã���ô� å " << _title << " �� �������� �ʽ��ϴ�." << endl;
        }

    }
   
}

void BookManager::searchByAuthor(const string& _author)
{
    if (books.empty())
    {
        cout << "���� �������� ��ϵ� å�� �����ϴ�." << endl;
        return;
    }
    cout << "�Է��Ͻ� ������ ����" << endl;
    vector<string> titles = getTitleByAuthor(_author);
    if (titles.size() == 0)
    {
        cout << "�Է����� ������ ������ �������� �ʽ��ϴ�." << endl;
    }
    else
    {
        // å �̸� �ϳ��� ��� ���� ��ȯ
        for (auto title : titles)
        {
            cout << "å�̸�: " << title << 
                " ���: " << borrowManager->GetQuantitybyTitle(title)<< endl;
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
    return titles;// �۰��� ��� ������ ��� Ÿ��Ʋ ��ȯ
}

void BookManager::BorrowingBook(const string& _title)
{
    if (int idx = isTitlehere(_title))
    {
        if (borrowManager->GetQuantitybyTitle(books[idx].title) > 0)
        {
            borrowManager->BorrowBook(books[idx].title);
            cout << "å�� ���Ƚ��ϴ�. ���� ���: " << borrowManager->GetQuantitybyTitle(books[idx].title)
                << "�� ���ҽ��ϴ�." << endl;
        }
        else
        {
            cout << "���� ��� �����ϴ�. �뿩�� �Ұ����մϴ�." << endl;
        }
       
    }
    else
    {
        cout << "�������� �ʴ� å �Դϴ�." << endl;
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
        cout << "å�� �ݳ��Ǿ����ϴ�." << endl;
        cout << "�ݳ��� å " << books[idx].title << "�� ���� ���� " << 
            borrowManager->GetQuantitybyTitle(books[idx].title) << endl;
    }
    else
    {
        cout << "�������� �ʴ� å �Դϴ�." << endl;
    }
}


