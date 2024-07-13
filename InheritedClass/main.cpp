#include <iostream>
#include <string>
#include "Account.cpp"
#include "Saving_Account.cpp"

using namespace std;

int main()
{
    Account acc1{};
    acc1.deposit(200);
    acc1.withdraw(500);
    acc1.withdraw(50);

    cout << endl;

    Account *acc2 = new Account("khaled", 100);
    acc2->deposit(400);
    acc2->withdraw(130.5);
    delete acc2;

    cout << endl;

    cout << "=========Saving Account========\n";

    Saving_Account sav1{0.12};
    sav1.deposit(100);
    sav1.withdraw(50);

    cout << endl;

    Saving_Account *sav2 = new Saving_Account(0.11);
    sav2->deposit(654);
    sav2->withdraw(123);
    delete sav2;

    return 0;
}