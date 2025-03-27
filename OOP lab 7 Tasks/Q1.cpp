#include <iostream>

using namespace std;

class Number {
private:
    int value;

public:
    // Constructor
    Number(int v) : value(v) {}

    // Prefix decrement operator
    Number& operator--() {
        value *= 4; // Multiply by 4 for prefix
        return *this;
    }

    // Postfix decrement operator
    Number operator--(int) {
        Number temp = *this; // Store the current state
        value /= 4; // Divide by 4 for postfix
        return temp; // Return the original state
    }

    // Function to display the value
    void display() const {
        cout << "Current Value: " << value << endl;
    }
};

int main() {
    Number num(16);
    
    cout << "Initial value: ";
    num.display();

    // Prefix decrement
    --num;
    cout << "After prefix decrement (--num): ";
    num.display();

    // Postfix decrement
    num--;
    cout << "After postfix decrement (num--): ";
    num.display();

    return 0;
}
