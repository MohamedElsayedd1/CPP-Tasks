#include <iostream>
using namespace std;

int main()
{
    int n1, n2;
    cout << "Enter number 1 & number 2 : ";
    cin >> n1 >> n2;
    while (n1 != n2)
    {
        if (n1 > n2)
        {
            n1 = n1 - n2;
        }
        else
        {
            n2 = n2 - n1;
        }
    }
    cout << "Greatest common factor : " << n1;
    return 0;
}