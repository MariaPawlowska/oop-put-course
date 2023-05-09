#include <iostream>
#include <cmath>
using namespace std;

class Logarithm {
public:
    Logarithm(double base, double argument) {

        if ( argument<0)
        {
            throw logic_error ("wrong argument");
        }
        if (base<=0 || base == 1)
        {
            throw logic_error ("wrong base");
        }
        base_ = base;
        argument_ = argument;
    }

    double Calculate() const {

        return log(argument_) / log(base_);
    }

private:
    double base_;
    double argument_;
};

int main ()
{
    int argument, base;
    cout<<"write number";
    cin>>argument;
    cout<<"write base";
    cin>>base;


    try {
        Logarithm logarithm (base, argument);
        cout<<logarithm.Calculate();

    } catch (const logic_error E)
    {
        cerr<<"wrong number! "<<E.what()<<endl;
    }

    return 0;
}