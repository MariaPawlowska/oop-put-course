#include<iostream>
#include "Library.h"
using namespace std;

class ToDoLibrary {
public:
    virtual void AddBook();
    virtual void DisplayAllBooks();
    virtual void DeleteBook();
    virtual void BorrowBook();
    virtual void ReturnBook();
    virtual void DisplayBorrower();
};





    void Library::AddBook(Book* newBook) {
        for (int i = 0; i < sizeof(books) / sizeof(books[0]); i++)
        {
            if (books[i] == nullptr) {
                books[i] = newBook;
                return;
            }
        }
    }

    void Library::DisplayAllBooks() {
        for (int i = 0; i < sizeof(books) / sizeof(books[0]); i++)
        {
            if (books[i] == nullptr)
                continue;

            books[i]->DisplayBook();
            cout << endl;
        }
    }

    void Library::DeleteBook(int numberOfBook) {
        for (int i = 0; i < sizeof(books) / sizeof(books[0]); i++) {
            if (books[i] == nullptr)
                continue;

            delete books[i];
            books[i] = nullptr;
            cout << "Book with number " << numberOfBook << " deleted." << endl;
            return;
        }
    };

    void Library::BorrowBook(int numberOfBook) {
        for (int i = 0; i < sizeof(books) / sizeof(books[0]); i++) {
            if (books[i] != nullptr && books[i]->BookNumber == numberOfBook) {
                if (books[i]->Status == 0) {
                    books[i]->Status = 1;
                    cout << "Book with number " << numberOfBook << " borrowed." << endl;
                }
                else {
                    cout << "Book with number " << numberOfBook << " is already borrowed." << endl;
                }
                return;
            }
        }
        cout << "Book with number " << numberOfBook << " not found." << endl;
    }

    void Library::ReturnBook(int numberOfBook) {
        for (int i = 0; i < sizeof(books) / sizeof(books[0]); i++) {
            if (books[i] != nullptr && books[i]->BookNumber == numberOfBook) {
                if (books[i]->Status == 1) {
                    books[i]->Status = 0;
                    cout << "Book with number " << numberOfBook << " returned." << endl;
                }
                else {
                    cout << "Book with number " << numberOfBook << " is not currently borrowed." << endl;
                }
                return;
            }
        }
        cout << "Book with number " << numberOfBook << " not found." << endl;
    }

    void Library::DisplayBorrower(int numberOfBook) {
        for (int i = 0; i < sizeof(books) / sizeof(books[0]); i++) {
            if (books[i] != nullptr && books[i]->BookNumber == numberOfBook) {
                if (books[i]->Status == 1) {
                    cout << "Book with number " << numberOfBook << " is currently borrowed." << endl;
                }
                else {
                    cout << "Book with number " << numberOfBook << " is not currently borrowed." << endl;
                }
                return;
            }
        }
        cout << "Book with number " << numberOfBook << " not found." << endl;
    }
