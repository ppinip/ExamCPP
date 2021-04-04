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
        cout << "constructor " << name << endl;
    }

    //------------------------------
    // destructor 
    //------------------------------
    // ตัวทำลายอ๊ฮบเจ็กต์ จะทำงานเมื่ออ๊อบเจ็กต์
    // สิ้นสุดการทำงาน หรือ ออกจาก scope หรือ
    // มีการเรียกคำสั่ง delete
    //------------------------------
    ~Student() {
        cout << "DESTRUCTOR " << name << endl;
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

void func() {
    Student c("Clair");
}

int main() {

    //------------------------------
    // destructor สำหรับ object name
    //------------------------------
    // destructor จะทำงานอัตโนมัติ เมื่ออ๊อบเจ็กต์
    // สิ้นสุดการทำงาน หรือ ออกจาก scope 
    // โดยจะทำงานแบบกลับลำดับกับการสร้างอ๊อบเจ็กต์
    //------------------------------
    Student a("Apple");
    cout << "-------" << endl;

    func();
    cout << "-------" << endl;

    Student b("Bee");
    cout << "-------" << endl;

    //------------------------------
    // destructor สำหรับ "new" keyword
    //------------------------------
    // จะทำงานก็ต่อเมื่อมีการเรียกคำสั่ง delete
    // ถ้าไม่ได้เรียก delete ตัว destructor จะไม่ทำงาน
    // ลำดับการทำงานของ destructor จะขึ้นอยู่กับ
    // ลำดับของคำสั่ง delete
    //------------------------------
    Student *kathy = new Student("Kathy");
    Student *nancy = new Student("Nancy");
    cout << "-------" << endl;

    delete kathy;
    
}