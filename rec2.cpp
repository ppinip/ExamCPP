#include <iostream>
using namespace std;

//  constructor
// ---------------------------------
//  - คล้ายฟังก์ชัน แต่ไม่มี return type ต้องมีชื่อตรงกับชื่อคลาส
//      - มีหรือไม่มี parameter ก็ได้
//  - สำหรับ object หนึ่ง ๆ contructor ถูกเรียกครั้งเดียวเท่านั้น ตอนสร้าง object
//  - โดยทั่วไป จะใช้ในการกำหนดค่าเริ่มต้นให้กับ data member โดยรับค่าผ่านทาง parameter
// ---------------------------------
//   default constructor 
// ---------------------------------
//  - เป็น constructor ที่ไม่มีพารามิเตอร์ ส่วนใหญ่ใช้ในการกำหนดค่า default ให้กับ data member
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

class Rectangle {

public:
    double width;
    double lenght;
                
                  //สามารถกำหนดค่า constructor แบบนี้ได้เลย
    Rectangle() : width(1), lenght(1) { //default constructor ถ้าไม่มี default objectที่ไม่มีพารามิเตอร์จะใช้งานไม่ได้ ex. Rectangle r3;
        // width = 1; 
        // lenght = 1;
    }

    // constructor overload
    explicit Rectangle(double size) : width(size), lenght(size)  { //ใส่ explicit ป้องกันการแปลงค่า
        // width = size;
        // lenght = size;
    }

    Rectangle(double w, double l) : width(w), lenght(l) {
        // width = w;
        // lenght = l;
    }

    double Area() const { 
        return width * lenght;
    }

    double Perimeter() const { 
        return 2 * (width + lenght);
    }
    
    void ChangeSize(double d) { 
        width += d;
        lenght += d;
    }

    void ChangeSize(double dw, double dl) { 
        width += dw;
        lenght += dl;
    }
};

int main() { 
    // Rectangle r1, r2;
    // r1.width = 5;
    // r1.lenght = 5;
    // r2.width = 7;
    // r2.width = 7;    

    //จากข้อมูลข้างบน ใช้ Constructor ช่วยในการสร้าง object และกำหนดค่าเริ่มต้นให้ data member ในคราวเดียวได้เลย
    Rectangle r1(5,5) , r2(7,7);
    Rectangle r3;
    // Rectangle r4 = 8; จะส่งค่าไปที่ฟังก์ชันพารามิเตอร์ตัวเดียว แปลงจากdoubleเป็นintให้เลย แต่มันไม่ดีไปซะหมด

    cout << "r1: " << r1.width << " " << r1.lenght << endl;
    cout << "r2: " << r2.width << " " << r2.lenght << endl;
    cout << "r3: " << r3.width << " " << r3.lenght << endl;
    
}   
