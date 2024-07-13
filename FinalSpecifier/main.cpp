#include <iostream>
using namespace std;

class Base
{
public:
    virtual void do_something();
};

class Derived : public Base
{
public:
    void do_something() override final; // function is overriden, but can't override it again in derived classed for class Derived
};

class Account final
{
};

// class Savings : public Account{  // can't derive a class from Account, because it's final specified.

// };

int main()
{

    return 0;
}