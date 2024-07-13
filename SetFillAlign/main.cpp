#include <iostream>
#include <iomanip>
using namespace std;

void ruler(){
    cout << "\n12345678901234567890123456789012345678901234567890\n";
}

int main()
{
    double num1{1234}, num2{1234.567};
    string hello {"Hello"};

    cout << "\n-------------Defaults--------------\n";
    ruler();
    cout << num1 << num2 << hello << endl;

    cout << "\n-------------Defaults one per line--------------\n";
    ruler();
    cout << num1 << endl;
    cout << num2 << endl;
    cout << hello << endl;

    cout << "\n-------------Set width 10 for num1--------------\n";
    ruler();
    cout << setw(10) << num1 << num2 << hello << endl;; // right justified by default for num1 only

    cout << "\n-------------Set width 10 for num1 and num2--------------\n";
    ruler();
    cout << setw(10) << num1 << setw(10) << num2 << hello << endl; // right justified by default for num1 and num2

    cout << "\n-------------Set width 10 for num1, num2 and hello--------------\n";
    ruler();
    cout << setw(10) << num1 << setw(10) << num2  << setw(10)<< hello <<endl; // right justified by default for num1, num2 and hello

    cout << "\n-------------Set width 10 for num1, num2 and hello to the left--------------\n";
    ruler();
    cout << setw(10) << left << num1 
    << setw(10) << left << num2  
    << setw(10) << left << hello << endl; // left justified for num1, num2 and hello

    cout << "\n-------------Set width 10 for num1, num2 and hello to the left + using setfill--------------\n";
    ruler();
    cout << setw(10) << left  << setfill('+') << num1 
    << setw(10) << left << setfill('-')  << num2  
    << setw(10) << left << setfill('*') << hello << endl; // left justified for num1, num2 and hello


    cout << endl;
    return 0;
}