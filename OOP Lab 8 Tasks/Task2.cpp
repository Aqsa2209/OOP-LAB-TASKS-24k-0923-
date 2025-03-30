#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Shape {
protected:
    string position; 
    double borderThickness;

public:
    Shape(string pos, double thickness = 1.0)
        : position(pos), borderThickness(thickness) {}

    virtual void draw() = 0; // Pure virtual function
    virtual double calculateArea() = 0; // Pure virtual function
    virtual double calculatePerimeter() = 0; // Pure virtual function

    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(string pos, double r, double thickness = 1.0)
        : Shape(pos, thickness), radius(r) {}

    void draw() override {
        cout << "Drawing Circle at " << position << " with radius " << radius << endl;
    }

    double calculateArea() override {
        return M_PI * radius * radius; // Area = pr²
    }

    double calculatePerimeter() override {
        return 2 * M_PI * radius; // Circumference = 2pr
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(string pos, double w, double h, double thickness = 1.0)
        : Shape(pos, thickness), width(w), height(h) {}

    void draw() override {
        cout << "Drawing Rectangle at " << position << " with width " << width << " and height " << height << endl;
    }

    double calculateArea() override {
        return width * height; // Area = width * height
    }

    double calculatePerimeter() override {
        return 2 * (width + height); // Perimeter = 2(width + height)
    }
};

class Triangle : public Shape {
private:
    double a, b, c; // Lengths of the sides

public:
    Triangle(string pos, double sideA, double sideB, double sideC, double thickness = 1.0)
        : Shape(pos, thickness), a(sideA), b(sideB), c(sideC) {}

    void draw() override {
        cout << "Drawing Triangle at " << position << " with sides " << a << ", " << b << ", " << c << endl;
    }

    double calculateArea() override {
        double s = (a + b + c) / 2; // Semi-perimeter
        return sqrt(s * (s - a) * (s - b) * (s - c)); 
    }

    double calculatePerimeter() override {
        return a + b + c; // Perimeter = a + b + c
    }
};

class Polygon : public Shape {
private:
    double sides[10]; // Fixed-size array for sides
    int numSides; // Number of sides

public:
    Polygon(string pos, double s[], int n, double thickness = 1.0)
        : Shape(pos, thickness), numSides(n) {
        for (int i = 0; i < n; i++) {
            sides[i] = s[i]; // Copy sides into the array
        }
    }

    void draw() override {
        cout << "Drawing Polygon at " << position << " with sides: ";
        for (int i = 0; i < numSides; i++) {
            cout << sides[i] << " ";
        }
        cout << endl;
    }

    double calculateArea() override {
        return 0.0; 
    }

    double calculatePerimeter() override {
        double perimeter = 0.0;
        for (int i = 0; i < numSides; i++) {
            perimeter += sides[i]; // Sum of all sides
        }
        return perimeter; // Perimeter = sum of all sides
    }
};

int main() {
    Circle circle("0,0", 5);
    circle.draw();
    cout << "Area: " << circle.calculateArea() << endl;
    cout << "Perimeter: " << circle.calculatePerimeter() << endl;

    Rectangle rectangle("1,1", 4, 6);
    rectangle.draw();
    cout << "Area: " << rectangle.calculateArea() << endl;
    cout << "Perimeter: " << rectangle.calculatePerimeter() << endl;

    Triangle triangle("2,2", 3, 4, 5);
    triangle.draw();
    cout << "Area: " << triangle.calculateArea() << endl;
    cout << "Perimeter: " << triangle.calculatePerimeter() << endl;

    double polygonSides[] = {3, 4, 5, 6}; 
    Polygon polygon("3,3", polygonSides, 4);
    polygon.draw();
    cout << "Perimeter: " << polygon.calculatePerimeter() << endl;

    return 0;
}
