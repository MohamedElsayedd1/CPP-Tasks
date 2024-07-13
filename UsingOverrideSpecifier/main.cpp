#include <iostream>
using namespace std;

class Base{
public : 
    virtual void say_hello() const{
        cout << "Base says hello.\n";
    }
    //virtual ~Base();
};

class Derived : public Base{
public : 
    void say_hello(){  // notice i forgot to put const
        cout << "Derived says hello.\n";
    }
};

int main()
{
    Base *p1 = new Base();
    p1->say_hello();  // calls Base::say_hello() -> Base says hello.

    Derived *p2 = new Derived();
    p2->say_hello(); // calls Derived::say_hello() -> Derived says hello.

    Base *p3 = new Derived(); // Expected to call Derived::say_hello() -> Derived says hello. since we are using virtual function
    // but Derived::say_hello() is not overriding because we forgot to put 'const'
    p3->say_hello(); // calls Base::say_hello() -> Base says hello.
    return 0;
}