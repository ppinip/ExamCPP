#include <iostream>
using namespace std;

// เชิงโครงสร้าง โปรแกรม แบ่งเป็น>ไฟล์ >ฟังก์ชัน
// เชิงวัตถุ โปรแกรม แบ่งเป็นไฟล์>คลาส>>ฟังก์ชัน

class Rectangle{ //คลาสเหมือนแม่พิมพ์คุกกี้ class เป็น user-define-type

public:
    // data member or attributes or property or instance variable
    double width;
    double lenght;

    // member function or method

    double Area() const { // accessor อ่าน คำนวณ ไม่เปลี่ยนค่าเมมเบอร์
        return width * lenght;
    }

    double Perimeter() const { // accessor ถ้าใส่constจะเปลี่ยนค่าไม่ได้
        return 2 * (width + lenght);
    }
    
    // -----function overload------- ชื่อเดียวกันการทำงานคล้ายกัน พารามิเตอร์ต่างกัน
    void ChangeSize(double d) { //mutator เปลี่ยนแปลงค่าเมมเบอร์
        width += d;
        lenght += d;
    }

    void ChangeSize(double dw, double dl) { 
        width += dw;
        lenght += dl;
    }
};

int main() {
    Rectangle r1, r2; //คือobject r1, r3 คุกกี้ออกมาแต่ละอัน หรือเรียกว่า instance

    cout << "Enter width and lenght: " << endl;

    cin >> r1.width >> r1.lenght
        >> r2.width >> r2.lenght;

    cout << "Area/Perimeter 1: " << r1.Area() 
         << "," << r1.Perimeter() << endl;
    cout << "Area/Perimeter 2: " << r2.Area() 
         << "," << r2.Perimeter() << endl;

   //จะทำงานทำแค่ตัว object นั้น จะsave data memberของobjectนั้นๆไว้เอง
   r1.ChangeSize(10); 
   // r1 เป็น implicit parameter(objectที่เรียกเมมเบอร์ฟังก์ชัน) (10) เป็น expilcit parameter

   r2.ChangeSize(10, 20);

   cout << "r1: " << r1.width << " " << r1.lenght << endl;
   cout << "r2: " << r2.width << " " << r2.lenght << endl;
   
   r1.ChangeSize(-1);

   cout << "r1: " << r1.width << " " << r1.lenght << endl;
   cout << "r2: " << r2.width << " " << r2.lenght << endl;



}