#include <iostream>
using namespace std;

int main()
{
    int n;
    int sum;
    cout << "Sum of first natural number \n";
    cout << "Enter the number : ";
    cin >> n;
    sum = n * (n + 1) * 0.5;
    cout << "Sum : " << sum;

    return 0;
}