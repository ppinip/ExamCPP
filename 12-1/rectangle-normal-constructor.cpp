#include <iostream>
using namespace std;

// ---------------------------------
//  constructor
// ---------------------------------
//  - คล้ายฟังก์ชัน แต่ไม่มี return type ต้องมีชื่อตรงกับชื่อคลาส
//      - มีหรือไม่มี parameter ก็ได้
//  - สำหรับ object หนึ่ง ๆ contructor ถูกเรียกครั้งเดียวเท่านั้น ตอนสร้าง object
//  - โดยทั่วไป จะใช้ในการกำหนดค่าเริ่มต้นให้กับ data member โดยรับค่าผ่านทาง parameter
// ---------------------------------
//   default constructor 
// ---------------------------------
//  - เป็น constructor ที่ไม่มีพารามิเตอร์ ส่วนใหญ่ใช้ในการกำหนดค่า default 
//    ให้กับ data member
//  - เราควรจะมี default constructor ก็ต่อเมื่อ data member ทุกตัวมีค่า default 
//  - C++ จะสร้าง default constructor ให้โดยอัตโนมัติ ถ้าไม่มีการประกาศ constructor ใด
//       - ทำให้สร้าง object แบบไม่รับ parameter ได้ ทั้งที่ไม่ได้เขียน constructor ไว้
//  - ถ้าเรามีการประกาศ constructor ไว้ C++ จะไม่สร้าง default constructor ให้
//       - ถ้าเราไม่ประกาศ default constructor เพิ่มเอง เราจะสร้าง object 
//         แบบไม่รับ parameter ไม่ได้
//       - ดังนั้น ถ้าต้องการ overload constructor โดยให้มี default constructor
//         เราต้องนิยามเพิ่มเติมเอง
// ---------------------------------
//   explicit keyword 
// ---------------------------------
// เราประกาศ explicit สำหรับ constructor ที่มี parameter 1 ค่า เพื่อป้องกัน
// ทำให้ไม่สามารถแปลงค่าทางขวามือของเครื่องหมาย = มาเป็น object ของ Rectangle ได้
//
class Rectangle {
public:
    // (1) data member
    double width;
    double length;

    Rectangle() {  // default constructor
        width = 1;
        length = 1;
        cout << "IN default constructor(s) w = " << width << endl;
    }

    explicit Rectangle(double size) {
        width = size;
        length = size;
        cout << "IN constructor(s) w = " << width << endl;
    }

    Rectangle(double w, double l) {
        width = w;
        length = l;
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
};
// object-oriented programming
int main() {

    // ใช้ constructor ช่วยในการสร้าง object และกำหนดค่าเริ่มต้นให้ data member
    // ในคราวเดียวกันเลย
    Rectangle r1(5), r2(7,10);  
    Rectangle r3;

    cout << "r1: " << r1.width << " " << r1.length << endl;
    cout << "r2: " << r2.width << " " << r2.length << endl;                                              
    cout << "r3: " << r3.width << " " << r3.length << endl;                                              
 
}