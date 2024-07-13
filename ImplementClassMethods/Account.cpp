#include "Account.h"

void Account::is_deposited(double deposit)
{
    cout << "==========================\n";
    cout << name << " account : \n";
    cout << "In balance : " << balance << endl;
    balance += deposit;
    cout << "Deposited money : " << deposit << endl;
    cout << "Total money after deposit : " << balance << endl;
    cout << "==========================\n";
}

void Account::is_withdrawed(double withdraw)
{
    cout << "==========================\n";
    cout << name << " account : \n";
    cout << "In balance : " << balance << endl;
    if (withdraw <= balance)
    {
        balance -= withdraw;
        cout << "withdrawn money : " << withdraw << endl;
        cout << "Total money after withdraw : " << balance << endl;
    }
    else
    {
        cout << "Can't withdraw, no enough money.\n";
    }
    cout << "==========================\n";
}

void Account::set_name(string n)
{
    name = n;
}

string Account::get_name()
{
    return name;
}