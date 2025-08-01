// Conversion from meter/cm to feet/inches.
// Conversion in Destination Object

#include <iostream>
using namespace std;

class MeterSystem
{
private:
    int meters;
    float centimeters;

public:
    MeterSystem(int m = 0, float cm = 0) : meters(m), centimeters(cm) {}
    int return_meters() { return meters; }
    float return_centimeters() { return centimeters; }
    void display()
    {
        cout << meters << "m " << centimeters << "cm" << endl;
    }
};

class FeetSystem
{
private:
    int feet;
    float inches;

public:
    FeetSystem(int ft = 0, float in = 0) : feet(ft), inches(in) {}
    FeetSystem(MeterSystem ms)
    {
        float totalCm = ms.return_meters() * 100 + ms.return_centimeters();
        float totalIn = totalCm / 2.54;
        feet = totalIn / 12;
        inches = totalIn - feet * 12;
    }
    void display()
    {
        cout << feet << "feet " << inches << " inches" << endl;
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