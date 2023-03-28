#include <iostream>
using namespace std;

class Medicines {
private:
    double Dose_Of_Medicine;

public:

    double pharmacy() {return this-> Dose_Of_Medicine;};

    Medicines() {this-> Dose_Of_Medicine = 0.0;};
    Medicines(double MedicineInPharmacy) {this-> Dose_Of_Medicine = MedicineInPharmacy;};
    Medicines(float dose) : Medicines(static_cast<double>(dose)){};


    
    string PoisonousDose() {
        if (Dose_Of_Medicine > 10.0) {
            return "poison \n";
        }
        else {
            return "not poison \n";
        }
    }
};

int main() {

    Medicines defaultMeds;
    Medicines doubleMeds(10.1);
    Medicines floatMeds(5.02f);


    cout<<defaultMeds.PoisonousDose();


    cout<<doubleMeds.PoisonousDose();


    cout<<floatMeds.PoisonousDose();

    return 0;
}


