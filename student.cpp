#include <iostream>
using namespace std;

class Student {
private:
    int id;
    string name; 
    int midterm_score, final_score;

public:
    // constructor with member initializer ยุบรวมกันใช้ได้ทั้งพารามิเตอร์1ค่าและ2,3 
    // โดยมีการตรวจสอบความถูกต้องของค่า ก่อนกำหนดให้กับ data member ด้วย
    Student(string n, int m = 0, int f = 0) //เริ่มใส่จากด้านหลังสุดก่อน
        : name(n), midterm_score(m), final_score(f) {
            if (m < 0) midterm_score = 0;
            if (f < 0) final_score = 0;
    }

    ~Student(){ //destructor
        //object name,ref ทำลายให้อัตโนมัติ 
        //ถ้าเป็นคำสั่ง pointer,new ต้องมีdelete
    }

    int GetTotalScore() const {
        return midterm_score + final_score;
    }

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
    Student kwan("Kwan", 45);
    Student ploy("Ploy", 7, 10);

    cout << fon.ToString() << endl;
    cout << kwan.ToString() << endl;
    cout << ploy.ToString() << endl;

    Student &rain = fon; //refference to obj
    rain.SetMidtermScore(5);
    cout << "object name: " + fon.ToString() << endl;
    cout << "object ref: " + rain.ToString() << endl;

    Student *current_student = &fon; //pointer to obj
    current_student->SetFinalScore(10);
    cout << "object name: " + fon.ToString() << endl;
    cout << "object ref: " + rain.ToString() << endl;
    cout << "object pointer: " + current_student->ToString() << endl;

    current_student = &kwan;
    cout << "move to point kwan: " << current_student->ToString() << endl;

    Student another_student = fon; //copy จาก fon ไปใส่ใน object ใหม่ ชื่อ another_student
    another_student.SetFinalScore(20);
    cout << "object name: " + fon.ToString() << endl;
    cout << "object ref: " + rain.ToString() << endl;
    cout << "object pointer: " + current_student->ToString() << endl;
    cout << "object copy: " + another_student.ToString() << endl;


}