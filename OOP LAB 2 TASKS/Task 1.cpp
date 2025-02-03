#include <iostream>
#include <cstdlib>

using namespace std;

int sum(int* arr, int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i]; 
    }
    return total;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Please provide numbers as arguments." << endl;
        return 1;
    }

    int size = argc - 1;
    int* arr = new int[size];

    for (int i = 1; i < argc; i++) {
        arr[i - 1] = atoi(argv[i]);
    }

    int total = sum(arr, size);
    cout << "Sum of array elements: " << total << endl;

    delete[] arr; 
    return 0;
}
