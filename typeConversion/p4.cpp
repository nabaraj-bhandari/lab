// Conversion from the 24-hour clock to 12 hour
// Conversion in Source Object

#include <iostream>
#include <string>
using namespace std;

class Time12
{
private:
    int hours;
    int minutes;
    float seconds;
    string meridiem;

public:
    Time12(int h, int m, float s, string md) : hours(h), minutes(m), seconds(s), meridiem(md) {}
    void display()
    {
        cout << hours << ":" << minutes << ":" << seconds << meridiem << endl;
    }
};

class Time24
{
private:
    int hours;
    int minutes;
    float seconds;

public:
    Time24(int h, int m, float s) : hours(h), minutes(m), seconds(s) {}
    operator Time12()
    {
        int m = minutes;
        float s = seconds;
        int h = (hours / 12 == 0) ? 12 : (hours % 12);
        string md = (hours < 12) ? "AM" : "PM";
        return Time12(h, m, s, md);
    }
    void display()
    {
        cout << hours << ":" << minutes << ":" << seconds << endl;
    }
};

int main()
{
    Time24 t24(13, 45, 37.8);
    Time12 t12 = t24;
    cout << "Given time in 24-hour clock: ";
    t24.display();
    cout << "Equivalent time in 12-hour clock: ";
    t12.display();
    return 0;
}