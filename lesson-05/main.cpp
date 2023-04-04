#include <iostream>
#include<string>
using namespace std;
class Animal{

public:
   virtual void Pat(){};
    virtual void Introduce(){}

};

class Dog:public Animal{
private:
    string name;
    int age;
public:

    void Pat() override{
        cout<<name<<" wags his tail"<<endl;
    }
    void Ball() {
        cout<<name<<" ran for the ball"<<endl;
    }
    Dog(int n, string x){
        this -> name = x;
        this -> age = n;
    };
    void Introduce() override{
        cout<<"The dog name is: "<<this->name<<endl;
    }


};

class Cat:public Animal{
private:
    string name;
    int age;
public:
    void Pat() override{
        cout<<name<<" does purrrrrs"<<endl;
    }
    void Play(){
        cout<<name<<" play the mouse "<<endl;
    }
    Cat(int n, string x){
        this -> name = x;
        this -> age = n;
    }
    void Introduce() override{
        cout<<"The cat age is: "<<this->age<<endl;
    }
};
int main() {
    Dog dog (5,"czarek");
    Cat cat (10,"mruczek");
    dog.Introduce();
    dog.Pat();
    dog.Ball();
    cat.Pat();
    cat.Play();
    cat.Introduce();
    return 0;
}
