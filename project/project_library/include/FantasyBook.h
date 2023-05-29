#include<iostream>
#include<string>

#ifndef FANTASYBOOK_H
#define FANTASYBOOK_H
#include"Book.h"

using namespace std;

class FantasyBook : public Book {
private:
    string Heroes;
public:
    FantasyBook(string nameA, string surnameA, string bookTitle, int serialNumber, string heroes);
    void DisplayBook() override;
};


#endif // FANTASYBOOK_H