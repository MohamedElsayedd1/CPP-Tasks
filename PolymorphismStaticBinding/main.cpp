#include <iostream>
#include <memory>
using namespace std;

class Base{
public: 
    void say_hello() const{
        cout << "Hi - i'm Base class.\n";
    }
};

class Derived : public Base{
public: 
    void say_hello() const{
        cout << "Hi - i'm Derived class.\n";
    }
};

void greeting(const Base &acc){
    cout << "Greeting : ";
    acc.say_hello();
}

int main()
{
    Base b;
    b.say_hello();

    Derived d;
    d.say_hello();

    greeting(b);
    greeting(d); // here comes the problem, it calls Base::say_hello() instead of Derived::say_hello().

    Base *ptr = new Derived(); // ptr holds address of a Base object, and Derived IS A Base
    ptr->say_hello(); // here comes the problem, it calls Base::say_hello() instead of Derived::say_hello().

    unique_ptr<Base> ptr1 = make_unique<Derived>();
    ptr1->say_hello(); // here comes the problem, it calls Base::say_hello() instead of Derived::say_hello().

    return 0;
}