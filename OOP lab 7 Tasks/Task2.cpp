#include <iostream>
#include <vector>
#include <cmath> // Only for pow

using namespace std;

class PolynomialUtils; // Forward declaration

class Polynomial {
private:
    vector<int> coefficients;

public:
    // Default constructor (empty polynomial)
    Polynomial() {}

    // Constructor from a vector of coefficients
    Polynomial(const vector<int>& coeffs) : coefficients(coeffs) {
        trim();
    }

    // Operator overloads for polynomial operations
    Polynomial operator+(const Polynomial& other) const {
        size_t maxSize = max(coefficients.size(), other.coefficients.size());
        vector<int> result(maxSize, 0);

        for (size_t i = 0; i < maxSize; ++i) {
            int coeff1 = (i < coefficients.size()) ? coefficients[i] : 0;
            int coeff2 = (i < other.coefficients.size()) ? other.coefficients[i] : 0;
            result[i] = coeff1 + coeff2;
        }
        return Polynomial(result);
    }

    Polynomial operator-(const Polynomial& other) const {
        size_t maxSize = max(coefficients.size(), other.coefficients.size());
        vector<int> result(maxSize, 0);

        for (size_t i = 0; i < maxSize; ++i) {
            int coeff1 = (i < coefficients.size()) ? coefficients[i] : 0;
            int coeff2 = (i < other.coefficients.size()) ? other.coefficients[i] : 0;
            result[i] = coeff1 - coeff2;
        }
        return Polynomial(result);
    }

    Polynomial operator*(const Polynomial& other) const {
        vector<int> result(coefficients.size() + other.coefficients.size() - 1, 0);

        for (size_t i = 0; i < coefficients.size(); ++i) {
            for (size_t j = 0; j < other.coefficients.size(); ++j) {
                result[i + j] += coefficients[i] * other.coefficients[j];
            }
        }
        return Polynomial(result);
    }

    // Overload operator<< to print the polynomial
    friend ostream& operator<<(ostream& os, const Polynomial& p) {
        if (p.coefficients.empty()) {
            os << "0";
            return os;
        }

        bool first = true;
        for (size_t i = 0; i < p.coefficients.size(); ++i) {
            int coeff = p.coefficients[i];
            if (coeff != 0) {
                if (!first) {
                    os << (coeff > 0 ? " + " : " - ");
                }
                if (abs(coeff) != 1 || i == 0) {
                    os << abs(coeff);
                }
                if (i > 0) {
                    os << "x";
                    if (i > 1) {
                        os << "^" << i;
                    }
                }
                first = false;
            }
        }
        return os;
    }

    // Trim leading zeros
    void trim() {
        while (coefficients.size() > 1 && coefficients.back() == 0) {
            coefficients.pop_back();
        }
    }

    // Friend class declaration
    friend class PolynomialUtils;
};

class PolynomialUtils {
public:
    // Method to evaluate the polynomial at a given point x
    static int evaluate(const Polynomial& p, int x) {
        int result = 0;
        for (size_t i = 0; i < p.coefficients.size(); ++i) {
            result += p.coefficients[i] * static_cast<int>(pow(x, i));
        }
        return result;
    }

    // Method to calculate the derivative of the polynomial
    static Polynomial derivative(const Polynomial& p) {
        vector<int> derivCoeffs;
        for (size_t i = 1; i < p.coefficients.size(); ++i) {
            derivCoeffs.push_back(i * p.coefficients[i]);
        }
        return Polynomial(derivCoeffs);
    }
};

int main() {
    Polynomial p1({3, 0, -2, 1}); // 1x^3 - 2x^2 + 0x + 3
    Polynomial p2({4, 1});        // 1x + 4

    cout << "Polynomial 1: " << p1 << endl;
    cout << "Polynomial 2: " << p2 << endl;

    Polynomial sum = p1 + p2;
    cout << "Sum: " << sum << endl;

    Polynomial difference = p1 - p2;
    cout << "Difference: " << difference << endl;

    Polynomial product = p1 * p2;
    cout << "Product: " << product << endl;

    int x = 2;
    cout << "Evaluation of Polynomial 1 at x = " << x << ": " << PolynomialUtils::evaluate(p1, x) << endl;

    Polynomial derivative = PolynomialUtils::derivative(p1);
    cout << "Derivative of Polynomial 1: " << derivative << endl;

    return 0;
}
