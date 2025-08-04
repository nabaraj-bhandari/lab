// Conversion from Kg to pound system
// User defined to Basic

#include <iostream>
using namespace std;

class KG
{
private:
    float kilograms;

public:
    KG(float kg = 0) : kilograms(kg) {}

    operator float()
    {
        return kilograms * 2.20462f;
    }
    void display()
    {
        cout << "Given weight in kg: " << kilograms << " kg\n";
    }
};

int main()
{
    KG kg = 60.67;
    float p;
    p = kg;
    kg.display();

    cout << "Equivalent weight in Pound: " << p << " lbs\n";
    return 0;
}