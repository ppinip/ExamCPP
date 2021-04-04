#include <iostream>
#include "vector.h"
using namespace std;

int main() {
    // this:    (1,1)  --> (2,2)
    // other:  (10,10) --> (20,20)
    // result: (11,11) --> (22,22)
    Point *p1_start = new Point(1,1);
    Point *p1_end = new Point(2,2);
    Vector *v1 = new Vector(p1_start, p1_end);  

    Point *p2_start = new Point(10,10);
    Point *p2_end = new Point(20,20);
    Vector *v2 = new Vector(p2_start, p2_end);

    Vector *v3 = v1->Add(v2);

    cout << "V1: " << v1->ToString() << endl;
    cout << "V2: " << v2->ToString() << endl;
    cout << "V3: " << v3->ToString() << endl;   

}