#include <iostream>
using namespace std;

class Rectangle {
public:
    // (1) data member
    double width;
    double length;

    // constructor using member initializer
    Rectangle() : width(1), length(1) {  
        cout << "IN default constructor(s) w = " << width << endl;
    }

    explicit Rectangle(double size) : width(size), length(size) {
        cout << "IN constructor(s) w = " << width << endl;
    }

    Rectangle(double w, double l) : width(w), length(l) {
        cout << "IN constructor(w,l) w = " << width << endl;
    }

    // (2) member function
    // ---- accessor ----
    double Area() const {
        return width * length;
    }

    // ---- accessor ----
    double Perimeter() const {
        return 2 * (width + length);
    }

    // ---- mutator ----
    void ChangeSize(double d) {
        width = width + d;
        length = length + d;
    }

    void ChangeSize(double dw, double dl) {
        width = width + dw;
        length = length + dl;
    }
};

int main() {

    Rectangle r1(5), r2(7,10);  
    Rectangle r3;

    cout << "r1: " << r1.width << " " << r1.length << endl;
    cout << "r2: " << r2.width << " " << r2.length << endl;                                              
    cout << "r3: " << r3.width << " " << r3.length << endl;                                              
 
}