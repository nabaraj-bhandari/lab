#include <iostream>
using namespace std;

template <class T>
class Queue
{
    T data[100];
    int front, rear;

public:
    Queue() : front(0), rear(0) {}
    void enqueue(T val)
    {
        data[rear++] = val;
    }
    T dequeue()
    {
        return data[front++];
    }
};

int main()
{
    Queue<int> q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    cout << "Dequeue int: " << q1.dequeue() << " " << q1.dequeue() << " " << q1.dequeue() << endl;

    Queue<float> q2;
    q2.enqueue(1.5f);
    q2.enqueue(2.5f);
    cout << "Dequeue float: " << q2.dequeue() << " " << q2.dequeue() << endl;

    Queue<char> q3;
    q3.enqueue('X');
    q3.enqueue('Y');
    cout << "Dequeue char: " << q3.dequeue() << " " << q3.dequeue() << endl;

    return 0;
}
