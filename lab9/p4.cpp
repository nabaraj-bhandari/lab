#include <iostream>
#include <stdexcept>
using namespace std;

int divide(int a, int b)
{
    if (b == 0)
        throw runtime_error("Division by zero");
    return a / b;
}

void accessArray(int index)
{
    int arr[3] = {10, 20, 30};
    if (index < 0 || index >= 3)
        throw out_of_range("Index out of bounds");
    cout << "Value at index " << index << ": " << arr[index] << endl;
}

int main()
{
    // Multiple catch demonstration
    try
    {
        cout << "Division result: " << divide(10, 0) << endl;
    }
    catch (const runtime_error &e)
    {
        cout << "Caught runtime_error: " << e.what() << endl;
    }
    catch (...)
    {
        cout << "Caught unknown exception in division.\n";
    }

    // Re-throwing demonstration
    try
    {
        try
        {
            accessArray(5);
        }
        catch (const out_of_range &e)
        {
            cout << "Caught out_of_range in inner block: " << e.what() << endl;
            throw; // Re-throw to outer handler
        }
    }
    catch (const exception &e)
    {
        cout << "Re-thrown and caught in outer block: " << e.what() << endl;
    }

    // Catch-all demonstration
    try
    {
        throw 404; // throw an int (unexpected type)
    }
    catch (const char *e)
    {
        cout << "Caught string exception: " << e << endl;
    }
    catch (...)
    {
        cout << "Caught unknown exception (catch-all)\n";
    }

    return 0;
}
