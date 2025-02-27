#include <iostream>
using namespace std;

class Engine {
public:
    Engine() : isRunning(false) {
        cout << "Engine created." << endl;
    }

    void start() {
        isRunning = true;
        cout << "Engine started." << endl;
    }

    void stop() {
        isRunning = false;
        cout << "Engine stopped." << endl;
    }

    ~Engine() {
        cout << "Engine destroyed." << endl;
    }

private:
    bool isRunning; 
};

class Car {
public:
    Car() {
        cout << "Car created." << endl;
    }

    void startCar() {
        engine.start(); 
    }

    void stopCar() {
        engine.stop(); 
    }

    ~Car() {
        cout << "Car destroyed." << endl;
    }

private:
    Engine engine; 
};

int main() {
    cout << "Creating a Car object..." << endl;
    Car myCar; 

    myCar.startCar(); 
    myCar.stopCar(); 
    return 0;
}
