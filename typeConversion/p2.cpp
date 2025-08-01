// Conversion from Cartesian coordinate to the polar coordinate system.
// Conversion in Source Object

#include <iostream>
#include <cmath>
using namespace std;

class Polar
{
private:
    float radius;
    float angle;

public:
    Polar(float r = 0, float a = 0) : radius(r), angle(a) {}
    void display()
    {
        cout << "(" << radius << "," << angle << ")" << endl;
    }
};

class Cartesian
{
private:
    float x;
    float y;

public:
    Cartesian(float a = 0, float b = 0) : x(a), y(b) {}
    operator Polar()
    {
        float radius = sqrt((x * x) + (y * y));
        float angle = atan2(y, x) * 180 / M_PI;
        return Polar(radius, angle);
    }
    void display()
    {
        cout << "(" << x << "," << y << ")" << endl;
    }
};

int main()
{
    Cartesian c(4, 5);
    Polar p = c;
    cout << "Given Cartesian co-orindate: ";
    c.display();
    cout << "Equivalent Polar co-orindate: ";
    p.display();
    return 0;
}