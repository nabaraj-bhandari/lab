// Conversion from the pound/ounce to Kg/gm
// Conversion in Source Object

#include <iostream>
using namespace std;

class MetricSystem
{
private:
    int kilograms;
    float grams;

public:
    MetricSystem(int kg = 0, float gm = 0) : kilograms(kg), grams(gm) {}
    void display()
    {
        cout << kilograms << "kg " << grams << " gm\n";
    }
};

class AvoirdupoisSystem
{
private:
    int pounds;
    float ounces;

public:
    AvoirdupoisSystem(float lb = 0, float oz = 0) : pounds(lb), ounces(oz) {}
    operator MetricSystem()
    {
        float totalOunces = pounds * 16 + ounces;
        float totalGrams = totalOunces * 28.3495;
        int kilograms = totalGrams / 1000;
        float grams = totalGrams - kilograms * 1000.f;
        return MetricSystem(kilograms, grams);
    }
    void display()
    {
        cout << pounds << "lb " << ounces << " oz\n";
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