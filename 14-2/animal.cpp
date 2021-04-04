#include <iostream>
using namespace std;

// ---------------------------------
//   inheritance : การรับทอดคลาส/อ๊อบเจ็กต์
// ---------------------------------
//
//    - ประโยชน์
//        - ปรับปรุง เปลี่ยนแปลง แก้ไข โปรแกรมได้ง่าย
//        - โปรแกรมมีความยืดหยุ่น มีคุณภาพดี
//        - เกิดการ reuse code โค้ดไม่ซ้ำซ้อน
//
//    - inheritance เป็นความสัมพันธ์ของคลาสประเภทหนึ่ง 
//         เป็นความสัมพันธ์แบบ "การเป็น" (Is-A Relationship)
//
//      ความสัมพันธ์มี 2 แบบ
//          A  "เป็น"  B    (A  is a  B)
//          A   "มี"  B     (A  has a  B)
//
//      Kwan     เป็น    นักเรียน (Student)         -----> "object" is a "class"
//                                                       - kwan คือ object (หนึ่งเดียวในโลก)
//                                                       - Student คือ class
//      บัญชี scb  เป็น   บัญชีธนาคาร (BankAccount)   -----> "object" is a "class"
//                                                       - บัญชี scb คือ object
//                                                       - BankAccount คือ class
//
//      Dog      เป็น    Animal      ------> "class" is a "class"  ---> inheritance
//                                          "Dog" is an "Animal"
//                                   ประธาน "Dog" is a derived class of "Animal"
//                                   กรรม   "Animal" is a base class
//                                          "Dog" รับทอดจาก "Animal"
//
//      Car     เป็น    Vehicle     ------> "class" is a "class"  ---> inheritance
//                                          "Car" is an "Vehicle"
//                                   ประธาน "Car" is a derived class of "Vehicle"
//                                   กรรม   "Vehicle" is a base class
//
// ------- derived class ------
//    - ได้รับ data member, member function จาก base class
//      ทำให้เรียกใช้ member function ของ base class ได้
//      เสมือนกับเป็นฟังก์ชันของตนเอง
//
//    - (ต้องสร้าง constructor ขึ้นมาเอง แต่เรียกใช้ constructor
//       ของ base class ได้)
//
//    - ได้รับ data member จาก base class
//      แต่อาจจะเข้าถึงโดยตรงได้หรือไม่ก็ได้ ขึ้นอยู่กับ access modifier ที่ base class
//      กล่าวคือ
//        - ถ้า base class ประกาศเป็น protected / public จะเข้าถึงโดยตรงผ่านชื่อตัวแปรได้
//        - ถ้า base class ประกาศเป็น private จะต้องเข้าถึงผ่าน getter/setter ที่ base class
//          มีให้
//
//    - derived class สามารถปรับแต่ง member function ของ base class
//      ให้ตรงกับสถานการณ์ของ derived class นั้น ๆ ได้
//      การปรับแต่ง member function มี 2 ประเภท
//         - redefine
//         - override โดยใช้ keyword "virtual" ที่ base class
//
// 
//  - redefine function 
//      การนิยามฟังก์ชันชื่อเดียวกับของ base class แต่ปรับแต่งให้เข้ากับ
//      สถานการณ์ของ derived class นั้น ๆ ได้
//      โดย C++ จะเลือกใช้ฟังก์ชันของ static type
// 
//  - override function
//      การนิยามฟังก์ชันชื่อเดียวกับของ base class แต่ปรับแต่งให้เข้ากับ
//      สถานการณ์ของ derived class นั้น ๆ ได้
//      โดยใช้ keyword virtual ที่ base class
//      โดย C++ จะเลือกใช้ฟังก์ชันของ dynamic type
//
// ---------------------------------

//----- base class ------
class Animal {
private:
    int age;

// --------- access modifier : protected --------
//   data member/member function ที่ประกาศเป็น protected 
//      - เข้าถึงได้ภายในคลาสตนเอง
//      - derived class ก็สามารถเข้าถึงตัวแปร/ฟังก์ชันที่เป็น protected ได้
//      - แต่คลาสอื่นหรือฟังก์ชัน main() จะไม่สามารถเข้าถึงตัวแปร/ฟังก์ชันที่เป็น protected
// ----------------------------------------------
protected:
    string name;

public:
    Animal(string n, int a) : name(n), age(a) {}

    string GetName() const { return name; }
    int GetAge() const { return age; }

    void Eat(string food) {
        cout << name << " is eating " << food << endl;
    }
    void Sleep() {
        cout << name << " is sleeping..." << endl;
    }
    virtual void MakeNoise() {
        cout << name << " is making noise" << endl;
    }
};

class Dog : public Animal {
public:
    Dog(string n, int a) : Animal(n, a) {}

    void MakeNoise() {
        cout << name << " age " << GetAge() << " is woofing" << endl;
    }
};

class Cat : public Animal {
public:
    Cat(string n, int a) : Animal(n, a) {}

    void MakeNoise() {
        cout << name << " age " << GetAge() <<  " is meowing" << endl;
    }
};

class Bird : public Animal {
public:
    Bird(string n, int a) : Animal(n, a) {}

    void MakeNoise() {
        cout << name << " age " << GetAge() <<  " is chriping" << endl;
    }
};

void echo(Animal *animal) {
    animal->MakeNoise();
    animal->MakeNoise();
}

// polymorphism --- poly (multi หลาย), morph (รูปร่าง)
//    โค้ดเดียวกัน สามารถทำงาน/มีพฤติกรรมที่แตกต่างกัน
//    ทำให้โค้ดมีความยืดหยุ่น

int main() {
    Dog *toob = new Dog("Toob", 2);
    Cat *maw = new Cat("Maw", 3);
    Bird *nok = new Bird("Nok", 1);

    toob->Eat("pork");
    toob->MakeNoise();

    maw->Eat("tuna");
    maw->MakeNoise();

    nok->Eat("worm");
    nok->MakeNoise();

    echo(toob);
    echo(maw);
    cout << "-----" << endl;

    // ตัวแปรพอยเตอร์ ani มีประเภทข้อมูล 2 แบบ
    //    - static type: Animal 
    //    - dynamic type: Dog
    // -------
    //    - การ redefine จะใช้ฟังก์ชันของ static type
    //    - การ override จะใช้ฟังก์ชันของ dynamic type (มี keyword virtual ที่ base class)
    Animal *ani = new Dog("Ani", 5);
    ani->Eat("cabbage");
    ani->MakeNoise();

    ani = new Cat("Milk", 2);
    ani->Eat("cabbage");
    ani->MakeNoise();
}