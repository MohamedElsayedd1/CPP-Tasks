#include <iostream>
using namespace std;

int main()
{
    int hour;
    cout << "Enter an hour : ";
    cin >> hour;
    if (hour >= 9 && hour <= 18)
    {
        cout << hour << " is working hour";
    }
    else
    {
        cout << hour << " is not working hour";
    }
    return 0;
}