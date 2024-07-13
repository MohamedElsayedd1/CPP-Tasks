#include <iostream>
using namespace std;

class Base{
private : 
    int value;
public : 
    Base() : value(0){ cout << "Base no-args constructor\n";}
    Base(int x) : value(x){ cout << "Base 1 arg constructor\n";}
    ~Base(){ cout << "Base destructor\n";}
};

class Derived : public Base{
private : 
    int doubled_value;
public : 
    Derived() : Base{},doubled_value(0){ cout << "Derived no-args constructor\n";}
    Derived(int x) : Base{x} ,doubled_value(x*2){ cout << "Derived 1 arg constructor\n";}
    ~Derived(){ cout << "Derived destructor\n";}
};

int main()
{
    Base base;
    cout << "=====================\n";
    Base base2(10);
    cout << "=====================\n";
    Derived D1;
    cout << "=====================\n";
    Derived D2(20); // calls Base overloaded constructor -> Base(x).
    cout << "=====================\n";
    return 0;
}