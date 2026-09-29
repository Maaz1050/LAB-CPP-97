#include <iostream> // Include necessary header for input/output stream 
#include <cmath> // Include necessary header for mathematical functions 
using namespace std;
const double PI = 3.14159; // Define constant value for PI 

class Shape { // Define a base class named Shape 
public: 
    // Virtual member function to calculate the area (pure virtual function) 
    virtual double calculateArea() const = 0; 
    // Virtual member function to calculate the perimeter (pure virtual function) 
    virtual double calculatePerimeter() const = 0; 
    // Virtual destructor ensuring safe cleanup of derived classes
    virtual ~Shape() {} 
}; 

class Circle: public Shape // Define a derived class named Circle inheriting from Shape
{ 
private:  
    double radius; // Private member variable to store the radius of the circle 
public: 
    // Constructor for Circle class 
    Circle(double rad): radius(rad) {} 
    // Override the virtual member function to calculate the area 
    double calculateArea() const override { 
        return PI * pow(radius, 2); // Calculate the area of the circle using the radius 
    } 
    // Override the virtual member function to calculate the perimeter 
    double calculatePerimeter() const override { 
        return 2 * PI * radius; // Calculate the perimeter of the circle using the radius 
    } 
}; 

class Rectangle: public Shape { // Define a derived class named Rectangle inheriting from Shape 
private:  
    double length; // Private member variable to store the length of the rectangle 
    double width; // Private member variable to store the width of the rectangle 
public: 
    // Constructor for Rectangle class 
    Rectangle(double len, double wid): length(len), width(wid) {} 
    // Override the virtual member function to calculate the area 
    double calculateArea() const override { 
        return length * width; // Calculate the area of the rectangle using its length and width 
    } 
    // Define the virtual member function to calculate the perimeter 
    double calculatePerimeter() const override { 
        return 2 * (length + width); // Calculate the perimeter of the rectangle using its length and width 
    } 
}; 

class Triangle: public Shape { // Define a derived class named Triangle inheriting from Shape
private:
    double side1; // Private member variables to store the lengths of the three sides
    double side2;
    double side3;
public:
    // Constructor for Triangle class
    Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}

    // Override the virtual member function to calculate the area using Heron's formula
    double calculateArea() const override {
        double s = (side1 + side2 + side3) / 2.0; // Semi-perimeter
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    // Override the virtual member function to calculate the perimeter
    double calculatePerimeter() const override {
        return side1 + side2 + side3; // Sum of all three sides
    }
};

int main() {
    // Create shapes dynamically using base class pointers to demonstrate polymorphism
    Shape* circle = new Circle(5.0);
    Shape* rectangle = new Rectangle(4.0, 6.0);
    Shape* triangle = new Triangle(3.0, 4.0, 5.0);

    // Print details for Circle
    cout << "Circle Area: " << circle->calculateArea() << "\n";
    cout << "Circle Perimeter: " << circle->calculatePerimeter() << "\n\n";

    // Print details for Rectangle
    cout << "Rectangle Area: " << rectangle->calculateArea() << "\n";
    cout << "Rectangle Perimeter: " << rectangle->calculatePerimeter() << "\n\n";

    // Print details for Triangle
    cout << "Triangle Area: " << triangle->calculateArea() << "\n";
    cout << "Triangle Perimeter: " << triangle->calculatePerimeter() << "\n\n";

    // Clean up allocated memory
    delete circle;
    delete rectangle;
    delete triangle;

    return 0;
}
