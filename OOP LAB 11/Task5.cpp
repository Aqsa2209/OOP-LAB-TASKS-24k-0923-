#include <iostream>
#include <stdexcept>

using namespace std;

// Custom exception for stack underflow
class StackUnderflowException : public exception {
public:
    const char* what() const noexcept override {
        return "StackUnderflowException: Attempted to access an element from an empty stack.";
    }
};

// Stack class template using raw array
template <typename T>
class Stack {
private:
    T* data;
    int capacity;
    int topIndex;

    void resize() {
        capacity *= 2;
        T* newData = new T[capacity];
        for (int i = 0; i <= topIndex; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

public:
    Stack(int initialCapacity = 10) : capacity(initialCapacity), topIndex(-1) {
        data = new T[capacity];
    }

    ~Stack() {
        delete[] data;
    }

    void push(const T& value) {
        if (topIndex + 1 == capacity) {
            resize();
        }
        data[++topIndex] = value;
    }

    void pop() {
        if (isEmpty()) {
            throw StackUnderflowException();
        }
        --topIndex;
    }

    T top() const {
        if (isEmpty()) {
            throw StackUnderflowException();
        }
        return data[topIndex];
    }

    bool isEmpty() const {
        return topIndex < 0;
    }

    int size() const {
        return topIndex + 1;
    }
};

// Demo program
int main() {
    Stack<int> s;

    try {
        s.push(5);
        s.push(10);
        s.push(15);

        cout << "Top element: " << s.top() << endl; // 15
        s.pop();
        cout << "Top after pop: " << s.top() << endl; // 10

        s.pop();
        s.pop();

        // Trigger exception
        cout << "Accessing top of empty stack..." << endl;
        cout << s.top() << endl;

    } catch (const StackUnderflowException& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}

