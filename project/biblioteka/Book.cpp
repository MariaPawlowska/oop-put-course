#include<iostream>
#include "Book.h"
using namespace std;

    Book::Book(string nameA, string surnameA, string bookTitle, int serialNumber) {
        this->authorName = nameA;
        this->authorSurname = surnameA;
        this->title = bookTitle;
        this->BookNumber = serialNumber;
        this->Status = 0;
    }

    bool Book::IsInit() {
        return authorName == "null";
    }
     void Book::DisplayBook() {
        if (IsInit()) {
            return;
        }
        cout << authorName + " " + authorSurname + " " + "\"title\"" << " " << " book number: " << BookNumber;

    }
