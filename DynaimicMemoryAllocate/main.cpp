#include <iostream>
using namespace std;

int main()
{
    cout << "Enter number of elements : ";
    int n;
    cin >> n;
    int *p = new int[n];
    cout << "Enter Elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    cout << "Elements : ";
    for (int i = 0; i < n; i++)
    {
        cout << p[i] << endl;
    }
    delete[] p;
}