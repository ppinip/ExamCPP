#include <iostream>
using namespace std;

// ---------------------------------
//   composition : การประกอบกันของคลาส/อ๊อบเจ็กต์
// ---------------------------------
//    - composition คือ การมี data member ที่เป็นอ๊อบเจ็กต์
//      ของคลาสใด ๆ
// 
//    - data member ในคลาส แบ่งได้เป็น 2 ประเภท 
//        - primitive type: เรียกว่า attribute
//                          คุณลักษณะของอ๊อบเจ็กต์นั้น ๆ
//        - class/object type: เรียกว่า composition
//                             เกิดเป็นความสัมพันธ์ของคลาส
// 
//    - ประโยชน์
//        - ปรับปรุง เปลี่ยนแปลง แก้ไข โปรแกรมได้ง่าย
//        - โปรแกรมมีความยืดหยุ่น มีคุณภาพดี
// ---------------------------------

class Course {
private:
    int id;
    string name;
    string instructor;    
};

class Student {
private:

    // primitive type: attribute คุณลักษณะของอ๊อบเจ็กต์นั้น ๆ
    int id;
    string name; 
    int midterm_score, final_score;

    // object type: composition
    Course **registered_course;
    Student *rahat_brother;  // พี่รหัส

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

void func() {
    Student c("Clair");
}

int main() {



}