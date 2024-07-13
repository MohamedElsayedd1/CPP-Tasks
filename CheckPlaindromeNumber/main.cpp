#include <iostream>
using namespace std;

int main()
{
    int n, _n, r, rev = 0;
    cout << "Enter a number : ";
    cin >> n;
    _n = n;
    while (n != 0)
    {
        rev *= 10;
        r = n % 10;
        n = n / 10;
        rev += r;
    }
    if (_n == rev)
    {
        cout << _n << " Number is plaindrome.";
    }
    else
    {
        cout << _n << " Number is not plaindrome.";
    }
    return 0;
}