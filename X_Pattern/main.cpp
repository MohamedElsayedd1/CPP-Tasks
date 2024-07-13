// Online C++ compiler to run C++ program online
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    // Write C++ code here
    unsigned int x;
    cin >> x;
    int k = x - 1;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
        {
            if (j == i && k == j)
            {
                k--;
                cout << "X";
            }
            else if (i == j)
            {
                cout << "\\";
            }
            else if (k == j)
            {
                cout << "/";
                k--;
            }
            else
            {
                cout << "*";
            }
        }
        cout << endl;
    }

    return 0;
}