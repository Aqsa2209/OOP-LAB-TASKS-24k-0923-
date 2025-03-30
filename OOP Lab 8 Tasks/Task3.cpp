#include <iostream>
using namespace std;

class Currency {
protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate; // Rate with respect to base currency (e.g., USD)

public:
    Currency(double amt, string code, string symbol, double rate)
        : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}

    virtual double convertToBase() const {
        return amount * exchangeRate; // Converts to base currency
    }

    virtual double convertTo(const Currency &targetCurrency) const {
        double baseValue = convertToBase();
        return baseValue / targetCurrency.exchangeRate; // Convert base currency to target currency
    }

    virtual void displayCurrency() const {
        cout << currencySymbol << " " << amount << " (" << currencyCode << ")" << endl;
    }
};

class Dollar : public Currency {
public:
    Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {} // Base currency
};

class Euro : public Currency {
public:
    Euro(double amt) : Currency(amt, "EUR", "€", 1.1) {} // Corrected Euro symbol
};

class Rupee : public Currency {
public:
    Rupee(double amt) : Currency(amt, "INR", "?", 0.013) {} // Corrected Rupee symbol
};

int main() {
    Dollar usd(100);
    Euro eur(50);
    Rupee inr(5000);

    usd.displayCurrency();
    eur.displayCurrency();
    inr.displayCurrency();

    cout << "100 USD to EUR: " << usd.convertTo(eur) << " EUR" << endl;
    cout << "50 EUR to INR: " << eur.convertTo(inr) << " INR" << endl;
    cout << "5000 INR to USD: " << inr.convertTo(usd) << " USD" << endl;

    return 0;
}

