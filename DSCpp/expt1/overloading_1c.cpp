// 25LEC07 - Nathan Lobo
// Aim:- To develop a C++ program using function overloading to calculate area of different shapes 
//       (square, rectangle, circle) use the function name area and overload it with appropriate parameter
#include <iostream>
using namespace std;
// Class to calculate area of different shapes using function overloading
class ShapeArea {
public:
    // Calculate area of a square
    int area(int side) {
        return side * side;
    }
    // Calculate area of a rectangle
    int area(int length, int breadth) {
        return length * breadth;
    }
    // Calculate area of a circle
    float area(float radius) {
        return 3.14159f * radius * radius;
    }
};
int main() {
    ShapeArea s; // Create ShapeArea object
    int sq, l, b;
    float r;
    // Input and area calculation for square
    cout << "Enter side of square: ";
    cin >> sq;
    cout << "Area of square: " << s.area(sq) << endl;
    // Input and area calculation for rectangle
    cout << "Enter length and breadth of rectangle: ";
    cin >> l >> b;
    cout << "Area of rectangle: " << s.area(l, b) << endl;
    // Input and area calculation for circle
    cout << "Enter radius of circle: ";
    cin >> r;
    cout << "Area of circle: " << s.area(r) << endl;
    return 0;
}