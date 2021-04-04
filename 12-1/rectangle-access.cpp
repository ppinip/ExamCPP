#include <iostream>
using namespace std;

class Rectangle {

private:
    // (1) data member
    //       ควรเป็น private เสมอ
    double width;
    double length;

public:
    // constructor
    //       ควรเป็น public
    Rectangle(double w, double l) : width(w), length(l) {
        if (w <= 0) width = 1;
        if (l <= 0) length = 1;
    }

    // (2) member function
    //       ควรเป็น public
    // ---- accessor ----
    double Area() const {
        return width * length;
    }

    // ---- accessor ----
    double Perimeter() const {
        return 2 * (width + length);
    }

    // ---- mutator ----
    // ****** function overload ******
    void ChangeSize(double d) {
        width = width + d;
        length = length + d;
    }
    // ****** function overload ******
    void ChangeSize(double dw, double dl) {
        width = width + dw;
        length = length + dl;
    }

    // ---- getters / setters ----
    double GetWidth() const {
        return width;
    }

    double GetLength() const {
        return length;
    }

    void SetWidth(double w) {
        if (w > 0)
            width = w;
    }

    void SetLength(double l) {
        if (l > 0)
            length = l;
    }
};
// object-oriented programming
int main() {

    // ใช้ constructor ช่วยในการสร้าง object และกำหนดค่าเริ่มต้นให้ data member
    // ในคราวเดียวกันเลย
    Rectangle r1(5,-10);  

    cout << "r1: " << r1.GetWidth() << " " << r1.GetLength() << endl;
    
    r1.SetWidth(-50);
    cout << "r1: " << r1.GetWidth() << " " << r1.GetLength() << endl;
}