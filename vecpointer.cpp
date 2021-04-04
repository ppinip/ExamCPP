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
//
//    - composition เป็นความสัมพันธ์ของคลาสประเภทหนึ่ง 
//         เป็นความสัมพันธ์แบบ "การมี" (Has-A Relationship)
//   
//      ความสัมพันธ์มี 2 แบบ
//          A  "เป็น"  B    (A  is a  B)
//          A   "มี"  B     (A  has a  B)
//
//      Kwan     เป็น    นักเรียน (Student)         -----> "object" is a "class"
//                                                       - kwan คือ object
//                                                       - Student คือ class
//      บัญชี scb  เป็น   บัญชีธนาคาร (BankAccount)   -----> "object" is a "class"
//                                                       - บัญชี scb คือ object
//                                                       - BankAccount คือ class
//
//      นักเรียน    มี    ชื่อ (name)                 -----> "class" has an attribute
//                                                       - Student คือ class
//                                                       - name คือ attribute
//      นักเรียน    มี    รายวิชาที่เรียน (Course)      -----> "class" has a "class" ---> composition
//      มหาวิทยาลัย มี    นักเรียน (Student)          -----> "class" has a "class" ---> composition
//
//      Bank         มี   BankAcount        ------> composition
//      BankAccount  มี   Bank              ------> composition
//
//      Company     มี    Employee          ------> composition
//      Employee    มี    Company           ------> composition
// ---------------------------------

class Point {
private:
    int x;
    int y;
public:
    Point(int x, int y) : x(x), y(y) {}

    // --- delegate ---
    Point *Add(Point *other) const {
        int result_x = this->x + other->x;
        int result_y = this->y + other->y;
        Point *result = new Point(result_x, result_y);
        return result;
    }

    void Change(int d) {
        x += d;
        y += d;
    }
    // --- Vector delegate to point ---
    string ToString() const {
        return "(" + to_string(x) + "," + to_string(y) + ")";
    }
};

class Vector {
private:
    Point *start;
    Point *end; 
public:
    Vector(Point *s, Point *e) : start(s), end(e) {}

    Vector *Add(Vector *other) const {
        Point *result_start = start->Add(other->start);
        Point *result_end = end->Add(other->end);
        Vector *result = new Vector(result_start, result_end);
        return result;
    }
    

    string ToString() const {
        return start->ToString() + "-->" + end->ToString();
    }
};

int main() {
    // this:    (1,1)  --> (2,2)
    // other:  (10,10) --> (20,20)
    // result: (11,11) --> (22,22)
    Point *p1_start = new Point(1,1);
    Point *p1_end = new Point(2,2);
    Vector *v1 = new Vector(p1_start, p1_end);  

    Point *p2_start = new Point(10,10);
    Point *p2_end = new Point(20, 20);
    Vector *v2 = new Vector(p2_start, p2_end);

    Vector *v3 = v1->Add(v2);

    cout << "V1: " << v1->ToString() << endl;
    // cout << "V2: " << v2.ToString() << endl;
    // cout << "V3: " << v3.ToString() << endl;  

    

}