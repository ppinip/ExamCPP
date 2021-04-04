#include <iostream>
using namespace std;

// ---------------------------------------------
// access modifier / access specifier : ตัวระบุการเข้าถึง
// ---------------------------------------------
//      - public : เราจะเข้าถึงตัวแปรหรือฟังก์ชันที่เป็น public ได้จากที่ใดก็ได้ (ภายในคลาสเอง
//                 หรือ ในคลาสอื่น หรือ ใน main function) เช่น สามารถเรียกใช้ตัวแปร
//                 r.width ได้ใน main function
//      - private : เราจะเข้าถึงตัวแปรหรือฟังก์ชันที่เป็น private ได้จากภายในคลาสเองเท่านั้น
//                  คือ ไม่สามารถเรียกใช้ตัวแปร r.width ได้ใน main function
//   ** data member ควรจะเป็น private เพื่อป้องกันการแก้ไขข้อมูลที่ไม่ถูกต้อง
//   ** constructor / member function ส่วนใหญ่จะเป็น public
// ---------------------------------------------
//   getter / setter
// ---------------------------------------------
//    - getter เป็นฟังก์ชันพื้นฐาน ใช้ในการคืนค่า data member
//    - setter เป็นฟังก์ชันพื้นฐาน ใช้ในการกำหนดค่าให้ data member โดยสามารถมีการ
//             ตรวจเช็คความถูกต้องของค่าก่อนการกำหนดค่าได้
// ---------------------------------------------
//    ToString() function
//--------------------------------------------
// เราไม่ควรมี cin และ cout ในคลาสที่เราสร้างขึ้นมา
// หากต้องการพิมพ์ข้อมูล data member ให้สร้าง member function
// เช่น ToString() เพื่อคืนค่าเป็น string
// แล้วค่อยใช้ cout ใน main()
//--------------------------------------------

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