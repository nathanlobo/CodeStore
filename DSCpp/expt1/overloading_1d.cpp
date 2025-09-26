// 25LEC07 - Nathan Lobo
// Aim:- Develop a C++ program using function overloading to calculate the average of 
//       1. Two integers numbers 
//       2. Three Floating Point numbers
//      Use the function name average and overload with appropriate parameter
#include <iostream>
using namespace std;
// Class to calculate averages using function overloading
class Calculator {
public:
    // Calculate average of two integers
    float average(int a, int b) {
        return (a + b) / 2.0;
    }
    // Calculate average of three floating point numbers
    float average(float a, float b, float c) {
        return (a + b + c) / 3.0f;
    }
};
int main() {
    Calculator calc; // Create Calculator object
    int x1, x2;
    float y1, y2, y3;
    // Input and average calculation for two integers
    cout << "Enter two integers: ";
    cin >> x1 >> x2;
    cout << "Average of two integers: " << calc.average(x1, x2) << endl;
    // Input and average calculation for three floats
    cout << "Enter three floating point numbers: ";
    cin >> y1 >> y2 >> y3;
    cout << "Average of three floats: " << calc.average(y1, y2, y3) << endl;
    return 0;
}