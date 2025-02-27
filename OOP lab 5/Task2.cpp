#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string name;
    int id;

public:
    Car(const string& name, int id) : name(name), id(id) {}

    void display() const {
        cout << "Car ID: " << id << ", Name: " << name << endl;
    }
};

class Garage {
private:
    static const int MAX_CARS = 10;
    Car* cars[MAX_CARS];
    int count;

public:
    Garage() : count(0) {
        for (int i = 0; i < MAX_CARS; ++i) {
            cars[i] = nullptr;
        }
    }

    bool parkCar(Car* car) {
        if (count < MAX_CARS) {
            cars[count++] = car;
            return true;
        } else {
            cout << "Garage is full!" << endl;
            return false;
        }
    }

    void listCars() const {
        cout << "Cars parked in the garage:" << endl;
        for (int i = 0; i < count; ++i) {
            if (cars[i]) {
                cars[i]->display();
            }
        }
    }
};

int main() {
    Car car1("Corrolla", 1);
    Car car2("Yaris", 2);
    Car car3("Swift", 3);

    Garage garage;

    garage.parkCar(&car1);
    garage.parkCar(&car2);
    garage.parkCar(&car3);

    garage.listCars();

    return 0;
}
