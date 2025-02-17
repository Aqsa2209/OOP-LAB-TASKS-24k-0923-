#include <iostream>

using namespace std;

class DynamicArray {
private:
    int* data;
    int arraySize;

public:
    DynamicArray() : data(nullptr), arraySize(0) {}

    DynamicArray(int n) : arraySize(n) {
        if (n < 0) {
            cout << "Size cannot be negative" << endl;
            arraySize = 0;
            data = nullptr;
            return;
        }
        data = new int[arraySize]{0};
    }

    DynamicArray(const DynamicArray& other) : arraySize(other.arraySize) {
        data = new int[arraySize];
        for (int i = 0; i < arraySize; ++i) {
            data[i] = other.data[i];
        }
    }

    DynamicArray(DynamicArray&& other) noexcept : data(other.data), arraySize(other.arraySize) {
        other.data = nullptr;
        other.arraySize = 0;
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            delete[] data;
            arraySize = other.arraySize;
            data = new int[arraySize];
            for (int i = 0; i < arraySize; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    DynamicArray& operator=(DynamicArray&& other) noexcept {
        if (this != &other) {
            delete[] data;
            data = other.data;
            arraySize = other.arraySize;
            other.data = nullptr;
            other.arraySize = 0;
        }
        return *this;
    }

    ~DynamicArray() {
        delete[] data;
    }

    int size() const {
        return arraySize;
    }

    int& at(int index) {
        if (index < 0 || index >= arraySize) {
            cout << "Index out of range" << endl;
            exit(EXIT_FAILURE);
        }
        return data[index];
    }

    const int& at(int index) const {
        if (index < 0 || index >= arraySize) {
            cout << "Index out of range" << endl;
            exit(EXIT_FAILURE);
        }
        return data[index];
    }

    void resize(int newSize) {
        if (newSize < 0) {
            cout << "New size cannot be negative" << endl;
            return;
        }
        int* newData = new int[newSize]{0};
        int minSize = (newSize < arraySize) ? newSize : arraySize;
        for (int i = 0; i < minSize; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        arraySize = newSize;
    }
};

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    DynamicArray arr(size);
    cout << "Enter " << size << " elements for the array:" << endl;
    for (int i = 0; i < arr.size(); ++i) {
        cout << "Element [" << i << "]: ";
        cin >> arr.at(i);
    }

    cout << "Array elements: ";
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr.at(i) << " ";
    }
    cout << endl;

    DynamicArray arrCopy = arr;
    cout << "Copied array elements: ";
    for (int i = 0; i < arrCopy.size(); ++i) {
        cout << arrCopy.at(i) << " ";
    }
    cout << endl;

    DynamicArray arrMove = std::move(arr);
    cout << "Moved array elements: ";
    for (int i = 0; i < arrMove.size(); ++i) {
        cout << arrMove.at(i) << " ";
    }
    cout << endl;

    arrMove.resize(8);
    cout << "Resized array elements: ";
    for (int i = 0; i < arrMove.size(); ++i) {
        cout << arrMove.at(i) << " ";
    }
    cout << endl;

    return 0;
}
