#include <iostream>
#include <memory>
#include <string>

using namespace std;

class BadTypeException {
public:
    BadTypeException(const string& message) : message(message) {}
    const char* what() const { return message.c_str(); }
private:
    string message;
};

class Base {
public:
    virtual ~Base() = default;
};

template<typename T>
class Derived : public Base {
public:
    T value;
    Derived(const T& val) : value(val) {}
};

class TypeSafeContainer {
private:
    unique_ptr<Base> data;

public:
    template<typename T>
    void store(const T& value) {
        data = make_unique<Derived<T>>(value);
    }

    template<typename T>
    T get() const {
        Derived<T>* derived = dynamic_cast<Derived<T>*>(data.get());
        if (!derived) {
            throw BadTypeException("Type mismatch: requested type does not match stored type.");
        }
        return derived->value;
    }
};

int main() {
    try {
        TypeSafeContainer container;
        container.store(42);
        cout << "Stored int: " << container.get<int>() << endl;

        container.store(3.14f);
        cout << "Stored float: " << container.get<float>() << endl;

        container.store(string("Hello"));
        cout << "Stored string: " << container.get<string>() << endl;

        // Uncommenting the following line will throw an exception
        // cout << "Trying to get an int: " << container.get<int>() << endl;
    } catch (const BadTypeException& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}
