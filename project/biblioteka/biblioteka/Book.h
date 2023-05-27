#include <iostream>
#include <string>
#ifndef BOOK_H
#define BOOK_H

using namespace std;

class Book {
private:
    string authorName;
    string authorSurname;
    string title;
public:

    int Status;
    int BookNumber;
    
    Book(string nameA, string surnameA, string bookTitle, int serialNumber);

    bool IsInit();
    
    virtual void DisplayBook();
        
};

#endif // BOOK_H