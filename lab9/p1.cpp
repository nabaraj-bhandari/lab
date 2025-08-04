#include <iostream>
using namespace std;

template <class T>
T sum(T arr[], int size)
{
    T total = 0;
    for (int i = 0; i < size; ++i)
        total += arr[i];
    return total;
}

int main()
{
    int a[] = {1, 2, 3, 4};
    double b[] = {1.1, 2.2, 3.3};
    float c[] = {1.5f, 2.5f};

    cout << "Sum of int array: " << sum(a, 4) << endl;
    cout << "Sum of double array: " << sum(b, 3) << endl;
    cout << "Sum of float array: " << sum(c, 2) << endl;
}
