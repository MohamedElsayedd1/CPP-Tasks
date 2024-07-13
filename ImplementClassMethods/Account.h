#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <iostream>
#include <vector>

using namespace std;

class Account
{
private:
    // attributes
    string name{"Account"};
    double balance{0.0};

    // methods
public:
    void set_balance(double val)
    {
        balance = val;
    }
    double get_balance()
    {
        return balance;
    }

    void set_name(string n);
    string get_name();

    void is_deposited(double deposit);
    void is_withdrawed(double withdraw);
};

#endif // !_ACCOUNT_H_
