#include <iostream>
using namespace std;

int main()
{
    int A[2][3];
    cout << "Enter 2x3 matrix : ";
    for (auto &x : A)
    {
        for (auto &y : x)
        {
            cin >> y;
        }
        cout << endl;
    }
    cout << "Matrix : ";
    for (auto &x : A)
    {
        for (auto &y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
}