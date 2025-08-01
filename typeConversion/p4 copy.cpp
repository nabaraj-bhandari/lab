// Conversion from the 24-hour clock to 12 hour
// Conversion in Destination Object

#include <iostream>
#include <string>
using namespace std;

class Time24
{
private:
    int hours;
    int minutes;
    float seconds;

public:
    Time24(int h, int m, float s) : hours(h), minutes(m), seconds(s) {}
    int getHours() const { return hours; }
    int getMinutes() const { return minutes; }
    float getSeconds() const { return seconds; }
    void display()
    {
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }
};

class Time12
{
private:
    int hours;
    int minutes;
    float seconds;
    string meridiem;

public:
    Time12(int h, int m, float s, string md) : hours(h), minutes(m), seconds(s), meridiem(md) {}
    Time12(const Time24 &t24)
    {
        int h = t24.getHours();
        meridiem = (h < 12) ? "AM" : "PM";
        hours = (h % 12 == 0) ? 12 : (h % 12);
        minutes = t24.getMinutes();
        seconds = t24.getSeconds();
    }
    void display()
    {
        cout << hours << ":" << minutes << ":" << seconds << meridiem << endl;
    }
};

int main()
{

    Time24 t24(7, 45, 37.8);
    Time12 t12 = t24;
    cout << "Given time in 24-hour clock: ";
    t24.display();
    cout << "Equivalent time in 12-hour clock: ";
    t12.display();
    return 0;
}