#include <iostream>
#include <string>
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
