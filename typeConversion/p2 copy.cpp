// Conversion from Cartesian coordinate to the polar coordinate system.
// Conversion in Destination Object

#include <iostream>
#include <cmath>
using namespace std;

class Cartesian
{
private:
    float x;
    float y;

public:
    Cartesian(float a = 0, float b = 0) : x(a), y(b) {}
    float getX() { return x; }
    float getY() { return y; }
    void display()
    {
        cout << "(" << x << "," << y << ")" << endl;
    }
};

class Polar
{
private:
    float radius;
    float angle;

public:
    Polar(float r = 0, float a = 0) : radius(r), angle(a) {}
    Polar(Cartesian c)
    {
        radius = sqrt((c.getX() * c.getX()) + (c.getY() * c.getY()));
        angle = atan2(c.getY(), c.getX()) * 180 / M_PI;
    }
    void display()
    {
        cout << "(" << radius << "," << angle << ")" << endl;
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