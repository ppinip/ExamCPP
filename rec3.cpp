#include <iostream>
using namespace std;


class Rectangle {

private:
    double width;
    double lenght;

public:

    Rectangle(double w, double l) : width(w), lenght(l) {
        if (w <= 0) width = 1;
        if (l <= 0) lenght = 1;
    }

    double Area() const { 
        return width * lenght;
    }

    double Perimeter() const { 
        return 2 * (width + lenght);
    }
    
    void ChangeSize(double d) { 
        width += d;
        lenght += d;
    }

    void ChangeSize(double dw, double dl) { 
        width += dw;
        lenght += dl;
    }

    //Getter
    double GetWidth() const{
        return width;
    }

    double GetLength() const {
        return lenght;
    }
    
    //Setter
    void SetWidth(double w) {
        if (w > 0) {
            width = w;
        }
    }

    void SetLength(double l){
        if (l > 0) {
            lenght = l;
        }
    }


};

int main() { 
    
    Rectangle r1(5,5);

    // r1.width = -50; privateป้องกันเคสแบบนี้

    cout << "r1: " << r1.GetWidth() << " " << r1.GetLength() << endl;
    
    
}   
