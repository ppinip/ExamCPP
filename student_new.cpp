#include <iostream>
using namespace std;

// --------------------------------------------------------
//   scope : ขอบเขตการใช้งาน การคงอยู่ของตัวแปร
// --------------------------------------------------------
//     - global scope: เหมือนในภาษา C
//     - class scope: ขอบเขตแค่ภายในคลาสนั้น ๆ
//     - block/function scope: ขอบเขตแค่ภายในบล็อค {} 
//                             หรือฟังก์ชันนั้น
//
//   โดย variable จะคงอยู่ได้ภายในขอบเขตที่ประกาศตัวแปรนั้นไว้เท่านั้น
//     - class-scope variable :
//          - ตัวแปร data member ที่ประกาศภายใน class block
//          - จะใช้ได้ทั่วทั้งคลาส
//     - block/function scope :
//         - ตัวแปร parameter หรือตัวแปร local ที่ประกาศใน
//           function block 
//         - ใช้ได้แค่ภายในบล็อค {} หรือฟังก์ชันนั้นเท่านั้น
// --------------------------------------------------------

class Student {
private:
    int id;
    string name; 
    int midterm_score, final_score;

public:
	// ------------------------------------------------
	//  เวลาประกาศ parameter หรือ local variable ให้เป็นชื่อ
	//  เดียวกับ data member จะทำให้ constructor หรือ function
	//  ไม่เห็น data member (จะเห็นเป็น parameter หรือ local variable)
	//
	//     - หากต้องการให้ local variable หรือ parameter ชื่อเดียวกับ
	//   data member ควรใช้ "this" pointer ในการระบุ data member
	//
	// -----------------------------------------------
	// "this" pointer พิเศษ
	// -----------------------------------------------
	//    - เป็น pointer ที่ชี้มาที่ object ปัจจุบัน
	//      ที่กำลังทำงานอยู่
	//    - ใช้ "this" ในการเข้าถึง data member / 
	//      member function ของอ๊อบเจ็กต์นี้ได้
	//      ทำให้ระบุได้ชัดเจนว่า ตัวแปรนี้เป็น data member
	//    - ช่วยแยกแยะระหว่าง data member กับ
	//      parameter / local variable (ถ้าชื่อตรงกัน)
	// -----------------------------------------------
    Student(string name, int midterm_score, int final_score) {
        this->name = name;
        this->midterm_score = midterm_score;
        this->final_score = final_score;
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
    void SetName(string name) {
        this->name = name;
    }
    void SetMidtermScore(int midterm_score) {
        this->midterm_score = midterm_score;
    }
    void SetFinalScore(int final_score) {
        this->final_score = final_score;
    }

    string ToString() const {
        string s = name + " has score of " + to_string(GetTotalScore());
        return s;
    }
};

int main() {

    Student *kathy = new Student("Kathy", 5, 6);

    cout << kathy->ToString() << endl;

    kathy->SetName("Katherine");
    cout << kathy->ToString() << endl;

    delete kathy;
}