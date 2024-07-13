#include <iostream>
using namespace std;

int main()
{
    signed int arr[10];
    int p = 0, n = 0;
    cout << "Enter numbers : ";
    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
    }
    for (auto x : arr)
    {
        if (x >= 0)
        {
            p++;
        }
        else
        {
            n++;
        }
    }
    cout << "Positive Numbers : " << p << " numbers.\n";
    cout << "Negative Numbers : " << n << " numbers.\n";
    return 0;
}