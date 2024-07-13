#include <iostream>
#include "Account.cpp"
#include "Saving_Account.cpp"
using namespace std;

int main()
{
    cout << "================== Account ================\n";
    Account a1{1000};
    cout << a1 << endl;
    
    a1.deposit(1000);
    cout << a1 << endl;

    a1.withdraw(1500);
    cout << a1 << endl;

    a1.withdraw(2000);
    cout << a1 << endl;

    cout << "================== Saving Account ================\n";
    Saving_Account s1{1000, 0.05};
    cout << s1 << endl;

    s1.deposit(1000);
    cout << s1 << endl;

    s1.withdraw(2500);
    cout << s1 << endl;

    s1.withdraw(500);
    cout << s1 << endl;

    return 0;
}