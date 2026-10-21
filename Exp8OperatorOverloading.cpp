#include <iostream>
using namespace std;

class Distance {
public:
    int feet;
    int inch;

    // Default Constructor
    Distance() {
        this->feet = 0;
        this->inch = 0;
    }

    // Parameterized Constructor
    Distance(int f, int i) {
        this->feet = f;
        this->inch = i;
    }

    // 1. Overloading Unary (-) Operator (Decrement)
    void operator-() {
        feet--;
        inch--;
        cout << "\nFeet & Inches (Unary Decrement): " << feet << "'" << inch;
    }

    // 2. Overloading Binary (+) Operator (Addition) via call by reference
    Distance operator+(const Distance& d2) {
        Distance d3;
        d3.feet = this->feet + d2.feet;
        d3.inch = this->inch + d2.inch;

        // Normalizing inches: if inches >= 12, convert them into feet
        if (d3.inch >= 12) {
            d3.feet += d3.inch / 12;
            d3.inch = d3.inch % 12;
        }
        return d3;
    }
};

int main() {
    // Testing Unary Operator Overloading
    cout << "--- Testing Unary Operator Overloading ---";
    Distance d1(8, 9);
    cout << "\nOriginal Distance d1: " << d1.feet << "'" << d1.inch;
    -d1; // Calls operator-()
    cout << endl;

    // Testing Binary Operator Overloading
    cout << "\n--- Testing Binary Operator Overloading ---";
    Distance distA(8, 9);
    Distance distB(10, 2);
    Distance distResult;

    distResult = distA + distB; // Calls operator+()
    cout << "\nTotal Feet & Inches (distA + distB): " << distResult.feet << "'" << distResult.inch << endl;

    return 0;
}
