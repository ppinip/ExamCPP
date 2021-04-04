#include <string>
#include "point.h"

#ifndef VECTOR_H
#define VECTOR_H

class Vector {
private:
    Point *start;
    Point *end; 
public:
    Vector(Point *start, Point *end);

    Vector *Add(Vector *other) const ;
    std::string ToString() const;
};

#endif
