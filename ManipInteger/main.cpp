#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int num{255};
    cout << dec << num << endl;
    cout << hex << num << endl;
    cout << oct << num << endl;
    
    cout << "========================\n";

    cout << showbase;
    cout << dec << num << endl;
    cout << hex << num << endl;
    cout << oct << num << endl;
    
    cout << "========================\n";

    cout << uppercase;
    cout << dec << num << endl;
    cout << hex << num << endl;
    cout << oct << num << endl;

    cout << "========================\n";
    
    cout << showpos;
    cout << dec << num << endl;

    cout << "========================\n";

    cout.setf(ios::showbase);
    cout.setf(ios::showpos);
    cout.setf(ios::uppercase);

    cout << resetiosflags(ios::showbase);
    cout << resetiosflags(ios::showpos);
    cout << resetiosflags(ios::uppercase);
    
    int x;
    cout << "Enter a number : ";
    cin >> x;
    
    cout << "Deciaml : " << dec << x << endl;
    cout << "Hexa : " << hex << x << endl;
    cout << "Hexa : " << showbase << uppercase << hex << x << endl;
    cout << "hexa : " << x << endl;
    cout << "hexa : " << nouppercase << x << endl;

    cout << "oct : " << oct << x << endl;
    cout << "oct : " << oct << uppercase << x << endl;
    return 0;
}