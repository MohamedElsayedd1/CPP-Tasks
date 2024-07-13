#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double num1{123456789.987654321};
    double num2{1234.56789};
    double num3{1234};

    cout << "--------------Default--------------\n";
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;

    cout << "--------------Precision 3--------------\n";
    cout << setprecision(3); // only displaying 3 digits
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;

    cout << "--------------Precision 5--------------\n";
    cout << setprecision(5); // only displaying 3 digits
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;

    cout << "--------------Precision 9--------------\n";
    cout << setprecision(9); // only displaying 3 digits
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;

    cout << "--------------Precision 3 - fixed--------------\n";
    cout << setprecision(3) << fixed; // only displaying 3 digits after . symbol
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;

    cout << "--------------Precision 5 - fixed - scientific notation--------------\n";
    cout << setprecision(5) << fixed << scientific; // only displaying 5 digits after . symbol
    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;

    return 0;
}