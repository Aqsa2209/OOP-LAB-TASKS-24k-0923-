#include <iostream>

using namespace std;

// Base templated class
template <typename T>
class Base {
protected:
    T a, b;

public:
    Base(T x, T y) : a(x), b(y) {}

    T multiply() const {
        return a * b;
    }

    void display() const {
        cout << "Base multiplication: " << multiply() << endl;
    }
};

// Derived templated class inheriting from Base<T>
template <typename T>
class Derived : public Base<T> {
private:
    T c, d;

public:
    Derived(T x, T y, T z, T w) : Base<T>(x, y), c(z), d(w) {}

    T multiplyDerived() const {
        return c * d;
    }

    void displayAll() const {
        // Call base class function
        this->display();

        // Show derived multiplication
        cout << "Derived multiplication: " << multiplyDerived() << endl;
    }
};

// Demo
int main() {
    Derived<int> obj(2, 3, 4, 5);
    obj.displayAll();

    return 0;
}
