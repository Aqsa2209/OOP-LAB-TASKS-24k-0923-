#include <iostream>
#include <cstdlib>

using namespace std;

void resizeArray(int*& arr, int& capacity) {
    int* newArr = new int[capacity * 2]; 
    for (int i = 0; i < capacity; i++) {
        newArr[i] = arr[i];
    }
    delete[] arr; 
    arr = newArr; 
    capacity *= 2; 
}

int main() {
    int capacity = 5;
    int size = 0;
    int* arr = new int[capacity];

    while (true) {
        if (size >= capacity) {
            resizeArray(arr, capacity); 
        }

        cout << "Enter a number (or -1 to finish): ";
        int num;
        cin >> num;

        if (num == -1) {
            break; 
        }

        arr[size] = num; 
        size++; 
    }

    cout << "Final array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr; 
    return 0;
}
