#include <iostream>
#include <cmath>

using namespace std;

class Polynomial {
private:
    double* coefficients;
    int degree;

public:
    Polynomial() : degree(0) {
        coefficients = new double[1]{0};
    }

    Polynomial(int deg, const double* coeffs) : degree(deg) {
        coefficients = new double[degree + 1];
        for (int i = 0; i <= degree; ++i) {
            coefficients[i] = coeffs[i];
        }
    }

    Polynomial(const Polynomial& other) : degree(other.degree) {
        coefficients = new double[degree + 1];
        for (int i = 0; i <= degree; ++i) {
            coefficients[i] = other.coefficients[i];
        }
    }

    Polynomial(Polynomial&& other) noexcept : coefficients(other.coefficients), degree(other.degree) {
        other.coefficients = nullptr;
        other.degree = 0;
    }

    ~Polynomial() {
        delete[] coefficients;
    }

    int getDegree() const {
        return degree;
    }

    double evaluate(double x) const {
        double result = 0;
        for (int i = 0; i <= degree; ++i) {
            result += coefficients[i] * pow(x, i);
        }
        return result;
    }

    Polynomial add(const Polynomial& other) const {
        int maxDegree = max(degree, other.degree);
        double* newCoeffs = new double[maxDegree + 1]{0};

        for (int i = 0; i <= degree; ++i) {
            newCoeffs[i] += coefficients[i];
        }
        for (int i = 0; i <= other.degree; ++i) {
            newCoeffs[i] += other.coefficients[i];
        }

        return Polynomial(maxDegree, newCoeffs);
    }

    Polynomial multiply(const Polynomial& other) const {
        int newDegree = degree + other.degree;
        double* newCoeffs = new double[newDegree + 1]{0};

        for (int i = 0; i <= degree; ++i) {
            for (int j = 0; j <= other.degree; ++j) {
                newCoeffs[i + j] += coefficients[i] * other.coefficients[j];
            }
        }

        return Polynomial(newDegree, newCoeffs);
    }
};

int main() {
    int degree;
    cout << "Enter the degree of the polynomial: ";
    cin >> degree;

    if (degree < 0) {
        cout << "Degree cannot be negative." << endl;
        return 1;
    }

    double* coeffs = new double[degree + 1];
    cout << "Enter the coefficients (from a0 to an): ";
    for (int i = 0; i <= degree; ++i) {
        cin >> coeffs[i];
    }

    Polynomial p(degree, coeffs);
    delete[] coeffs;

    double x;
    cout << "Enter a value for x to evaluate the polynomial: ";
    cin >> x;
    cout << "Polynomial evaluated at x = " << x << ": " << p.evaluate(x) << endl;

    return 0;
}
