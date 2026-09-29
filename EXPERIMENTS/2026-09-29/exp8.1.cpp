#include <iostream>
using namespace std;

class Distance {
public:
    int feet, inch;

    // Constructor to initialize the object's value
    Distance(int f, int i) {
        this->feet = f;
        this->inch = i;
    }

    // Overloading(-) operator to perform decrement operation
    void operator-() 
    {
        feet=feet-3;
        inch--;
        cout << "\nFeet & Inches(Decrement): " << feet << "'" << inch << endl;
    }
    void operator+()
    {
        feet=feet+3;
        inch++;
        cout << "\nFeet & Inches(Increment): " << feet << "'" << inch << endl;
    }
};

// Driver Code
int main() {
    Distance d1(8, 9);
    Distance d2(10,11);
    // Corrected: Removed the quotes so the unary operator executes
    -d1; 
    +d2;
    return 0;
}
