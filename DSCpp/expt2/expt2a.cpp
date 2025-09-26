// 25LEC07 - Nathan Lobo
// Aim:- To create a class box that contains private data members for length, breadth and height, 
//       use a friend function to calculate volume
#include <iostream>
using namespace std;
// Class representing a box with length, breadth, and height
class Box {
private:
    float length;   // Length of the box
    float breadth;  // Breadth of the box
    float height;   // Height of the box
public:
    // Function to set the dimensions of the box
    void setData(float l, float b, float h){
        length = l;
        breadth = b;
        height = h;
    }
    // Friend function declaration to calculate volume
    friend void calculateVolume(const Box& b);
};
// Friend function to calculate and print the volume of the box
void calculateVolume(const Box& b) {
    cout << "Volume = " << b.length * b.breadth * b.height << endl;
}
int main() {
    float l, b, h;
    // Prompt user for box dimensions
    cout << "Enter length, breadth and height of the box: ";
    cin >> l >> b >> h;
    Box box; // Create a Box object
    box.setData(l, b, h); // Set the dimensions
    calculateVolume(box); // Calculate and display the volume
    return 0;
}