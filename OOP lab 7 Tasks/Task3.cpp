#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BigInteger {
private:
    vector<int> digits; // Store digits in reverse order
    bool isNegative;    // Sign of the number

    // Helper function to remove leading zeros
    void trim() {
        while (digits.size() > 1 && digits.back() == 0) {
            digits.pop_back();
        }
        if (digits.size() == 1 && digits[0] == 0) {
            isNegative = false; // Zero is non-negative
        }
    }

public:
    // Default constructor
    BigInteger() : isNegative(false) {
        digits.push_back(0); // Initialize with 0
    }

    // Constructor from string
    BigInteger(const string& number) {
        isNegative = (number[0] == '-');
        for (int i = number.size() - 1; i >= (isNegative ? 1 : 0); --i) {
            if (isdigit(number[i])) {
                digits.push_back(number[i] - '0');
            }
        }
        trim();
    }

    // Operator overload for addition
    BigInteger operator+(const BigInteger& other) const {
        if (isNegative == other.isNegative) {
            BigInteger result;
            result.isNegative = isNegative;
            int carry = 0, sum;
            size_t maxSize = max(digits.size(), other.digits.size());

            for (size_t i = 0; i < maxSize || carry; ++i) {
                sum = carry;
                if (i < digits.size()) sum += digits[i];
                if (i < other.digits.size()) sum += other.digits[i];
                result.digits.push_back(sum % 10);
                carry = sum / 10;
            }
            result.trim();
            return result;
        } else {
            // If signs are different, use subtraction
            return *this - (-other);
        }
    }

    // Operator overload for subtraction
    BigInteger operator-(const BigInteger& other) const {
        if (isNegative != other.isNegative) {
            return *this + (-other); // If signs differ, use addition
        }

        // Determine which is larger
        bool resultNegative = false;
        const BigInteger* larger = this;
        const BigInteger* smaller = &other;

        if (*this < other) {
            larger = &other;
            smaller = this;
            resultNegative = !isNegative; // Result will have the opposite sign
        }

        BigInteger result;
        result.isNegative = resultNegative;
        int borrow = 0, diff;

        for (size_t i = 0; i < larger->digits.size(); ++i) {
            diff = larger->digits[i] - (i < smaller->digits.size() ? smaller->digits[i] : 0) - borrow;
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result.digits.push_back(diff);
        }
        result.trim();
        return result;
    }

    // Negation operator
    BigInteger operator-() const {
        BigInteger result = *this;
        if (result != BigInteger(0)) {
            result.isNegative = !isNegative;
        }
        return result;
    }

    // Comparison operators
    bool operator==(const BigInteger& other) const {
        return (isNegative == other.isNegative && digits == other.digits);
    }

    bool operator!=(const BigInteger& other) const {
        return !(*this == other);
    }

    bool operator<(const BigInteger& other) const {
        if (isNegative != other.isNegative) {
            return isNegative; // If signs differ, negative is smaller
        }
        if (digits.size() != other.digits.size()) {
            return isNegative ? (digits.size() > other.digits.size()) : (digits.size() < other.digits.size());
        }
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] != other.digits[i]) {
                return isNegative ? (digits[i] > other.digits[i]) : (digits[i] < other.digits[i]);
            }
        }
        return false; // They are equal
    }

    bool operator>(const BigInteger& other) const {
        return other < *this;
    }

    // I/O operators
    friend ostream& operator<<(ostream& os, const BigInteger& num) {
        if (num.isNegative) os << '-';
        for (auto it = num.digits.rbegin(); it != num.digits.rend(); ++it) {
            os << *it;
        }
        return os;
    }

    friend istream& operator>>(istream& is, BigInteger& num) {
        string input;
        is >> input;
        num = BigInteger(input);
        return is;
    }
};

int main() {
    BigInteger num1("123456789");
    BigInteger num2("987654321");
    BigInteger sum = num1 + num2;
    BigInteger difference = num2 - num1;

    cout << "Number 1: " << num1 << endl;
    cout << "Number 2: " << num2 << endl;
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << difference << endl;

    return 0;
}
