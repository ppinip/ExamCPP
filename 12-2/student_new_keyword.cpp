#include <iostream>
using namespace std;

class Student {
private:
    int id;
    string name; 
    int midterm_score, final_score;

public:
    // constructor with member initializer
    // โดยมีการตรวจสอบความถูกต้องของค่า ก่อนกำหนดให้กับ data member ด้วย
    Student(string n, int m = 0, int f = 0) 
        : name(n), midterm_score(m), final_score(f) {
            if (m < 0) midterm_score = 0;
            if (f < 0) final_score = 0;
    }

    int GetTotalScore() const {
        return midterm_score + final_score;
    }

    // ----------- getters / setters ----------
    int GetId() const {
        return id;
    }
    string GetName() const {
        return name;
    }
    void SetName(string n) {
        name = n;
    }
    void SetMidtermScore(int m) {
        midterm_score = m;
    }
    void SetFinalScore(int f) {
        final_score = f;
    }

    string ToString() const {
        string s = name + " has score of " + to_string(GetTotalScore());
        return s;
    }
};

int main() {

    // -------------------------------------
    //    'new' keyword ในการสร้างอ๊อบเจ็กต์
    //     และ pointer ชี้ไปที่อ๊อบเจ็กต์
    // -------------------------------------
    //  - ประกาศตัวแปร pointer ชี้ไปที่อ๊อบเจ็กต์ของคลาส Rectangle
    //  - สร้าง object ด้วยคีย์เวิร์ด new
    //  - Dynamic Memory Management
    //      - ให้ C++ จองพื้นที่หน่วยความจำสำหรับเก็บออปเจ็ค
    //      - โดยใช้คำสั่ง new
    //  *** เมื่อใช้เสร็จ จะตอ้งใช้คำสั่ง delete เพื่อคืน memory
    //---------------------------------------------------
    
    Student *kathy = new Student("Kathy", 5, 6);

    cout << kathy->ToString() << endl;

    kathy->SetName("Katherine");
    cout << kathy->ToString() << endl;

    // ------------------------------------
    //   delete object สำหรับ pointer
    // ------------------------------------
    // *** เมื่อใช้ object เสร็จ 
    //      จะตอ้งใช้คำสั่ง delete เพื่อคืน memory
    // ------------------------------------
    delete kathy;
}