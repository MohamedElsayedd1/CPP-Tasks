#include <iostream>
using namespace std;

int main()
{
    int n, rev = 0, r;
    cout << "Enter number : ";
    cin >> n;
    while (n != 0)
    {
        rev *= 10;
        r = n % 10; // 3
        n = n / 10; /// 15
        rev += r;   // 3
    }
    cout << "Reversed Number : " << rev;
    return 0;
}