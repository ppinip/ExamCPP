#include <string>

#ifndef POINT_H
#define POINT_H

class Point {
private:
    int x;
    int y;
public:
    Point();
    Point(int x, int y);

    Point *Add(Point *other) const;
    std::string ToString() const;
};

#endif