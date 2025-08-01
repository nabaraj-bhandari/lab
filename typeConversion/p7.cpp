// Conversion from meter/cm to feet/inches
// Conversion in Source Object

#include <iostream>
using namespace std;

class FeetSystem
{
private:
    int feet;
    float inches;

public:
    FeetSystem(int ft = 0, float in = 0) : feet(ft), inches(in) {}
    void display()
    {
        cout << feet << "feet " << inches << " inches" << endl;
    }
};

class MeterSystem
{
private:
    int meters;
    float centimeters;

public:
    MeterSystem(int m = 0, float cm = 0) : meters(m), centimeters(cm) {}

    operator FeetSystem()
    {
        float totalCm = meters * 100 + centimeters;
        float totalIn = totalCm / 2.54;
        int feet = totalIn / 12;
        float inches = totalIn - feet * 12;
        return FeetSystem(feet, inches);
    }

    void
    display()
    {
        cout << meters << "m " << centimeters << "cm" << endl;
    }
};

int main()
{
    MeterSystem ms(2, 45.6);
    FeetSystem fs;
    fs = ms;
    cout << "Given meter system: ";
    ms.display();
    cout << "Equivalent feet system: ";
    fs.display();
    return 0;
}