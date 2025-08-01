// Conversion from the pound/ounce to Kg/gm
// Conversion in Destination Object

#include <iostream>
using namespace std;

class AvoirdupoisSystem
{
private:
    int pounds;
    float ounces;

public:
    AvoirdupoisSystem(float lb = 0, float oz = 0) : pounds(lb), ounces(oz) {}
    int getPounds() const { return pounds; }
    float getOunces() const { return ounces; }
    void display()
    {
        cout << pounds << "lb " << ounces << " oz\n";
    }
};

class MetricSystem
{
private:
    int kilograms;
    float grams;

public:
    MetricSystem(int kg = 0, float gm = 0) : kilograms(kg), grams(gm) {}
    MetricSystem(const AvoirdupoisSystem &as)
    {
        float totalOunces = (as.getPounds() * 16.f) + as.getOunces();
        float totalGrams = totalOunces * 28.3495;
        kilograms = totalGrams / 1000;
        grams = totalGrams - (1000 * kilograms);
    }
    void display()
    {
        cout << kilograms << "kg " << grams << " gm\n";
    }
};

int main()
{
    AvoirdupoisSystem as(23, 12.56);
    MetricSystem ms = as;
    cout << "Given weight in Avoirdupois System: ";
    as.display();
    cout << "Equivalent weight in Metric System: ";
    ms.display();
    return 0;
}