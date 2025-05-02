#include <iostream>
#include <stdexcept>

using namespace std;

// Custom exception
class ArrayIndexOutOfBounds : public exception {
public:
    const char* what() const noexcept override {
        return "ArrayIndexOutOfBounds: Invalid index accessed.";
    }
};

// Template class SafeArray<T>
template<typename T>
class SafeArray {
private:
    T* data;
    size_t size;

public:
    SafeArray(size_t s) : size(s) {
        data = new T[size]();
    }

    ~SafeArray() {
        delete[] data;
    }

    // Copy constructor
    SafeArray(const SafeArray<T>& other) : size(other.size) {
        data = new T[size];
        for (size_t i = 0; i < size; ++i)
            data[i] = other.data[i];
    }

    // Assignment operator
    SafeArray& operator=(const SafeArray<T>& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new T[size];
            for (size_t i = 0; i < size; ++i)
                data[i] = other.data[i];
        }
        return *this;
    }

    // Access with bounds checking
    T& operator[](int index) {
        if (index < 0 || index >= static_cast<int>(size))
            throw ArrayIndexOutOfBounds();
        return data[index];
    }

    const T& operator[](int index) const {
        if (index < 0 || index >= static_cast<int>(size))
            throw ArrayIndexOutOfBounds();
        return data[index];
    }

    size_t getSize() const {
        return size;
    }
};

// Demo program
int main() {
    SafeArray<int> arr(5);

    // Fill and display the array
    for (int i = 0; i < 5; ++i)
        arr[i] = i * 10;

    cout << "SafeArray contents:\n";
    for (int i = 0; i < 5; ++i)
        cout << arr[i] << " ";
    cout << endl;

    // Attempt to access invalid index
    try {
        cout << "Accessing arr[7]...\n";
        cout << arr[7] << endl; // Should throw
    } catch (const ArrayIndexOutOfBounds& e) {
        cout << e.what() << endl;
    }

    return 0;
}


