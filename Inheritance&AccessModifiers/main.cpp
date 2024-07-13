#include <iostream>
using namespace std;

class Base
{
public:
    int a;

protected:
    int b;

private:
    int c;
};

class Public_Derived : public Base
{
public:
    void access_base_members()
    {
        a = 100; // a will be accessibale because it's public ,and a will be public for derived classes
        b = 400; // b will be accessible because it's protected ,and b will be protected for other derived classes
        // c= 19; // c won't be accessible because it's private ,and c is still not accessible by other derived classes
    }
};

class Protected_Derived : protected Base
{
public:
    void access_base_members()
    {
        a = 100; // a will be accessibale because it's public ,and a will be PROTECTED for derived classes
        b = 400; // b will be accessible because it's protected ,and b will be PROTECTED for other derived classes
        // c = 19; // c won't be accessible because it's private ,and c is still not accessible by other derived classes
    }
};

class Private_Derived : private Base
{
public:
    void access_base_members()
    {
        a = 100; // a will be accessibale because it's public ,and a will be PRIVATE for derived classes
        b = 400; // b will be accessible because it's protected ,and b will be PRIVATE for other derived classes
        // c = 19; // c won't be accessible because it's private ,and c is still not accessible by other derived classes
    }
};

int main()
{
    cout << "=========Base member access from base object==========\n";
    Base base_obj;
    base_obj.a = 100; // ok
    // base.b = 10; // Not accessible by object because it's PROTECTED, only accessed by the class itself or a friend
    // base.c = 500; // Not accessible by object because it's PRIVATE, only accessed by the class itself or a friend

    cout << "=========Base member access from public inherited object==========\n";
    Public_Derived pud_obj;
    pud_obj.a = 500; // ok
    // pd_obj.b = 90; // Not accessible by object because it's PROTECTED, only accessed by the class itself or a friend
    // pd_obj.c = 88; // Not accessible by object because it's PRIVATE, only accessed by the class itself or a friend

    cout << "=========Base member access from protected inherited object==========\n";
    Protected_Derived prd_obj;
    // prd_obj.a = 500; // Not accessible because a became PROTECTED because of protected inheritance
    // pd_obj.b = 90; // Not accessible by object because it's PROTECTED, only accessed by the class itself or a friend
    // pd_obj.c = 88; // Not accessible by object because it's PRIVATE, only accessed by the class itself or a friend

    cout << "=========Base member access from protected inherited object==========\n";
    Private_Derived pvd_obj;
    // prd_obj.a = 500; // Not accessible because a became PRIVATE because of protected inheritance
    // pd_obj.b = 90; // Not accessible by object because b became PRIVATE because of protected inheritance
    // pd_obj.c = 88; // Not accessible by object because it's PRIVATE, only accessed by the class itself or a friend

    return 0;
}