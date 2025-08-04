#include <iostream>
#include <typeinfo>
using namespace std;

class Vehicle
{
public:
    virtual void info() const { cout << "Generic Vehicle\n"; }
    virtual ~Vehicle() {}
};

class Bus : public Vehicle
{
public:
    void info() const override { cout << "Bus\n"; }
};

class Car : public Vehicle
{
public:
    void info() const override { cout << "Car\n"; }
};

class Bike : public Vehicle
{
public:
    void info() const override { cout << "Bike\n"; }
};

int main()
{
    Vehicle *v[] = {new Bus(), new Car(), new Bike()};

    for (int i = 0; i < 3; i++)
    {
        cout << "Type: " << typeid(*v[i]).name() << "\n";
        v[i]->info();

        if (Bus *b = dynamic_cast<Bus *>(v[i]))
            cout << "Dynamic cast says this is a Bus\n";
        else if (Car *c = dynamic_cast<Car *>(v[i]))
            cout << "Dynamic cast says this is a Car\n";
        else if (Bike *bk = dynamic_cast<Bike *>(v[i]))
            cout << "Dynamic cast says this is a Bike\n";
    }

    for (int i = 0; i < n; i++)
        delete v[i];
}
