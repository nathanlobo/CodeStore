#include <iostream>
using namespace std;
class ShapeArea {
public:
    int area(int side) {
        return side * side;
    }
    int area(int length, int breadth) {
        return length * breadth;
    }
    float area(float radius) {
        return 3.14159 * radius * radius;
    }
};
int main() {
    ShapeArea s;
    int sq, l, b;
    float r;
    cout << "Enter side of square: ";
    cin >> sq;
    cout << "Area of square: " << s.area(sq) << endl;
    cout << "Enter length and breadth of rectangle: ";
    cin >> l >> b;
    cout << "Area of rectangle: " << s.area(l, b) << endl;
    cout << "Enter radius of circle: ";
    cin >> r;
    cout << "Area of circle: " << s.area(r) << endl;
    return 0;
}