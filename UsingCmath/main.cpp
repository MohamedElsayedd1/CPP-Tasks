#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    double num, power;
    cout << "Enter a number : ";
    cin >> num;

    cout << "The sqrt of " << num << " : " << sqrt(num) << endl;
    cout << "The cubed root of " << num << " : " << cbrt(num) << endl;

    cout << "sin(" << num << ") : " << sin(num) << endl;
    cout << "cos(" << num << ") : " << cos(num) << endl;

    cout << "the ceil of " << num << " : " << ceil(num) << endl;
    cout << "the floor of " << num << " : " << floor(num) << endl;
    cout << "the round of " << num << " : " << round(num) << endl;

    cout << "Enter a power to raise : ";
    cin >> power;
    cout << num << " is raised to power " << power << ": " << pow(num, power) << endl;
}