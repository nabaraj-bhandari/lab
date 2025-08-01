// Conversion from liter to gallons
// Basic to User defined

#include <iostream>
using namespace std;
class Gallon
{
private:
    float volume;

public:
    Gallon()
    {
        volume = 0;
    }
    Gallon(float l)
    {
        volume = l / 3.78541;
    }
    void display()
    {
        cout << volume << " gallons" << endl;
    }
};

int main()
{
    float l = 3.45;
    Gallon g = l;
    cout << "Given volume in litres: " << l << " litres" << endl;
    cout << "Equivalent volume in gallons: ";
    g.display();
    return 0;
}