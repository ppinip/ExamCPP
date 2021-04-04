#include <string>
#include "point.h"
using namespace std;

Point::Point() : x(0), y(0) {}
Point::Point(int x, int y) : x(x), y(y) {}

Point *Point::Add(Point *other) const {
    int result_x = this->x + other->x;
    int result_y = this->y + other->y;
    Point *result = new Point(result_x, result_y);
    return result;
}

string Point::ToString() const {
    return "(" + to_string(x) + "," + to_string(y) + ")";
}
