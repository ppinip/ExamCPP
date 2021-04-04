#include <iostream>
using namespace std;

class Student {
public:
    string name; 
    int midterm_score, final_score;

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
};

int main() {
    Student fon("Fon");
    Student kwan("Kwan", -20);
    Student ploy("Ploy", 7, 10);

    cout << fon.name << " has score of " << fon.GetTotalScore() << endl;
    cout << kwan.name << " has score of " << kwan.GetTotalScore() << endl;
    cout << ploy.name << " has score of " << ploy.GetTotalScore() << endl;
}