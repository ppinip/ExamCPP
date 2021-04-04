#include <string>

class Point {
private:
    double x;
    double y;
public:
    Point() : x(0), y(0) {}
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
    std::string ToString() const {
        return "(" + std::to_string(x) + "," + std::to_string(y) + ")";
    }
};