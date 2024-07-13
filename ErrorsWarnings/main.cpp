#include <iostream>
using namespace std;

int main()
{
    // Compile time error
    cout << "hello";

    // Run time error
    int x =7/0;
    cout << "x : " << x;
    return 0;
}