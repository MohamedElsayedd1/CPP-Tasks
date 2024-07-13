#include <iostream>
#include <vector>
using namespace std;

class Account
{
public:
    virtual void withdraw(void)
    {
        cout << "Account::withdraw()\n";
    }
};

class Savings : public Account
{
public:
    void withdraw(void) override
    {
        cout << "Savings::withdraw()\n";
    }
};

class Checking : public Account
{
public:
    void withdraw(void) override
    {
        cout << "Checking::withdraw()\n";
    }
};

class Trust : public Account
{
public:
    void withdraw(void) override
    {
        cout << "Trust::withdraw()\n";
    }
};

void do_withdraw(Account &acc);

int main()
{
    cout << "===== Base class Reference 1 ====\n";
    Account a;
    Account &ref = a;
    ref.withdraw(); // calls Account::withdraw() -> dynamic binding

    Trust t;
    Account &ref1 = t;
    ref1.withdraw(); // calls Trust::withdraw() -> dynamic binding

    cout << "===== Base class Reference 1 ====\n";

    Account a1;
    Savings a2;
    Checking a3;
    Trust a4;

    do_withdraw(a1); // Account::withdraw()
    do_withdraw(a2); // Savings::withdraw()
    do_withdraw(a3); // Checking::withdraw()
    do_withdraw(a4); // Trust::withdraw()

    return 0;
}

void do_withdraw(Account &acc)
{
    acc.withdraw();
}