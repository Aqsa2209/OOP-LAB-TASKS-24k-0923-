#include <iostream>
#include <string>

using namespace std;
class Vehicles {
protected:
    double price;

public:
    Vehicles(double p) : price(p) {}

    double getPrice() const {
        return price;
    }
};
class Car : public Vehicles {
protected:
    int seatingCapacity;
    int numberOfDoors;
    string fuelType;

public:
    Car(double p, int capacity, int doors, const string& fuel)
        : Vehicles(p), seatingCapacity(capacity), numberOfDoors(doors), fuelType(fuel) {}

    int getSeatingCapacity() const {
        return seatingCapacity;
    }

    int getNumberOfDoors() const {
        return numberOfDoors;
    }

    string getFuelType() const {
        return fuelType;
    }
};
class Motorcycle : public Vehicles {
protected:
    int numberOfCylinders;
    int numberOfGears;
    int numberOfWheels;

public:
    Motorcycle(double p, int cylinders, int gears, int wheels)
        : Vehicles(p), numberOfCylinders(cylinders), numberOfGears(gears), numberOfWheels(wheels) {}

    int getNumberOfCylinders() const {
        return numberOfCylinders;
    }

    int getNumberOfGears() const {
        return numberOfGears;
    }

    int getNumberOfWheels() const {
        return numberOfWheels;
    }
};
class Audi : public Car {
private:
    string modelType;

public:
    Audi(double p, int capacity, int doors, const string& fuel, const string& model)
        : Car(p, capacity, doors, fuel), modelType(model) {}

    void displayDetails() const {
        cout << "Audi Car Details:" << endl;
        cout << "Price: $" << getPrice() << endl;
        cout << "Seating Capacity: " << getSeatingCapacity() << endl;
        cout << "Number of Doors: " << getNumberOfDoors() << endl;
        cout << "Fuel Type: " << getFuelType() << endl;
        cout << "Model Type: " << modelType << endl;
    }
};

class Yamaha : public Motorcycle {
private:
    string makeType;

public:
    Yamaha(double p, int cylinders, int gears, int wheels, const string& make)
        : Motorcycle(p, cylinders, gears, wheels), makeType(make) {}

    void displayDetails() const {
        cout << "Yamaha Motorcycle Details:" << endl;
        cout << "Price: $" << getPrice() << endl;
        cout << "Number of Cylinders: " << getNumberOfCylinders() << endl;
        cout << "Number of Gears: " << getNumberOfGears() << endl;
        cout << "Number of Wheels: " << getNumberOfWheels() << endl;
        cout << "Make Type: " << makeType << endl;
    }
};

int main() {
    Audi myAudi(50000, 5, 4, "Petrol", "A6");
    Yamaha myYamaha(15000, 2, 5, 2, "YZF-R3");
    myAudi.displayDetails();
    cout << endl;
    myYamaha.displayDetails();

    return 0;
}
