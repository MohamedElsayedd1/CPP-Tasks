#include <iostream>
using namespace std;

class Base
{
private:
    int value;

public:
    Base() : value{0} { cout << "Base default constructor\n"; }
    Base(int x) : value(x) { cout << "Base 1 arg constructor\n"; }
    Base(const Base &rhs) : value{rhs.value}
    {
        cout << "Base copy constructor\n";
    }
    Base &operator=(const Base &rhs)
    {
        if (this == &rhs)
            return *this;
        value = rhs.value;
        cout << "Base copy = operator\n";
        return *this;
    }
    ~Base() { cout << "Base destructor\n"; }
};

class Derived : public Base
{
private:
    int doubled_val;

public:
    Derived() : Base(), doubled_val{0} { cout << "Derived default constructor\n"; }
    Derived(int x) : Base(x), doubled_val{2 * x} { cout << "Derived 1 arg constructor\n"; }
    Derived(const Derived &rhs) : Base(rhs), doubled_val{rhs.doubled_val}
    {
        cout << "Derived copy constructor\n";
    }
    Derived &operator=(const Derived &rhs)
    {
        if (this == &rhs)
            return *this;
        Base::operator=(rhs);
        doubled_val = rhs.doubled_val;
        cout << "Derived copy = operator\n";
        return *this;
    }
    ~Derived() { cout << "Derived destrucor\n"; }
};

int main()
{
    Base b1{100}; // Base 1 arg constructor
    cout << "===================\n";
    Base b2{b1}; // Base copy constructor
    cout << "===================\n";
    b1 = b2; // Base copy = operator

    cout << "\n===================\n";

    Derived d1{500}; // Derived 1 arg constructor
    cout << "===================\n";
    Derived d2{d1}; // Derived copy constructor
    cout << "===================\n";
    d2 = d1; // Derived copy = operator
    cout << "===================\n";

    return 0;
}