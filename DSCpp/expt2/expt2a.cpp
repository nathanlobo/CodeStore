#include <iostream>
using namespace std;
class Box {
private:
    float length;
    float breadth;
    float height;
public:
    void setData(float l, float b, float h){
        length = l;
        breadth = b;
        height = h;
    }
    friend void calculateVolume(const Box& b);
};
void calculateVolume(const Box& b) {
    cout << "Volume = " << b.length * b.breadth * b.height << endl;
}
int main() {
    float l, b, h;
    cout << "Enter length, breadth and height of the box: ";
    cin >> l >> b >> h;
    Box box;
    box.setData(l, b, h);
    calculateVolume(box);
    return 0;
}
