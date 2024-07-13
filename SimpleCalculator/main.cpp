#include <iostream>
using namespace std;

int operation;

int main()
{
    int operation;
    float n1, n2;
    float res;
    cout << "1. Add\n";
    cout << "2. Sub\n";
    cout << "3. Multiply\n";
    cout << "4. Deivide\n";
    cout << "Select an operation : ";
    cin >> operation;
    cout << "Enter 2 numbers : ";
    cin >> n1 >> n2;
    switch (operation)
    {
    case 1:
        res = n1 + n2;
        break;
    case 2:
        res = n1 - n2;
        break;
    case 3:
        res = n1 * n2;
        break;
    case 4:
        res = n1 / n2;
        break;
    }
    cout << "Result : " << res;
    return 0;
}