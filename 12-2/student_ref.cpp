#include <iostream>
using namespace std;

class Student {
private:
    int id;
    string name; 
    int midterm_score, final_score;

public:
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
    Student fon("Fon");

    cout << fon.ToString() << endl;

    // -------------------------------------
    //    Reference to object
    // -------------------------------------
    // สร้าง reference ของอ๊อบเจ็กต์ fon
    // rain เป็นเหมือนชื่ออีกชื่อหนึ่งของอ๊อบเจ็กต์ fon 
    // ดังนั้น rain และ fon เป็นชื่อของอ๊อบเจ็กต์เดียวกัน
    // ถ้าเปลี่ยนค่าในอันใดอันหนึ่ง อีกอันจะเปลี่ยนตามไปด้วย
    // โดย rain ไม่ใช่ pointer
    // -------------------------------------
    cout << "---- after adding ref ----"  << endl;
    Student &rain = fon;   // reference of object
    rain.SetMidtermScore(5);
    cout << "object name: "+ fon.ToString() << endl;
    cout << "object ref: "+ rain.ToString() << endl;

    // -------------------------------------
    //    Pointer to object
    // -------------------------------------
    //  - ประกาศตัวแปร pointer ชี้ไปที่อ๊อบเจ็กต์ของคลาส Student
    //  - สามารถให้ pointer ชี้ไปที่อ๊อบเจ็กต์ที่มีอยู่แล้วได้ 
    //      - ให้ pointer current_student ชี้ไปที่อ๊อบเจ็กต์ fon ที่มีอยู่แล้ว
    //  - fon, rain, current_student ใช้อ๊อบเจ็กต์ร่วมกันอยู่
    //    ถ้าเปลี่ยนค่าในอันใดอันหนึ่ง อีกอันจะเปลี่ยนตามไปด้วย
    // -------------------------------------
    cout << "---- after adding pointer ----"  << endl;
    Student *current_student = &fon;  // pointer to fon
    current_student->SetFinalScore(10);
    cout << "object name: "+ fon.ToString() << endl;
    cout << "object ref: "+ rain.ToString() << endl;
    cout << "object pointer: "+ current_student->ToString() << endl;

    // -------------------------------------
    //    Copy to object
    // -------------------------------------
    // หากเรากำหนดค่า ดังโค้ดด้านล่าง จะเป็นการก๊อบปี้
    // อ๊อบเจ็กต์ fon มาใส่ another_student
    // ดังนั้น fon กับ another_student เป็นคนละอ๊อบเจ็กต์กัน
    // ถ้าเปลี่ยนค่าในอันใดอันหนึ่ง อีกอันจะไม่เปลี่ยนตามไปด้วย
    // -------------------------------------
    cout << "---- after adding copy ----"  << endl;
    Student another_student = fon;    // copy จาก fon ไปใส่ใน object ใหม่ ชื่อ another_student
    another_student.SetFinalScore(20);
    cout << "object name: "+ fon.ToString() << endl;
    cout << "object ref: "+ rain.ToString() << endl;
    cout << "object pointer: "+ current_student->ToString() << endl;
    cout << "object copy: "+ another_student.ToString() << endl;

    // ถ้าโค้ดล่าง คือ เป็น pointer ทั้งขวามือและซ้ายมือ จะเป็นการให้
    // more_pointer ชี้ไปที่อ๊อบเจ็กต์เดียวกับ current_student
    Student *more_pointer = current_student;
    cout << more_pointer->ToString() << endl;

    // สามารถเปลี่ยนให้ pointer ชี้ไปที่อ๊อบเจ็กต์อื่นได้
    Student kwan("Kwan", 15);
    current_student = &kwan;
    cout << "move to point kwan: " << current_student->ToString() << endl;

    // operator overload
    // int x = 4 + 20;
    // string four = "4";
    // string s = four + "20";
    // cout << "x = " << x << endl;
    // cout << "s = " << s << endl;
}