#include <iostream>
using namespace std;

class Triangle{
private:
    int x =4;
    int h = 5;
public:
    int Base(){
        return x;
    }
    int High(){
        return h;
    }
};

class Area{
public:
    float ar(Triangle triangle){
        return triangle.Base()*triangle.High()*0.5;
    }

};

int main() {
Triangle figure;
Area area;

cout<<area.ar(figure);


    return 0;
}
