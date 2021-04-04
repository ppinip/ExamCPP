#include <iostream>
using namespace std;

class Vector {
private:
    // (x1,y1) --> (x2,y2)
    int start_x, start_y, start_z;
    int end_x, end_y, end_z;

public:
    Vector(int sx, int sy, int sz,
           int ex, int ey, int ez) : 
                start_x(sx), start_y(sy), start_z(sz),
                end_x(ex), end_y(ey), end_z(ez) {}

    // this:    (1,1)  --> (2,2)
    // other:  (10,10) --> (20,20)
    // result: (11,11) --> (22,22)
    Vector Add(Vector other) const {
        int result_sx = this->start_x + other.start_x;
        int result_sy = this->start_y + other.start_y;
        int result_sz = this->start_z + other.start_z;

        int result_ex = this->end_x + other.end_x;
        int result_ey = this->end_y + other.end_y;
        int result_ez = this->end_z + other.end_z;

        Vector result(result_sx, result_sy, result_sz,
                      result_ex, result_ey, result_ez);
        return result;
    }

    string ToString() const {
        return "(" + to_string(start_x) + "," 
                   + to_string(start_y) + "," 
                   + to_string(start_z) + ")"
             + "-->"
             + "(" + to_string(end_x) + "," 
                   + to_string(end_y) + "," 
                   + to_string(end_z) + ")";
    }

};

int main() {
    // this:    (1,1)  --> (2,2)
    // other:  (10,10) --> (20,20)
    // result: (11,11) --> (22,22)
    Vector v1(1,1,1,2,2,2);
    Vector v2(10,10,10,20,20,20);
    Vector v3 = v1.Add(v2);

    cout << "v1: " << v1.ToString() << endl;
    cout << "v2: " << v2.ToString() << endl;
    cout << "v3: " << v3.ToString() << endl;



}