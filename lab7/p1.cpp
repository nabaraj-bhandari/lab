#include <iostream>
#include <cmath>
using namespace std;

class Shape
{
public:
    virtual void display() const = 0;
    virtual double area() const = 0;
    virtual ~Shape() { cout << "Shape destroyed\n"; }
};

class Circle : public Shape
{
    double r;

public:
    Circle(double rad) : r(rad) {}
    void display() const override { cout << "Circle\n"; }
    double area() const override { return M_PI * r * r; }
    ~Circle() { cout << "Circle destroyed\n"; }
};

class Rectangle : public Shape
{
    double l, w;

public:
    Rectangle(double a, double b) : l(a), w(b) {}
    void display() const override { cout << "Rectangle\n"; }
    double area() const override { return l * w; }
    ~Rectangle() { cout << "Rectangle destroyed\n"; }
};

class Trapezoid : public Shape
{
    double a, b, h;

public:
    Trapezoid(double x, double y, double z) : a(x), b(y), h(z) {}
    void display() const override { cout << "Trapezoid\n"; }
    double area() const override { return (a + b) * h / 2; }
    ~Trapezoid() { cout << "Trapezoid destroyed\n"; }
};

int main()
{
    Shape *s[] = {new Circle(5), new Rectangle(4, 6), new Trapezoid(3, 5, 4)};
    int n = sizeof(s) / sizeof(s[0]);

    for (int i = 0; i < n; i++)
    {
        s[i]->display();
        cout << "Area: " << s[i]->area() << "\n";
        delete s[i];
    }
}
