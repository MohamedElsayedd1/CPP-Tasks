#include <iostream>
#include <vector>
using namespace std;

class Account
{
public:
    void withdraw(void)
    {
        cout << "Account::withdraw()\n";
    }
};

class Savings : public Account
{
public:
    void withdraw(void)
    {
        cout << "Savings::withdraw()\n";
    }
};

class Checking : public Account
{
public:
    void withdraw(void)
    {
        cout << "Checking::withdraw()\n";
    }
};

class Trust : public Account
{
public:
    void withdraw(void)
    {
        cout << "Trust::withdraw()\n";
    }
};

int main()
{
    cout << "===== Base class pointers ====\n";
    Account *a1 = new Account();
    Account *a2 = new Savings();
    Account *a3 = new Checking();
    Account *a4 = new Trust();

    // no dynamic polymorphism yet
    a1->withdraw(); // Account::withdraw()
    a2->withdraw(); // Account::withdraw()
    a3->withdraw(); // Account::withdraw()
    a4->withdraw(); // Account::withdraw()

    cout << "====== Array ======\n";

    Account *array[]{a1, a2, a3, a4}; // array of pointers to objects of type Account

    for (int i = 0; i < 4; i++)
        array[i]->withdraw();

    cout << "====== Array ======\n";

    array[0] = a4;

    for (int i = 0; i < 4; i++)
        array[i]->withdraw();

    cout << "======= Vector =======\n";

    vector<Account *> accounts{a1, a2, a3, a4}; // vector of pointers to an object type 'Account', vector<Account> *accounts is pointer to vector holding objects of type 'Account'

    for (auto x : accounts)
        x->withdraw();

    // deleting pointers
    delete a1;
    delete a2;
    delete a3;
    delete a4;

    return 0;
}