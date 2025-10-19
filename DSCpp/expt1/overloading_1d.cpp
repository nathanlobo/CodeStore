#include <iostream>
using namespace std;
class Calculator {
public:
    float average(int a, int b) {
        return (a + b) / 2.0;
    }
    float average(float a, float b, float c) {
        return (a + b + c) / 3.0f;
    }
};
int main() {
    Calculator calc;
    int x1, x2;
    float y1, y2, y3;
    cout << "Enter two integers:\n";
    cin >> x1 >> x2;
    cout << "Average of two integers: " << calc.average(x1, x2) << endl;
    cout << "Enter three floating point numbers:\n";
    cin >> y1 >> y2 >> y3;
    cout << "Average of three floats: " << calc.average(y1, y2, y3) << endl;
    return 0;
}