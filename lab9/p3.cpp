#include <iostream>
using namespace std;

template <class T>
class Stack
{
    T st[3];
    int top;

public:
    Stack() : top(-1) {}
    class Overflow
    {
    };
    class Underflow
    {
    };

    void push(T val)
    {
        if (top == 2)
            throw Overflow();
        st[++top] = val;
    }
    T pop()
    {
        if (top == -1)
            throw Underflow();
        return st[top--];
    }
};

int main()
{
    Stack<int> s;
    try
    {
        s.push(1);
        s.push(2);
        s.push(3);
        s.push(4); // Overflow
    }
    catch (...)
    {
        cout << "Stack Overflow!\n";
    }

    try
    {
        cout << s.pop() << endl;
        cout << s.pop() << endl;
        cout << s.pop() << endl;
        cout << s.pop() << endl; // Underflow
    }
    catch (...)
    {
        cout << "Stack Underflow!\n";
    }
}
