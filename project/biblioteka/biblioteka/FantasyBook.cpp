#include<iostream>
#include"FantasyBook.h"
using namespace std;




    FantasyBook::FantasyBook(string nameA, string surnameA, string bookTitle, int serialNumber, string heroes) : Book(nameA, surnameA, bookTitle, serialNumber)
    {
        this->Heroes = heroes;
    }

    void FantasyBook::DisplayBook() 
    {
        Book::DisplayBook();
        IsInit();
        cout << " " << Heroes;
    }

