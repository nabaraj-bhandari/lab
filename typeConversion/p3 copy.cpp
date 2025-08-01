// Conversion from meter system to feet system
// Basic to User Defined

#include <iostream>
using namespace std;

class Feet
{
private:
    float feet;

public:
    Feet()
    {
        feet = 0;
    }
    Feet(float l)
    {
        feet = l * 3.28084;
    }
    void display()
    {
        cout << feet << " feet\n";
    }
};

int main()
{
    float m = 4.56;
    Feet f = m;
    cout << "Given meter system: " << m << " meters\n";
    cout << "Equivalent feet system: ";
    f.display();
    return 0;
}