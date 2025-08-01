// Conversion from Kg to pound system
// Basic to User defined

#include <iostream>
using namespace std;

class Pound
{
private:
    float pounds;

public:
    Pound()
    {
        pounds = 0;
    }
    Pound(float kg)
    {
        pounds = 2.20462f * kg;
    }
    void display()
    {
        cout << "Equivalent weight in Pound: " << pounds << " lbs\n";
    }
};

int main()
{
    float kg = 60.67;
    Pound p;
    p = kg;
    cout << "Given weight in kg: " << kg << " kg\n";
    p.display();
    return 0;
}