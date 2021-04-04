#include <iostream>
using namespace std;

class Point {
private:
    int x;
    int y;
public:
    Point(int x, int y) : x(x), y(y) {}

    Point Add(Point other) const {
        int result_x = this->x + other.x;
        int result_y = this->y + other.y;
        Point result(result_x, result_y);
        return result;
    }
    // delegate
    string ToString() const {
        return "(" + to_string(x) + "," + to_string(y) + ")";
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

    Point p1_start(1,1), p1_end(2,2);
    Vector v1(p1_start, p1_end);

    Point p2_start(10, 10), p2_end(20,20);
    Vector v2(p2_start, p2_end);

    Vector v3 = v1.Add(v2);

    cout << "V1: " << v1.ToString() << endl;
    cout << "V2: " << v2.ToString() << endl;
    cout << "V3: " << v3.ToString() << endl;

}