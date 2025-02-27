#include <iostream>

using namespace std;

class Car {
public:
    
    Car(const string& engine, int horsepower, int seating_capacity, int no_of_speakers)
        : engine(engine), horsepower(horsepower), seating_capacity(seating_capacity), no_of_speakers(no_of_speakers) {}
    void changeAttributes(const string& newEngine, int newHorsepower, int newSeatingCapacity, int newNoOfSpeakers) const {
        const_cast<string&>(engine) = newEngine;
        const_cast<int&>(horsepower) = newHorsepower;
        const_cast<int&>(seating_capacity) = newSeatingCapacity;
        const_cast<int&>(no_of_speakers) = newNoOfSpeakers;
    }
    void displayDetails() const {
        cout << "Car Details:" << endl;
        cout << "Engine: " << engine << endl;
        cout << "Horsepower: " << horsepower << endl;
        cout << "Seating Capacity: " << seating_capacity << endl;
        cout << "Number of Speakers: " << no_of_speakers << endl;
    }

private:
    mutable string engine;          
    mutable int horsepower;
    mutable int seating_capacity;
    mutable int no_of_speakers;
};

int main() {
    Car myCar("V6", 300, 5, 6);

    cout << "Initial ";
    myCar.displayDetails();

    myCar.changeAttributes("V8", 400, 7, 8);

    cout << "Updated ";
    myCar.displayDetails();

    return 0;
}
