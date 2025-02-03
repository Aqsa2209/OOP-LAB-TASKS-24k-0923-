#include <iostream>
#include <cstdlib>

using namespace std;
void* addToArray(void* array, int size, int addValue) {
    int* arr = (int*)array; 
    for (int i = 0; i < size; i++) {
        arr[i] += addValue; 
    }
    return arr; 
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

    int addValue = 5; 
    void* modifiedArray = addToArray((void*)arr, size, addValue); // Call the function

    cout << "Modified array elements: ";
    for (int i = 0; i < size; i++) {
        cout << ((int*)modifiedArray)[i] << " "; 
    }
    cout << endl;

    delete[] arr; 
    return 0;
}
