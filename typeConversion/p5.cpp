// Conversion from liter to gallons
// User defined to Basic

#include <iostream>
using namespace std;

class Liter
{
private:
    float volume;

public:
    Liter(float v = 0) : volume(v) {}
    operator float()
    {
        return volume / 3.78541;
    }
    void display()
    {
        cout << volume << " liters\n";
    }
};

int main()
{
    Liter l = 3.45;
    float g = l;
    cout << "Given volume in litres: ";
    l.display();
    cout << "Equivalent volume in gallons: " << g << " gallons\n";
    return 0;
}