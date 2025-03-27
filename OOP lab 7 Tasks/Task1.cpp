#include <iostream>
#include <numeric> // for std::gcd

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    void reduce() {
        int gcd = std::gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;

        // Ensure the denominator is always positive
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    // Constructor
    Fraction(int num, int denom) : numerator(num), denominator(denom) {
        if (denom == 0) {
            throw invalid_argument("Denominator cannot be zero.");
        }
        reduce();
    }

    // Arithmetic operators
    Fraction operator+(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator, 
                        denominator * other.denominator);
    }

    Fraction operator-(const Fraction& other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator, 
                        denominator * other.denominator);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            throw invalid_argument("Cannot divide by zero.");
        }
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    // Relational operators
    bool operator==(const Fraction& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }

    bool operator<(const Fraction& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }

    bool operator>(const Fraction& other) const {
        return other < *this;
    }

    bool operator<=(const Fraction& other) const {
        return !(*this > other);
    }

    bool operator>=(const Fraction& other) const {
        return !(*this < other);
    }

    // Insertion and extraction operators
    friend ostream& operator<<(ostream& os, const Fraction& f) {
        os << f.numerator;
        if (f.denominator != 1) {
            os << "/" << f.denominator;
        }
        return os;
    }

    friend istream& operator>>(istream& is, Fraction& f) {
        char slash; // To consume the '/' character
        is >> f.numerator >> slash >> f.denominator;
        f.reduce(); // Reduce after input
        return is;
    }
};

int main() {
    Fraction f1(2, 4), f2(3, 6);
    cout << (f1 + f2) << endl; // Should output 1

    return 0;
}
