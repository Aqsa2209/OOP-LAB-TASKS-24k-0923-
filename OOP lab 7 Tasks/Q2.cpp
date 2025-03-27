#include <iostream>

using namespace std;

class Shape {
private:
    double area; // Area of the shape

public:
    // Constructor to initialize the area
    Shape(double a) : area(a) {}

    // Function to get the area
    double Area() const {
        return area;
    }

    // Overloading the + operator to add areas of two shapes
    Shape operator+(const Shape& other) {
        return Shape(this->area + other.area); // Create a new Shape object with the sum of areas
    }
};

int main() {
    // Create two Shape objects with different areas
    Shape shape1(10.5); // Area of shape1
    Shape shape2(15.3); // Area of shape2

    // Calculate the total area using the overloaded + operator
    Shape totalArea = shape1 + shape2;

    // Display the areas
    cout << "Area of shape1: " << shape1.Area() << endl;
    cout << "Area of shape2: " << shape2.Area() << endl;
    cout << "Total area (shape1 + shape2): " << totalArea.Area() << endl;

    return 0;
}
