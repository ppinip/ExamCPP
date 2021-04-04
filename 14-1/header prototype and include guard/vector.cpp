#include <string>
#include "vector.h"
using namespace std;

Vector::Vector(Point *start, Point *end) : start(start), end(end) {}

Vector *Vector::Add(Vector *other) const {
        Point *result_start = start->Add(other->start);
        Point *result_end = end->Add(other->end);
        Vector *result = new Vector(result_start, result_end);
        return result;
}

string Vector::ToString() const {
        return start->ToString() + "-->" + end->ToString();
}

