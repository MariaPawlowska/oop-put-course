#include <iostream>
#include <map>
#include<string>
using namespace std;
class Cantor {
public:
    Cantor() = default;
    virtual ~Cantor() = default;

    virtual double Rate(const string& abbreviation) const = 0;
};

/*class Euro{
public:
    Euro();
    string abb;
    double am;
    Euro(string abbreviation,double amount): abb(abbreviation), am(amount) {};
};*/

class FakeUsdCantor : public Cantor {
public:
    FakeUsdCantor() {
        // rates_ map with values for ten most popular currencies relative to USD
        rates_ = {
                {"EUR", 0.85},
                {"JPY", 110.66},
                {"GBP", 0.73},
                {"CHF", 0.91},
                {"CAD", 1.25},
                {"AUD", 1.34},
                {"CNY", 6.47},
                {"HKD", 7.78},
                {"NZD", 1.44},
                {"KRW", 1153.89}
        };
    }

    double Rate(const std::string& abbreviation) const override {
        auto it = rates_.find(abbreviation);
        if (it != rates_.end()) {
            return it->second;
        }
        // Handle error case when currency abbreviation is not found
        return 0.0;
    }

private:
    std::map<std::string, double> rates_;
};

class Currency {
public:
    Currency() = default;
    virtual ~Currency() = default;

    virtual double ConvertedToDollars(const Cantor& cantor) const = 0;
    virtual std::string Abbreviation() const = 0;
    virtual double Amount() const = 0;
};
class Euro : public Currency {
private:
    string abbrev;
    double amount_;

public:
    Euro(std::string abbreviation, double amount) : abbrev(abbreviation), amount_(amount) {}

    double ConvertedToDollars(const Cantor& cantor) const override {
        double exchange_rate = cantor.Rate(abbrev);
        return amount_ / exchange_rate;
    }

    string Abbreviation() const override {
        return abbrev;
    }

    double Amount() const override {
        return amount_;
    }
};

int main() {
    FakeUsdCantor usd;
    Euro my_currency("JPY", 1000);
    cout << "Abbreviation: " << my_currency.Abbreviation() << endl;
    cout << "Amount: " << my_currency.Amount() << endl;
    cout << "Amount in USD: " << my_currency.ConvertedToDollars(usd) << endl;
    return 0;
}