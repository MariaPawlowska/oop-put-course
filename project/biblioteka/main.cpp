#include <iostream>
#include <string>
#include "FantasyBook.h"
#include"Library.h"

using namespace std;

int main() {
    int x;
    string fantasy;
    Library library;

    while (1) {
        cout << "Hello! Enter a number from 1 to 6 to select an option." << endl;
        cout << "If you don't select the number, the system will shut down." << endl;
        cout << "1.Show all authors and titles of their books in the library." << endl;
        cout << "2. Add author and book title." << endl;
        cout << "3. Delete the author and title of the book." << endl;
        cout << "4. Borrow a book." << endl;
        cout << "5. Give the book back." << endl;
        cout << "6. Display all borrower books." << endl;
        cin >> x;
        switch (x) {
        case 1:
            library.DisplayAllBooks();
            break;
        case 2:
            cout << "Do you want add fantasy book? Write YES or NO" << endl;
            cin >> fantasy;
            if (fantasy == "YES") {
                string nameF, surnameF, titleF, heroesF;
                int numberF;
                cout << "Enter author's name: " << endl;
                cin >> nameF;
                cout << "Enter author's surname: " << endl;
                cin >> surnameF;
                cout << "Enter title: " << endl;
                cin.ignore();
                getline(cin, titleF);
                cout << "Enter book number: " << endl;
                cin >> numberF;
                cout << "Enter heroe's name: " << endl;
                cin >> heroesF;
                FantasyBook* fantasyBook = new FantasyBook(nameF, surnameF, titleF, numberF, heroesF);
                library.AddBook(fantasyBook);
            }
            else {
                string name, surname, title, heroes;
                int number;
                cout << "Enter author's name: " << endl;
                cin >> name;
                cout << "Enter author's surname: " << endl;
                cin >> surname;
                cout << "Enter title: " << endl;
                cin.ignore();
                getline(cin, title);
                cout << "Enter book number: " << endl;
                cin >> number;
                Book* book = new Book(name, surname, title, number);
                library.AddBook(book);
            }
            break;
        case 3:
            int bookNumber;
            cout << "Enter book number: ";
            cin >> bookNumber;
            library.DeleteBook(bookNumber);
            break;
        case 4:
            int numberB;
            cout << "Enter bok number: " << endl;
            cin >> numberB;
            library.BorrowBook(numberB);
            break;
        case 5:
            int numberR;
            cout << "Enter bok number: " << endl;
            cin >> numberR;
            library.ReturnBook(numberR);
            break;
        case 6:
            int numberD;
            cout << "Enter bok number: " << endl;
            cin >> numberD;
            library.DisplayBorrower(numberD);
            break;
        default:
            cout << "Shut down. Bye!";
            return 0;
        }
    }

}
