#include <iostream>
using namespace std;

int main()
{
    int n, n_, r, sum = 0;
    cout << "Enter number : ";
    cin >> n;
    n_ = n;
    while (n != 0)
    {
        r = n % 10;
        n = n / 10;
        sum += r * r * r;
    }
    if (sum == n_)
    {
        cout << n_ << " is armstrong number.\n";
    }
    else
    {
        cout << n_ << " is not armstrong number.\n";
    }
    return 0;
}