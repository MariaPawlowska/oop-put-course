#include <iostream>
#include <string>
#include"Book.h"

using namespace std;



class Library {
private:
    Book* books[10] = { nullptr };
public:
    void AddBook(Book* newBook);
        
    void DisplayAllBooks();

    void DeleteBook(int numberOfBook);

    void BorrowBook(int numberOfBook);

    void ReturnBook(int numberOfBook);

    void DisplayBorrower(int numberOfBook);
};