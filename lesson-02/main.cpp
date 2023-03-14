#include <iostream>
using namespace std;

class Address {
public:
    int number;
    string street;
    string place;
};

class Addition{
public:
    void print(int a, int b);
    int a;
    int b;
};

void Addition::print(int a, int b){
    cout<<a+b;
}

int main() {
    Address myaddress;
    Addition option;
    cout<<"enter the house number: \n";
    cin>>myaddress.number;
    cout<<"enter the street: \n";
    cin>>myaddress.street;
    cout<<"enter the place \n";
    cin>>myaddress.place;

    cout<<"write a: \n";
    cin>>option.a;
    cout<<"write b: \n";
    cin>>option.b;


    cout<<"Number "<<myaddress.number<<endl;
    cout<<"Street "<<myaddress.street<<endl;
    cout<<"Place "<<myaddress.place<<endl;

    option.print(option.a,option.b);

    return 0;
}
