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

class Point {
private:
    int x;
    int y;
    int z;
public:
    Point(int x, int y, int z) : x(x), y(y), z(z) {}

    // --- delegate ---
    Point Add(Point other) const {
        int result_x = this->x + other.x;
        int result_y = this->y + other.y;
        int result_z = this->z + other.z;
        Point result(result_x, result_y, result_x);
        return result;
    }
    // --- Vector delegate to point ---
    string ToString() const {
        return "(" + to_string(x) + "," + to_string(y) + ","  
                   + to_string(z) + ")";
    }
};

class Vector {
private:
    Point start;
    Point end; 
public:
    Vector(Point s, Point e) : start(s), end(e) {}

    Vector Add(Vector other) const {
        Point result_start = start.Add(other.start);
        Point result_end = end.Add(other.end);
        Vector result(result_start, result_end);
        return result;
    }
    string ToString() const {
        return start.ToString() + "-->" + end.ToString();
    }
};

int main() {
    // this:    (1,1)  --> (2,2)
    // other:  (10,10) --> (20,20)
    // result: (11,11) --> (22,22)
    Point p1_start(1,1,1), p1_end(2,2,2);
    Vector v1(p1_start, p1_end);  

    Point p2_start(10,10,10), p2_end(20,20,20);
    Vector v2(p2_start, p2_end);

    Vector v3 = v1.Add(v2);

    cout << "V1: " << v1.ToString() << endl;
    cout << "V2: " << v2.ToString() << endl;
    cout << "V3: " << v3.ToString() << endl;    
}