#include <iostream>
#include <string>

using namespace std;

class Car {
protected:
    string model;
    double price;

public:
    Car(const string& m, double p) : model(m), price(p) {}

    string getModel() const {
        return model;
    }

    void setModel(const string& m) {
        model = m;
    }

    virtual void setPrice(double p) = 0; // Abstract method

    double getPrice() const {
        return price;
    }

    void displayInfo() const {
        cout << "Model: " << model << ", Price: $" << price << endl;
    }
};

class Color : public Car {
public:
    Color(const string& m, double p) : Car(m, p) {}

    void setPrice(double p) override {
        price = p;
    }
};

class Company : public Car {
public:
    Company(const string& m, double p) : Car(m, p) {}

    void setPrice(double p) override {
        price = p;
    }
};

int main() {
    Color car1("Red Car", 25000);
    Company car2("Blue Car", 30000);

    car1.setPrice(24000);
    car2.setPrice(29000);

    car1.displayInfo();
    car2.displayInfo();

    return 0;
}
