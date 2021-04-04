#include <string>
#include "point.h"

class Vector {
private:
    Point *start;
    Point *end; 
public:
    Vector(Point *start, Point *end) : start(start), end(end) {}

    Vector *Add(Vector *other) const {
        Point *result_start = start->Add(other->start);
        Point *result_end = end->Add(other->end);
        Vector *result = new Vector(result_start, result_end);
        return result;
    }
    void ChangeStart(int d) {
        start->Change(d);
    }
    std::string ToString() const {
        return start->ToString() + "-->" + end->ToString();
    }
};