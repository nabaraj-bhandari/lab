// Conversion from meter system to feet system
// User Defined to Basic

#include <iostream>
using namespace std;

class Meter
{
private:
    float meters;

public:
    Meter(float m = 0) : meters(m) {}
    operator float() const
    {
        return meters * 3.28084;
    }
    void display()
    {
        cout << meters << " meters\n";
    }
};

int main()
{
    Meter m = 4.56;
    float ft = m;
    cout << "Given meter system: ";
    m.display();
    cout << "Equivalent feet system: " << ft << " feet\n";
}